from flask import Flask, request, send_file, jsonify, render_template
import os
import subprocess
from werkzeug.utils import secure_filename

app = Flask(__name__)

# Configuration
UPLOAD_FOLDER = 'uploads'
OUTPUT_FOLDER = 'outputs'
os.makedirs(UPLOAD_FOLDER, exist_ok=True)
os.makedirs(OUTPUT_FOLDER, exist_ok=True)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
app.config['OUTPUT_FOLDER'] = OUTPUT_FOLDER

# Function to call your Huffman C++ executable
def rnhfm(input_file_path, output_file_path):
    try:
        result = subprocess.run(["./hw8", "-c", input_file_path, output_file_path], capture_output=True, text=True)
        if result.returncode != 0:
            print(f"Error: {result.stderr}")
            return False
        return True
    except Exception as e:
        print(f"Error running Huffman compress program: {e}")
        return False

def dehfm(input_file_path, output_file_path):
    try:
        result = subprocess.run(["./hw8", "-u", input_file_path, output_file_path], capture_output=True, text=True)
        if result.returncode != 0:
            print(f"Error: {result.stderr}")
            return False
        return True
    except Exception as e:
        print(f"Error running Huffman decompress program: {e}")
        return False

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/compress', methods=['POST'])
def upload_file():
    if 'file' not in request.files:
        return jsonify({"error": "No file part"}), 400
    
    file = request.files['file']
    if file.filename == '':
        return jsonify({"error": "No selected file"}), 400
    
    custom_filename = request.form.get('customFileName')
    if not custom_filename:
        return jsonify({"error": "No custom file name provided"}), 400
    
    filename = secure_filename(custom_filename)
    input_file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
    output_file_path = os.path.join(app.config['OUTPUT_FOLDER'], filename)
    
    file.save(input_file_path)
    
    if not rnhfm(input_file_path, output_file_path):
        return jsonify({"error": "Huffman compression failed"}), 500
    
    return jsonify({"message": "File uploaded and compressed successfully", "output_file": filename})

@app.route('/decompress', methods=['POST'])
def decompress_file():
    if 'file' not in request.files:
        return jsonify({"error": "No file part"}), 400
    
    file = request.files['file']
    if file.filename == '':
        return jsonify({"error": "No selected file"}), 400
    
    custom_filename = request.form.get('customFileName')
    if not custom_filename:
        return jsonify({"error": "No custom file name provided"}), 400
    
    filename = secure_filename(custom_filename)
    input_file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
    output_file_path = os.path.join(app.config['OUTPUT_FOLDER'], filename)
    
    file.save(input_file_path)
    
    if not dehfm(input_file_path, output_file_path):
        return jsonify({"error": "Huffman decompression failed"}), 500
    
    return jsonify({"message": "File uploaded and decompressed successfully", "output_file": filename})

@app.route('/download/<filename>', methods=['GET'])
def download_file(filename):
    filepath = os.path.join(app.config['OUTPUT_FOLDER'], filename)
    if os.path.exists(filepath):
        return send_file(filepath, as_attachment=True)
    else:
        return jsonify({"error": "File not found"}), 404

if __name__ == '__main__':
    app.run(debug=True)
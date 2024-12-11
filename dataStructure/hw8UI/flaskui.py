from flask import Flask, request, send_file, jsonify
import os
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
def run_huffman(input_file_path, output_file_path):
    try:
        # Replace 'huffman_executable' with the actual name of your compiled C++ Huffman program
        result = os.system(f"./hw8 -c {input_file_path} {output_file_path}")
        if result != 0:
            return False
        return True
    except Exception as e:
        print(f"Error running Huffman program: {e}")
        return False

@app.route('/upload', methods=['POST'])
def upload_file():
    if 'file' not in request.files:
        return jsonify({"error": "No file part"}), 400
    
    file = request.files['file']
    if file.filename == '':
        return jsonify({"error": "No selected file"}), 400
    
    filename = secure_filename(file.filename)
    input_file_path = os.path.join(app.config['UPLOAD_FOLDER'], filename)
    output_file_path = os.path.join(app.config['OUTPUT_FOLDER'], filename + '.huff')
    
    file.save(input_file_path)
    
    # Run the Huffman compression
    if not run_huffman(input_file_path, output_file_path):
        return jsonify({"error": "Huffman compression failed"}), 500
    
    return jsonify({"message": "File uploaded and processed successfully", "output_file": filename + '.huff'})

@app.route('/download/<filename>', methods=['GET'])
def download_file(filename):
    filepath = os.path.join(app.config['OUTPUT_FOLDER'], filename)
    if os.path.exists(filepath):
        return send_file(filepath, as_attachment=True)
    else:
        return jsonify({"error": "File not found"}), 404

if __name__ == '__main__':
    app.run(debug=True)

'''
curl -X POST -F "file=@/path/to/input.txt" http://127.0.0.1:5000/upload
curl -O http://127.0.0.1:5000/download/input.txt.huff
'''
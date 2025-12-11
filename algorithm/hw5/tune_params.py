import subprocess
import random
import re
import sys

# Targets from hw4 ans_dt0X.txt
TARGETS = [194.153, 256.901, 335.777, 428.872]
TOLERANCE = 1e-9 # Strict inequality or very close

def generate_params():
    # Refined search space based on previous best
    params = {
        'run_times': 30, # More stable results
        'max_evaluation': -1,
        'dot_factor': random.uniform(4.0, 5.0),
        'alpha': random.uniform(0.35, 0.55),
        'beta': random.uniform(0.85, 0.99),
        'temperature': random.uniform(0.20, 0.40),
        'cooling_rate': random.uniform(0.997, 0.9995)
    }
    return params

def run_simulation(params):
    cmd = [
        "./main",
        "p1.txt", "p2.txt", "p3.txt", "p4.txt",
        str(params['run_times']),
        str(params['max_evaluation']),
        str(params['dot_factor']),
        str(params['alpha']),
        str(params['beta']),
        str(params['temperature']),
        str(params['cooling_rate'])
    ]
    
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
        output = result.stdout
        
        # Parse output for "best: X.XXX" matches
        # The output format for each file ends with:
        # best: <dist> mean: <mean>
        
        matches = re.findall(r"best: ([\d\.]+) mean:", output)
        if len(matches) != 4:
            return None
        
        distances = [float(x) for x in matches]
        return distances
    except Exception as e:
        print(f"Error running simulation: {e}")
        return None

def main():
    print("Starting parameter tuning...")
    print(f"Targets: {TARGETS}")

    trial = 0
    best_diff_sum = float('inf')

    while True:
        trial += 1
        params = generate_params()
        
        distances = run_simulation(params)
        
        if distances is None:
            continue
            
        # Check against targets
        success = True
        diff_sum = 0
        current_diffs = []
        
        for i, dist in enumerate(distances):
            diff = dist - TARGETS[i]
            current_diffs.append(diff)
            # We want dist <= TARGET
            # Allow a tiny float tolerance if equal
            if dist > TARGETS[i] + TOLERANCE:
                success = False
            
            diff_sum += max(0, diff) # Only penalize being worse

        if trial % 10 == 0:
            print(f"Trial {trial}: {distances} (Diff: {diff_sum})")

        if success:
            print("\nFOUND MATCHING PARAMETERS!")
            print(f"Parameters: {params}")
            print(f"Results: {distances}")
            print("Command line arguments:")
            print(f"{params['run_times']} {params['max_evaluation']} {params['dot_factor']} {params['alpha']} {params['beta']} {params['temperature']} {params['cooling_rate']}")
            break
            
        if diff_sum < best_diff_sum:
            best_diff_sum = diff_sum
            print(f"[Best so far] Trial {trial}: Distances {distances} (Total Excess: {diff_sum:.4f})")
            print(f"  Params: {params}")

if __name__ == "__main__":
    main()

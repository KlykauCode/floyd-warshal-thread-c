import pandas as pd
import matplotlib.pyplot as plt

data_file = "results.txt"

with open(data_file, 'r') as file:
    lines = file.readlines()

lines = [line.strip() for line in lines if line.strip()]
headers = lines[0].split(",") 
data = [list(map(int, line.split(","))) for line in lines[1:]]

df = pd.DataFrame(data, columns=[header.strip() for header in headers])

plt.figure(figsize=(12, 8))

plt.plot(
    df["Vertices"], 
    df["Single-thread (ms)"], 
    label="Single-threaded", 
    marker='o'
)

plt.plot(
    df["Vertices"], 
    df["Multi-thread (ms)"], 
    label="Multi-threaded", 
    marker='s'
)

plt.title("Execution Time vs Number of Vertices", fontsize=16)
plt.xlabel("Number of Vertices", fontsize=14)
plt.ylabel("Execution Time (ms)", fontsize=14)
plt.grid(True, linestyle="--", linewidth=0.5)
plt.legend(fontsize=12)

output_file = "performance_comparison.png"
plt.savefig(output_file)

plt.show()
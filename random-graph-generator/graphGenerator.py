import random

def generate_random_big_graph(num_vertices, density, min_weight, max_weight, output_file):
    with open(output_file, 'w') as f:
        f.write(f"{num_vertices}\n")
        for i in range(num_vertices):
            row = []
            for j in range(num_vertices):
                if i == j:
                    row.append("0") 
                else:
                    if random.random() < density:
                        weight = random.randint(min_weight, max_weight)
                        row.append(str(weight))
                    else:
                        row.append("INF")
            f.write(' '.join(row) + '\n')
    print(f"Graph was generated in:  '{output_file}'.")

if __name__ == "__main__":
    NUM_VERTICES = 2000          
    DENSITY = 0.8            
    MIN_WEIGHT = 1             
    MAX_WEIGHT = 300           
    OUTPUT_FILE = "big_graph2000.txt"

    generate_random_big_graph(NUM_VERTICES, DENSITY, MIN_WEIGHT, MAX_WEIGHT, OUTPUT_FILE); 
    

    
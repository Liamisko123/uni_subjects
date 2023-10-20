import random
import copy
def print_data(data):
    for line in data:
        for col in line:
            print(col, end=" ")
        print("\n")

def generate_data(n_rows, n_cols):
    data = []
    for row in range(n_rows):
        data.append([])
        for col in range(n_cols):
            data[row].append(random.randint(0, 1))
    return data

if __name__ == "__main__":
    data = copy.deepcopy(generate_data(3, 5))
    print_data(data)
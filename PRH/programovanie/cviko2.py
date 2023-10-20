import random

def find_max(in_list):
    current_max = [float('-inf'), 0]
    for i, element in enumerate(in_list):
        if element > current_max[0]:
            current_max = [element, i]
    return current_max

if __name__ == "__main__":
    my_list = []
    for i in range(40):
        my_list.append(random.uniform(0, 100))
    print(find_max(my_list))
    print(max(my_list))
    print(my_list)
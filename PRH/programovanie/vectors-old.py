import numpy as np
class MyVector:
    def __init__(self, vector):
        self.vector = vector

    def __mul__(self, other):
        sum = 0
        for index in range(len(self.vector)):
            sum += self.vector[index] * other.vector[index]
        return sum

    def get_vector(self):
        return self.vector

    def is_perpendicular_to(self, other):
        result = self * other
        if result == 0:
            return True
        return False

    def cross_product(self, other):
        if(len(self.vector) <= 3 and len(other.vector) <= 3): 
            return MyVector(list(np.cross(self.vector, other.vector))) 
        return self

if __name__ == "__main__":
    v = MyVector([1, 0, 0, 1])
    w = MyVector([0, 1, 0, 99])

    print(v * w)
    print(v.get_vector())
    perpen = v.cross_product(w)
    print(perpen.vector)

    print(v.is_perpendicular_to(w))

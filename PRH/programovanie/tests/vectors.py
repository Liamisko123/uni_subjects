class MyVector:
    def __init__(self, vector):
        self.vector = vector

    def __mul__(self, other):
        summed = 0
        for index in range(len(self.vector)):
            summed += self.vector[index] * other.vector[index]
        return summed
    
    def __add__(self, other):
        summed_vector = []
        for i in range(len(self.vector)):
            summed_vector.append(self.vector[i] + other.vector[i])
        return MyVector(summed_vector)
    
    def norm(self):
        v_pows = 0
        for v in self.vector:
            v_pows += v**2
        sqrt = v_pows ** (1/2)
        return sqrt

    def get_vector(self):
        return self.vector


if __name__ == "__main__":
    v = MyVector([1, 2, 3])
    w = MyVector([3, 4, 0])

    print(v * w)
    print(v.get_vector())

    print(f"Norm: {w.norm()}")
    print(f"Sum: {(v + w).vector}")

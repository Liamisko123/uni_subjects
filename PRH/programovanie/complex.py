class complexNumber:
    def __init__(self, real, imaginary) -> None:
        self.real = real
        self.imaginary = imaginary

    def __add__(self, other) -> tuple:
        return (self.real + other.real, self.imaginary + other.imaginary)

    def __sub__(self, other) -> tuple:
        return (self.real - other.real, self.imaginary - other.imaginary)
        

    def __mul__(self, other) -> tuple:
        return (self.real * other.real, self.imaginary * other.imaginary)
    
    def get_size(self):
        return ((self.real**2) + (self.imaginary**2))**(1/2) #calculate abs(complex_number)
        
    def to_string(self):
        return f"{self.real} + {self.imaginary}i"

if __name__ == "__main__":
    complex_num1 = complexNumber(4, 3)
    complex_num2 = complexNumber(2, 8)
    print(complex_num1 + complex_num2)
    print(complex_num1 - complex_num2)
    print(complex_num1 * complex_num2)

    print(complex_num1.to_string())
    print(complex_num2.to_string())

    print(complex_num1.get_size())
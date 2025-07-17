# Program for basic arithmetic operations

# Addition
def add(a, b):
    return a + b

# Subtraction
def subtract(a, b):
    return a - b

# Multiplication
def multiply(a, b):
    return a * b

# Division
def divide(a, b):
    if b != 0:
        return a / b
    else:
        return "Division by zero is not allowed"

# Modulus
def modulus(a, b):
    return a % b

# Exponentiation
def exponentiate(a, b):
    return a ** b

# Floor Division
def floor_divide(a, b):
    if b != 0:
        return a // b
    else:
        return "Division by zero is not allowed"

# Example usage
if __name__ == "__main__":
    x = 10
    y = 5

    print("Addition:", add(x, y))
    print("Subtraction:", subtract(x, y))
    print("Multiplication:", multiply(x, y))
    print("Division:", divide(x, y))
    print("Modulus:", modulus(x, y))
    print("Exponentiation:", exponentiate(x, y))
    print("Floor Division:", floor_divide(x, y))
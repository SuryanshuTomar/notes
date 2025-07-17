# Program 1: Check if a number is positive, negative, or zero
number = float(input("Enter a number: "))
if number > 0:
    print("The number is positive.")
elif number < 0:
    print("The number is negative.")
else:
    print("The number is zero.")

# Program 2: Find the largest of three numbers
a = float(input("Enter the first number: "))
b = float(input("Enter the second number: "))
c = float(input("Enter the third number: "))

if a > b and a > c:
    print("The largest number is:", a)
elif b > c:
    print("The largest number is:", b)
else:
    print("The largest number is:", c)

# Program 3: Check if a year is a leap year
year = int(input("Enter a year: "))
if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
    print(f"{year} is a leap year.")
else:
    print(f"{year} is not a leap year.")

# Program 4: Conditional expression to check if a number is even or odd
num = int(input("Enter a number: "))
result = "Even" if num % 2 == 0 else "Odd"
print(f"The number is {result}.")

# Program 5: Ternary expression to find the smaller of two numbers
x = float(input("Enter the first number: "))
y = float(input("Enter the second number: "))
smaller = x if x < y else y
print(f"The smaller number is: {smaller}")
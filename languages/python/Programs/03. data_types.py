# The is how we check the data types in python
name = "Alex Mercer" # string
age = 27 # integer
isBachelor = True # boolean
gpa = 3.4 # floats

print(type(name))
print(type(age))
print(type(isBachelor))
print(type(gpa))

# Type casting examples in Python

# Integer to float
age_float = float(age)  # Converts integer to float
print(age_float, type(age_float))

# Float to integer
gpa_int = int(gpa)  # Converts float to integer
print(gpa_int, type(gpa_int))

# Integer to string
age_str = str(age)  # Converts integer to string
print(age_str, type(age_str))

# String to integer
age_from_str = int("27")  # Converts string to integer
print(age_from_str, type(age_from_str))

# String to float
gpa_from_str = float("3.4")  # Converts string to float
print(gpa_from_str, type(gpa_from_str))

# Float to string
gpa_str = str(gpa)  # Converts float to string
print(gpa_str, type(gpa_str))

# Boolean to integer
isBachelor_int = int(isBachelor)  # Converts boolean to integer
print(isBachelor_int, type(isBachelor_int))

# Integer to boolean
age_bool = bool(age)  # Converts integer to boolean
print(age_bool, type(age_bool))

# String to boolean
bool_from_str = bool("True")  # Converts string to boolean
print(bool_from_str, type(bool_from_str))

# Boolean to string
isBachelor_str = str(isBachelor)  # Converts boolean to string
print(isBachelor_str, type(isBachelor_str))
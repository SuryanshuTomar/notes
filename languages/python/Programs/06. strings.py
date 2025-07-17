# String Methods and Indexing Examples

# String Methods
sample_text = "Hello, World!"

# 1. Convert to uppercase
uppercase_text = sample_text.upper()
print("Uppercase:", uppercase_text)

# 2. Convert to lowercase
lowercase_text = sample_text.lower()
print("Lowercase:", lowercase_text)

# 3. Replace a substring
replaced_text = sample_text.replace("World", "Python")
print("Replaced Text:", replaced_text)

# 4. Split the string
split_text = sample_text.split(", ")
print("Split Text:", split_text)

# 5. Check if string starts with a specific substring
starts_with_hello = sample_text.startswith("Hello")
print("Starts with 'Hello':", starts_with_hello)

# 6. Check if string ends with a specific substring
ends_with_exclamation = sample_text.endswith("!")
print("Ends with '!':", ends_with_exclamation)

# 7. Find the index of a substring
index_of_world = sample_text.find("World")
print("Index of 'World':", index_of_world)

# 8. Strip whitespace
whitespace_text = "   Hello, World!   "
stripped_text = whitespace_text.strip()
print("Stripped Text:", stripped_text)

# Indexing
example_text = "Python"

# Accessing characters by index
first_char = example_text[0]  # First character
print("First Character:", first_char)

last_char = example_text[-1]  # Last character
print("Last Character:", last_char)

# Slicing the string
substring = example_text[1:4]  # Characters from index 1 to 3
print("Substring (1:4):", substring)

reversed_text = example_text[::-1]  # Reverse the string
print("Reversed Text:", reversed_text)
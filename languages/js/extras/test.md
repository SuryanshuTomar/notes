# How JavaScript Functions Work Internally (Example-Based Explanation)

## Example Code:
```javascript
function greet(name) {
    const message = `Hello, ${name}!`;
    console.log(message);
    return message;
}

greet("Alice");
```

---

## Step-by-Step Explanation:

### 1. **Function Declaration**:
- When the JavaScript engine encounters the `greet` function declaration, it allocates memory for the function in the **heap memory**.
- The function's reference is stored in the **variable environment** of the global execution context.

### 2. **Function Invocation**:
- When `greet("Alice")` is called, the JavaScript engine:
  1. Creates a new **execution context** for the `greet` function.
  2. Pushes this execution context onto the **call stack**.

### 3. **Execution Context Creation**:
The execution context for `greet` contains:
- **Variable Environment**:
  - `name = "Alice"`
  - `message = "Hello, Alice!"`
- **Lexical Environment**:
  - Tracks the outer (global) scope for variable lookups.
- **`this` Binding**:
  - Refers to the global object (or `undefined` in strict mode).

### 4. **Function Execution**:
- The function executes line by line:
  1. `const message = "Hello, Alice!";` creates a local variable `message`.
  2. `console.log(message);` logs `"Hello, Alice!"` to the console.
  3. `return message;` returns the string `"Hello, Alice!"`.

### 5. **Function Return**:
- Once the function finishes execution:
  - Its execution context is **popped off** the call stack.
  - The returned value (`"Hello, Alice!"`) is passed back to the caller.

---

## Visual Representation:

### Memory Allocation:
```plaintext
Heap Memory: [Function greet()]
Stack Memory: [Execution Contexts]
```

### Call Stack Visualization:
1. **Initial State**:
   ```plaintext
   [Global Execution Context]
   ```

2. **`greet("Alice")` Called**:
   ```plaintext
   [greet Execution Context]
   [Global Execution Context]
   ```

3. **`greet` Returns**:
   ```plaintext
   [Global Execution Context]
   ```

---

### Execution Context Breakdown:
```plaintext
Execution Context for greet():
+-----------------------------+
| Variable Environment:       |
| - name: "Alice"             |
| - message: "Hello, Alice!"  |
|                             |
| Lexical Environment:        |
| - Outer Scope: Global       |
|                             |
| this Binding: Global Object |
+-----------------------------+
```

---

### Call Stack Example:
```plaintext
Global() -> greet("Alice")
```

---

### Diagram:
```plaintext
Heap Memory:
+-------------------+
| Function greet()  |
+-------------------+

Call Stack:
+-------------------+
| greet() Execution |
| Global Context    |
+-------------------+
```

---

### Additional Notes:
- **Call Stack**: Manages the order of function execution.
- **Heap Memory**: Stores function objects and other reference types.
- **Garbage Collection**: Frees memory for unused variables and functions.
- **Lexical Scope**: Determines variable accessibility based on where the function is defined.
- **`this` Binding**: Depends on how the function is called.

This example demonstrates how JavaScript functions are executed step by step, with memory allocation and call stack operations.

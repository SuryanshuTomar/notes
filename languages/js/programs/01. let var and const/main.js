// 01. let var and const

// Q1: What is the difference between var, let, and const?
var a = 1;
let b = 2;
const c = 3;
a = 10; // allowed
b = 20; // allowed
// c = 30; // Error: Assignment to constant variable

console.log(a, b, c); // 10 20 3

// Q2: What is variable hoisting? How does it differ for var, let, and const?
console.log(x); // undefined (var is hoisted and initialized with undefined)
var x = 5;

// console.log(y); // ReferenceError: Cannot access 'y' before initialization
let y = 10;

// console.log(z); // ReferenceError: Cannot access 'z' before initialization
const z = 15;

// Q3: What is temporal dead zone (TDZ)?
// The time between entering scope and variable declaration for let/const is TDZ.
// Accessing variable in TDZ throws ReferenceError.

// Q4: What is variable shadowing?
let value = 'outer';
{
    let value = 'inner'; // shadows outer 'value'
    console.log(value); // 'inner'
}
console.log(value); // 'outer'

// Q5: Can you shadow a variable declared with var using let or const?
var num = 100;
{
    let num = 200; // allowed, shadows outer 'num'
    console.log(num); // 200
}
console.log(num); // 100

// Q6: Can you shadow a variable declared with let using var?
let foo = 1;
{
    // var foo = 2; // SyntaxError: Identifier 'foo' has already been declared
}

// Q7: What happens if you redeclare a variable with var in the same scope?
var test = 1;
var test = 2; // allowed
console.log(test); // 2

// Q8: What happens if you redeclare a variable with let or const in the same scope?
let test2 = 1;
// let test2 = 2; // SyntaxError: Identifier 'test2' has already been declared

// Q9: Are var, let, and const block scoped?
{
    var blockVar = 'I am var';
    let blockLet = 'I am let';
    const blockConst = 'I am const';
}
console.log(blockVar); // 'I am var'
// console.log(blockLet); // ReferenceError
// console.log(blockConst); // ReferenceError

// Q10: What is the scope of var, let, and const?
function scopeTest() {
    if (true) {
        var x = 1;
        let y = 2;
        const z = 3;
    }
    console.log(x); // 1 (function scoped)
    // console.log(y); // ReferenceError (block scoped)
    // console.log(z); // ReferenceError (block scoped)
}
scopeTest();


// Q11: How does variable hoisting interact with function declarations and expressions?
console.log(hoistedFunc()); // 'I am hoisted'
// console.log(exprFunc()); // TypeError: exprFunc is not a function

function hoistedFunc() {
    return 'I am hoisted';
}

var exprFunc = function() {
    return 'I am an expression';
};

// Q12: What happens if you use let/const in a for loop header?
for (let i = 0; i < 2; i++) {
    setTimeout(() => console.log('let i:', i), 0); // 0, 1
}
for (var j = 0; j < 2; j++) {
    setTimeout(() => console.log('var j:', j), 0); // 2, 2
}

// Q13: Can you attach properties to variables declared with var, let, or const in the global scope?
var globalVar = 1;
let globalLet = 2;
const globalConst = 3;
console.log(window.globalVar); // 1 (in browsers)
// console.log(window.globalLet); // undefined
// console.log(window.globalConst); // undefined

// Q14: What happens with let/const in the global scope in strict mode?
"use strict";
// let strictLet = 10;
// console.log(window.strictLet); // undefined

// Q15: How do closures interact with var, let, and const in loops?
var funcsVar = [];
let funcsLet = [];
for (var k = 0; k < 3; k++) {
    funcsVar.push(() => k);
}
for (let l = 0; l < 3; l++) {
    funcsLet.push(() => l);
}
console.log(funcsVar.map(fn => fn())); // [3, 3, 3]
console.log(funcsLet.map(fn => fn())); // [0, 1, 2]

// Q16: What happens if you declare a variable with the same name in different scopes?
let outer = 'outer';
{
    let outer = 'inner';
    {
        let outer = 'innermost';
        console.log(outer); // 'innermost'
    }
    console.log(outer); // 'inner'
}
console.log(outer); // 'outer'

// Q17: Can you use let or const before declaration in the same block?
// console.log(beforeLet); // ReferenceError
let beforeLet = 5;

// Q18: What is the difference between const object and const primitive?
const arr = [1, 2];
arr.push(3); // allowed
// arr = [4, 5]; // Error

const obj = { a: 1 };
obj.b = 2; // allowed
// obj = {}; // Error

// Q19: How does destructuring interact with let, var, and const?
const [d1, d2] = [1, 2];
let { e1, e2 } = { e1: 3, e2: 4 };
var [f1, f2] = [5, 6];

// Q20: What happens if you use var, let, and const in eval?
eval('var evalVar = 1;');
eval('let evalLet = 2;');
eval('const evalConst = 3;');
console.log(evalVar); // 1
// console.log(evalLet); // ReferenceError
// console.log(evalConst); // ReferenceError


/*
Summary:
- var is function scoped, hoisted, can be redeclared, and can be shadowed by let/const.
- let and const are block scoped, hoisted but not initialized (TDZ), cannot be redeclared in the same scope.
- const must be initialized at declaration and cannot be reassigned.
- Shadowing with let/const is allowed, but not the other way around.
- Hoisting works differently for var (initialized as undefined) and let/const (TDZ).
*/

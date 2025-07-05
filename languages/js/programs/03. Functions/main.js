// Question 1 - IIFE Output based question - What will be the output of the following code?
(function() {
    try {
        var a = b = 3; // reference error as b is not declared with var, let, or const
        console.log(a);
        console.log(b); 
    } catch (error) {
        console.log("Error:", error.message); // "Error: b is not defined"
    }
})();

// ----------------------------------------------------------------------------------------------------
// Question 2 - IIFE Output based question - What will be the output of the following code?
(function(x) {
    return (function(y) {
        console.log(x); // 10
        console.log(y); // 20
    })(20);
})(10);

// ----------------------------------------------------------------------------------------------------
// Question 3 - Function Scope - What will be the output of the following code?
var num1 = 10,
    num2 = 20,
    name = "John";

function multiply() {
    var num1 = 5; // local variable
    return num1 * num2; // uses the global num2
}

multiply(); // 5 * 20 = 100

// ----------------------------------------------------------------------------------------------------
// Question 4 - Nested Function Scope - What will be the output of the following code?

var player = "John"; // global variable
function getScore() {
    var score = 100; // local variable
    var overs = 12; // local variable

    function displayOvers() {
        console.log(overs); // 12
    }

    function displayPlayerData() {
        console.log(`Player: ${player} has scored : ${score}`); // Player: John has scored : 100
    }

    displayOvers();
    displayPlayerData()
}

// -----------------------------------------------------------------------------------------------------
// Question 5 - Function Scope - What will be the output of the following code?

for (var i = 0; i < 5; i++) {
    setTimeout(function() {
        console.log(i); // 5, because var is function scoped and the loop completes before the timeout executes
    }, 1000);
}

for (let j = 0; j < 5; j++) {
    setTimeout(function() {
        console.log(j); // 0, 1, 2, 3, 4, because let is block scoped and each iteration has its own scope
    }, 1000);
}

// -----------------------------------------------------------------------------------------------------
// Question 6 - Function Hoisting - What will be the output of the following code?


// => Polyfill for Array.prototype.map
if (!Array.prototype.myMap) { // Check if myMap is not already defined
    Array.prototype.myMap = function (callback, thisArg) {
        if (this == null) throw new TypeError('Array.prototype.myMap called on null or undefined');
        if (typeof callback !== 'function') throw new TypeError(callback + ' is not a function');
        const arr = Object(this); // Convert this to an object
        const len = arr.length >>> 0; // Use unsigned right shift to ensure length is a non-negative integer.
        const result = new Array(len);
        for (let i = 0; i < len; i++) {
            if (i in arr) {
                result[i] = callback.call(thisArg, arr[i], i, arr);
            }
        }
        return result;
    };
}

// Example for myMap
const nums = [1, 2, 3];
const doubled = nums.myMap(x => x * 2);
console.log(doubled); // [2, 4, 6]

// -------------------------------------------------------------------------------------------------------------------
// => Polyfill for Array.prototype.filter
if (!Array.prototype.myFilter) { // Check if myFilter is not already defined
    Array.prototype.myFilter = function (callback, thisArg) {
        if (this == null) throw new TypeError('Array.prototype.myFilter called on null or undefined');
        if (typeof callback !== 'function') throw new TypeError(callback + ' is not a function');
        const arr = Object(this);
        const len = arr.length >>> 0;
        const result = [];
        for (let i = 0; i < len; i++) {
            if (i in arr) {
                if (callback.call(thisArg, arr[i], i, arr)) {
                    result.push(arr[i]);
                }
            }
        }
        return result;
    };
}

// Example for myFilter
const mixed = [1, 2, 3, 4, 5];
const evens = mixed.myFilter(x => x % 2 === 0);
console.log(evens); // [2, 4]

// -------------------------------------------------------------------------------------------------------------------
// => Polyfill for Array.prototype.reduce
if (!Array.prototype.myReduce) { // Check if myReduce is not already defined
    Array.prototype.myReduce = function (callback, initialValue) {
        if (this == null) throw new TypeError('Array.prototype.myReduce called on null or undefined');
        if (typeof callback !== 'function') throw new TypeError(callback + ' is not a function');
        const arr = Object(this); // Convert this to an object
        const len = arr.length >>> 0; // Use unsigned right shift to ensure length is a non-negative integer.
        let accumulator, startIdx = 0;
        
        if (arguments.length > 1) { // If initialValue is provided
            accumulator = initialValue; // Use the provided initial value
        } else { // If no initialValue is provided
            while (startIdx < len && !(startIdx in arr)) startIdx++; // Find the first index with a value
            if (startIdx >= len) throw new TypeError('Reduce of empty array with no initial value'); // If no values found, throw error
            accumulator = arr[startIdx++]; // Use the first value as the initial accumulator
        }
        
        // Iterate through the array starting from startIdx
        // and apply the callback function to each element
        for (let i = startIdx; i < len; i++) { //
            if (i in arr) {
                accumulator = callback(accumulator, arr[i], i, arr);
            }
        }
        return accumulator;
    };
}

// Example for myReduce
const sum = [1, 2, 3, 4].myReduce((acc, curr) => acc + curr, 0);
console.log(sum); // 10


// -------------------------------------------------------------------------------------------------------------------
/*
* The expression `>>> 0` performs an unsigned right shift by 0 places:
* 1. It converts the operand to a 32-bit integer
* 2. Shifts right by 0 positions (effectively no shift)
* 3. Fills vacant bits with 0s (unlike >> which uses sign bit)
* 
* This guarantees:
* - Non-numeric values become 0
* - null/undefined become 0
* - Negative numbers become large positive numbers
* - Decimal values are truncated (floor)
* 
* It's a standard way to ensure array lengths are valid non-negative integers
* 
* Examples:
* (-1) >>> 0 = 4294967295 (converts negative to large positive)
* (3.75) >>> 0 = 3 (truncates decimal)
* ('5') >>> 0 = 5 (converts string to number)
* (NaN) >>> 0 = 0 (converts NaN to 0)
* (null) >>> 0 = 0 (converts null to 0)
* (undefined) >>> 0 = 0 (converts undefined to 0)
*/

// -------------------------------------------------------------------------------------------------------------------

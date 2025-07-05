// Function to print binary representation of any JavaScript value
function toBinary(value) {
    // Handle different types
    if (typeof value === 'number') {
        return value.toString(2);
    } else if (typeof value === 'string') {
        // Convert each character to its binary representation
        return Array.from(value)
            .map(char => char.charCodeAt(0).toString(2).padStart(8, '0'))
            .join(' ');
    } else if (typeof value === 'boolean') {
        return value ? '1' : '0';
    } else if (value === null) {
        return 'null (no binary representation)';
    } else if (value === undefined) {
        return 'undefined (no binary representation)';
    } else if (typeof value === 'object') {
        try {
            // For objects, arrays, etc., convert to JSON first
            return Array.from(JSON.stringify(value))
                .map(char => char.charCodeAt(0).toString(2).padStart(8, '0'))
                .join(' ');
        } catch (e) {
            return 'Cannot convert to binary: ' + e.message;
        }
    } else {
        return `Cannot convert ${typeof value} to binary`;
    }
}


// Examples
// console.log('Number 42 in binary:', toBinary(42));
// console.log('String "ABC" in binary:', toBinary('ABC'));
// console.log('Boolean true in binary:', toBinary(true));
// console.log('Array [1,2,3] in binary:', toBinary([1, 2, 3]));
// console.log('Object {a:1} in binary:', toBinary({a: 1}));
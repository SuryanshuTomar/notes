// Question 1 - Return only name of the students in Uppercase and Capitalize letters

const students1 = [
    { name: 'John', age: 20, rollNo: 101, marks: 85 },
    { name: 'Sarah', age: 22, rollNo: 102, marks: 90 },
    { name: 'Mike', age: 21, rollNo: 103, marks: 75 },
    { name: 'Emma', age: 23, rollNo: 104, marks: 95 },
    { name: 'Alex', age: 20, rollNo: 105, marks: 80 }
];

const studentNamesInUpperCase = students1.map(student => student.name.toUpperCase());
const studentNamesInCaps = students1.map(student => student.name.charAt(0).toUpperCase() + student.name.slice(1).toLowerCase());

console.log("Student Names in Uppercase : ", studentNamesInUpperCase); // ['JOHN', 'SARAH', 'MIKE', 'EMMA', 'ALEX']
console.log("Student Names in Capitalize format", studentNamesInCaps); // ['John', 'Sarah', 'Mike', 'Emma', 'Alex']

// ---------------------------------------------------------------------------------------
// Question 1 - Return only those students who have marks greater than 80

const students2 = [
    { name: 'John', age: 20, rollNo: 101, marks: 85 },
    { name: 'Sarah', age: 22, rollNo: 102, marks: 90 },
    { name: 'Mike', age: 21, rollNo: 103, marks: 75 },
    { name: 'Emma', age: 23, rollNo: 104, marks: 95 },
    { name: 'Alex', age: 20, rollNo: 105, marks: 80 }
];

const studentsWithHighMarks = students2.filter(student => student.marks > 80);
console.log("Students with marks greater than 80: ", studentsWithHighMarks); 
// [
//   { name: 'John', age: 20, rollNo: 101, marks: 85 }, 
//   { name: 'Sarah', age: 22, rollNo: 102, marks: 90 },
//   { name: 'Emma', age: 23, rollNo: 104, marks: 95 }
// ]

// ---------------------------------------------------------------------------------------
// Question 3 - Calculate the total marks of all students

const students3 = [
    { name: 'John', age: 20, rollNo: 101, marks: 85 },
    { name: 'Sarah', age: 22, rollNo: 102, marks: 90 },
    { name: 'Mike', age: 21, rollNo: 103, marks: 75 },
    { name: 'Emma', age: 23, rollNo: 104, marks: 95 },
    { name: 'Alex', age: 20, rollNo: 105, marks: 80 }
];

const totalMarks = students3.reduce((accumulator, student) => accumulator + student.marks, 0);
console.log("Total Marks of all students: ", totalMarks); // 425

// ---------------------------------------------------------------------------------------
// Question 4 - Return the names of students who have marks greater than 80 and are older than 21
const students4 = [
    { name: 'John', age: 20, rollNo: 101, marks: 85 },
    { name: 'Sarah', age: 22, rollNo: 102, marks: 90 },
    { name: 'Mike', age: 21, rollNo: 103, marks: 75 },
    { name: 'Emma', age: 23, rollNo: 104, marks: 95 },
    { name: 'Alex', age: 20, rollNo: 105, marks: 80 }
];  

const studentsWithHighMarksAndAge = students4
    .filter(student => student.marks > 80 && student.age > 21)
    .map(student => student.name);
console.log("Students with marks greater than 80 and older than 21: ", studentsWithHighMarksAndAge); // ['Sarah', 'Emma']

// ---------------------------------------------------------------------------------------  

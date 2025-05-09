// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract ClassroomAttendance {
    // Teacher's address
    address public teacher;

    // Mapping to store attendance
    mapping(address => bool) public attendance;

    // List of students who attended
    address[] public students;

    // Event to log attendance
    event AttendanceMarked(address student);

    // Constructor sets the teacher
    constructor() {
        teacher = msg.sender;
    }

    // Function to mark attendance (only teacher can call)
    function markAttendance(address student) public {
        require(msg.sender == teacher, "Only the teacher can mark attendance");
        require(!attendance[student], "Student already marked present");

        attendance[student] = true;
        students.push(student);

        emit AttendanceMarked(student);
    }

    // Function to get the total number of students who attended
    function getAttendanceCount() public view returns (uint) {
        return students.length;
    }

    // Function to check if a student has attended
    function hasAttended(address student) public view returns (bool) {
        return attendance[student];
    }
}
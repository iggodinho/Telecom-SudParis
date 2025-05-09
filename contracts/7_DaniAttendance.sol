// SPDX-License-Identifier: MIT

pragma solidity ^0.8.0;

contract ClassroomAttendance {

    address public teacher;


    struct Student {
        string name;
        bool attendance;
    }

    mapping(uint => Student) public studentRecords;

    uint[] public rollNumbers;

    
    event AttendanceMarked(uint rollNumber, string name);

    
    constructor() {
        teacher = msg.sender;
        
        rollNumbers.push(1);
        studentRecords[1] = Student("John", false);

        /*
        1.
        Similar to how John was added, add two more students
        named Jane and Mary with roll number 2 and 3
        respectively. 
        */




    }

    /*
    2.
    Create a modifier called onlyTeacher which gives access to teachers only.
    The code will be similar to the one we practiced in previous program.
    */






    
    function markAttendance(uint _rollnumber) public onlyTeacher {
        
        /*
        3. You need to check if the student is present or not. For this
           see if the rollnumber is present in the array
        */





        
        /*
        4. Once the rollnumber is present, fetch the student data from
           the records. Remove Student("Nish", false) and replace it 
           with your code. 
        */
        
        



        /*
        5. First, check if the student is already marked present or not.
           If yes, you need to throw error message.
           If no, then mark the student present. 
        */
        




        emit AttendanceMarked(_rollnumber, _student.name);
    }

    
    function hasAttended(uint _rollnumber) public view returns (bool) {
        require(_rollnumber < rollNumbers.length, "Student not found");
        /*
        To return this value, you need to access one of the variable
        stored in struct. We have seen how to perform access in our 
        previous program. Remove the word false below and fill it
        with your answer. 
        */
        return false
    }

    // Function to get total number of students
    function getTotalStudents() public view returns (uint) {
        return rollNumbers.length;
    }
}

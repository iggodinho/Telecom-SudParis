// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract EnumExample {
    enum Status { Active, Inactive }

    Status public currentStatus;

    function setActive() public {
        currentStatus = Status.Active;
    }

    /*
    1.
    Similar to setActive function, make another function
    called setInactive which changes the currentStatus to 
    inactive.
    */
    
}
// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;


contract Counter {

    uint public counter;

    function increase_counter() public {
        counter += 1;
    }
    /*
    Insert your code below. 
    -----------------------
    a. Create a function named decrease_counter
    b. The function takes no argument
    c. In function body
        i. First check if the value of counter variable is 0 or not.
           For this, you need to use "require"
       ii. Then decrease the counter value 
    */
    
    function decrease_counter() public {
        require(counter>0, "The counter value is 0");
        counter-=1;
    }
}
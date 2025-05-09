// SPDX-License-Identifier: GPL-3.0

pragma solidity >=0.8.2 <0.9.0;


contract Storage {

    // 1. Create a variable called "owner" of type "address"
    address public owner;
    
    string public name = "John Doe";

    constructor() {
        // 2. Use msg.sender global variable to assign address to the owner variable.
        owner = msg.sender;
    }

    function change_name(string memory _name) public {
        // Check if the msg.sender is the owner of the contract. Then change the name.
        require(msg.sender==owner,"You are not the owner!");
    
        name = _name;
    }


}
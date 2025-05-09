// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract ArrayStorage {

    /* [Information]
    This is a struct data type. It is generally used to store
    information related to certain entity. 
    */
    struct Item {
        string name;
        uint count;
    }

    /*
    1.
    Similar to the array we created in the class session,
    Create an array of type Item. It's name should be items.
    Mark it as public. The array should be a dynamic sized array.
    */
    

    function add_item(string memory _name, uint _count) public {
        /*
        2. In this function, we want add the item information first in struct and then
        push it in the array. Using the data received from the function arguments,
        - Create an struct object.
           [To create struct object use the syntax <StructName>(argument1, argument2)]
        - Then push the struct object into the array.
        */
        
    }

    function get_item_name(uint index) public view returns (string memory) {
        require(index < items.length, "Index is out of bounds.");
        return items[index].name;
    }
}
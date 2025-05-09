// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Ownership {
    address public owner;

    uint public btc_price;

    constructor() {
        owner = msg.sender;
    }


    modifier onlyOwner() {
        require(msg.sender == owner, "You are not the owner");
        _;
    }

    function changeOwner(address newOwner) public onlyOwner {
        owner = newOwner;
    }

    /*
    Add a function modifier to this function so that only owner can
    make changes. It should be similar to changeOwner function. Also
    make necessary adjustments (Hint: 1 line inside the function body
    needs to be removed).
    */
    function change_btc_price(uint _btc_price) public {
        require(msg.sender == owner, "You are not the owner");
        btc_price = _btc_price;
    }
}
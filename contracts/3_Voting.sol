// SPDX-License-Identifier: MIT


pragma solidity ^0.8.0;

contract Voting {
    
    /*
    1.  
    - Create a mapping with name votes. 
    - The mapping should map candidate name to the number of votes. (candidate => number of votes) 
    - Mark the mapping as public
    */
    
    mapping (string => int) public votes;

    function vote(string memory candidate) public {
        require(votes[candidate] == 0, "You have already voted");
        votes[candidate] += 1;
    }

    /*
    2.
    - Create a function named show_vote and mark it as public.
    - It should take the candidate's name as function argument. 
       The name of the argument should be _candidate and type string memory
    - Then the function body should return the number of votes received by the candidate.
    - After completing the above steps, you will receive a warning [Function is underlined with yellow line]. Fix it. 
    */
    
    function show_vote(string memory _candidate) public view returns (int) {
        return votes[_candidate];  
    }
    
}
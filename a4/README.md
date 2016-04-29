#CS372 Assignment 4
Impement a New Design Pattern

This repo contains an implementation of the Chain of Responsibility design pattern.  
The design is roughly based on the process by which a vending machine sorts and recognizes the coins it is given.  
All classes are defined in vend.hpp  


##Usage:
include vend.hpp  
create a VendingMachine object  
To add handlers to VendingMachine, use `VendingMachine::addCoinHandler ( CoinHandler * )`  
Add as many CoinHandlers as you need for your quantity of coins  
You __MUST__ add a DefaultCoinHandler as the last coin handler in your VendingMachine. If you neglect adding a DefaultCoinHandler your code's execution will be undefined and likely result in a Segmentation Fault.

Test coins in the VendingMachine with `VendingMachine::processCoin( int diameter, double weight)`  
For __valid coins__, a message with the value, diameter, and weight of the coin will be printed to the console.  For __invalid coins__, a rejection message with the diameter and weight of the coin will be printed to the console.
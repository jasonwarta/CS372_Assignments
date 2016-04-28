/*
 * vend.h
 * 4/27/2016
 * 
 * CS 372 Sp16
 * Assignment 4: Implementing a New Design Pattern
 * Chain of Responsibility design pattern
 * 
 * classes defined in this file:
 * 	VendingMachine
 * 	CoinHandler
 * 	DefaultCoinHandler
 * 	
 * 	
 * Usage:
 * include vend.h
 * create a VendingMachine object
 * add CoinHandler using VendingMachine::addCoinHandler ( CoinHandler * )
 * add DefaultCoinHandler using VendingMachine::addCoinHandler ( CoinHandler * )
 * test coins in your system with VendingMachine::processCoin ( int, weight )
 */

#ifndef VEND_H
#define VEND_H

#include <iostream>

class VendingMachine
{
public:
	VendingMachine(): child_(nullptr) {};

	virtual ~VendingMachine() { delete child_; } ;

	VendingMachine(VendingMachine & other) {
		delete child_;
		child_ = other.child_;
	};

	/**
	 * @brief handle a coin
	 * @details handle a coin by passing responsibility down the line to a child object
	 * 
	 * @param diameter coin diameter
	 * @param weight coin weight
	 */
	virtual void processCoin(int diameter, double weight){
		child_->processCoin(diameter,weight);
	};

	/**
	 * @brief add a coin handler
	 * @details add a pointer to a Coin handler to the VendingMachine
	 * 
	 * @param coin pointer to Coin object
	 */
	void addCoinHandler(VendingMachine *coin) {
		if(child_) child_->addCoinHandler(coin);
		else child_ = coin;
	};

private:
	VendingMachine *child_;

}; //end of class VendingMachine

class CoinHandler : public VendingMachine
{
public:
	CoinHandler() = delete;

	/**
	 * @brief CoinHandler constructor
	 * @details makes a CoinHandler object
	 * 
	 * @param d diameter of the coin
	 * @param wt weight of the coin
	 * @param val value of the coin
	 */
	CoinHandler(int d, double wt, double val): diameter_(d), weight_(wt), value_(val) {};

	/**
	 * @brief handle a coin
	 * @details print a message if coin is recognized, otherwise pass to next handler
	 * 
	 * @param diameter coin diameter
	 * @param weight coin weight
	 */
	void processCoin(int diameter, double weight){
		if(diameter == diameter_ && weight == weight_){
			std::cout.precision(2);
			std::cout << "Coin Accepted! Value: $" << std::fixed << value_ << "\n";
			std::cout << "Coin Size - Diameter: " << diameter << ", Weight: " << weight << "\n" << std::endl;
		} else {
			VendingMachine::processCoin(diameter,weight);
		}
	};

private:
	int diameter_;
	double weight_;
	double value_;

}; //end of class CoinHandler

class DefaultCoinHandler : public VendingMachine
{
public:
	/**
	 * @brief handle default case
	 * @details this is the end of the line. if a coin reaches this handler it is discarded
	 * 
	 * @param diameter coin diameter
	 * @param weight coin weight
	 */
	void processCoin(int diameter, double weight){
		std::cout << "Coin rejected. We couldn't find a match for that coin.\n";
		std::cout << "Coin Size - Diameter: " << diameter << ", Weight: " << weight << "\n" << std::endl;
	};
}; //end of class DefaultCoinHandler

#endif // VEND_H

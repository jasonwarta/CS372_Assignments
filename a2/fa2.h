/* 
 * fa2.h
 * Jason Warta
 * February 16, 2016
 * 
 * CS372 Sp16
 * Assignment 2
 */

#ifndef FA2_H_INCLUDED
#define FA2_H_INCLUDED

#include <vector>
using std::vector;
#include <random>
#include <functional>
using std::function;
#include <cstddef>
using std::size_t;
#include <future>

/* 
 * vector<double> normRand(size_t)
 * Pre : Takes a unsigned integer for vector size
 * Post: Produces a vector of the given size, populated with
 *       random numbers that fit a (100,15) normal distribution
 */
inline vector<double> normRand(size_t n){

	std::default_random_engine gen;
	std::normal_distribution<double> norm(100,15);
	
	vector<double> numbers;

	for(int i = 0; i < n; i++){
		numbers.push_back( norm(gen) );
	}

	return numbers;
}

/*
 * vector<int> asyncSquares(size_t)
 * Pre : Takes a unsigned integer for vector size
 * Post: Populates the vector with numbers such that
 *       the value at a given index is the square of the index
 */
inline vector<int> asyncSquares(size_t n){
	vector<int> squares;

	for(int i = 0; i < n; i++){
		squares.push_back( std::async(std::launch::async, [=]{ return i*i; }).get() );
	}

	return squares;
}

/*
 * function<int(int)> repeatFunction(function<int(int)>,int)
 * Pre : Takes a function object which takes an int and returns an int
 *       Takes a integer for the number of times to recursively call the passed function
 * Post: Returns a function that when called, will return the value you would expect
 *       if you called the original function, passing in its output, the specified number of times
 */
function<int(int)> repeatFunction(function<int(int)> func, int n){
	function<int(int)> newFunc = [=](int input){
		int temp = input;
		for(int i = 0; i < n; i++){
			temp = func(temp);
		}
		return temp;
	};
	return newFunc;
}

#endif
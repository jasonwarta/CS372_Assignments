#include "vend.hpp"

// simple struct to make USD objects for test code
struct USD {
	USD(int d,double wt,double val): d_(d),wt_(wt),val_(val) {};
	int d_; 			// diameter of coin	(millimeters)
	double wt_;		// weight of coin 	(grams)
	double val_;	// value of coin 		(USD)
};
	
// example code to demo VendingMachine and CoinHandler classes
void testVendingMachine(){
	// create multiple US coins
	// units meainingless, but these are the units I'm using:
	// units: diameter(mm), weight(g), value($)
	// these values were found on the US Mint website
	USD dollar	(26, 8.1, 1.00);
	USD quarter	(23, 5.7, 0.25);
	USD dime		(18, 2.3, 0.10);
	USD nickel 	(21, 5.0, 0.05);
	USD penny		(19, 2.5, 0.01);

	// create base VendingMachine object
	VendingMachine vendor;
	// add multiple CoinHandler handlers to the VendingMachine
	vendor.addCoinHandler(new CoinHandler(dollar.d_  , dollar.wt_  , dollar.val_));
	vendor.addCoinHandler(new CoinHandler(quarter.d_ , quarter.wt_ , dollar.val_));
	vendor.addCoinHandler(new CoinHandler(dime.d_    , dime.wt_    , dime.val_));
	vendor.addCoinHandler(new CoinHandler(nickel.d_  , nickel.wt_  , nickel.val_));
	vendor.addCoinHandler(new CoinHandler(penny.d_   , penny.wt_   , penny.val_));
	// add default handler
	// this MUST be added at the end of an object
	vendor.addCoinHandler(new DefaultCoin());

	vendor.processCoin(15,5.1);
	vendor.processCoin(26,8.1); //dollar
	vendor.processCoin(28,9.7);
	vendor.processCoin(21,5.0); //nickel
	vendor.processCoin(10,1.0);
	vendor.processCoin(19,2.5); //penny
	vendor.processCoin(26,8.7);
	vendor.processCoin(23,5.7); //quarter
	vendor.processCoin(18,2.5);
	vendor.processCoin(18,2.3); //dime
}

int main(int args, char *argv[]){
	// uncomment this function call to run the tests in the function testVendingMachine
	testVendingMachine();




	return 0;
}
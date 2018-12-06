/*
 * BarcodeArrayScanner.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: laurenkearney
 */
#include "Product.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main() {

//load file into array
	int count = 0;
	Product barcodeArray[100];
	ifstream file("upc_corpus.txt");
	string upc, info;
	while (getline(file, upc, ',') && getline(file, info) && count < 100) {
		Product product;
		product.info = info;
		stringstream convert(upc);
		if (convert >> product.upc) {
			barcodeArray[count] = product;
		}
		count++;
	}
//get upc to search for
	long input;
	cout << "search(upc): ";
	cin >> input;
	Product searchProduct;
	searchProduct.upc = input;

	// search
	clock_t t;
	t = clock();
	for (int i = 0; i < 100; i++) {
		Product product = barcodeArray[i];
		if (product == searchProduct)
			break;
	}
	t = clock() - t;
	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;


}

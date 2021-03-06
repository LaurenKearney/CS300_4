#include "BinarySearchTree.h"
#include "Product.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


int main(){
	int count = 0;
	BinarySearchTree<Product> barcodeBST;
	ifstream file("upc_corpus.txt");
	string upc, info;
	while (getline(file, upc, ',') && getline(file, info) && count<100000) {
		Product product;
		product.info=info;
		stringstream convert(upc);
		if (convert >> product.upc){
			barcodeBST.insert(product);
		}
		count++;
	}
	long input;
	cout << "search(upc): ";
	cin >> input;
	Product searchProduct;
	searchProduct.upc = input;

	// search
	clock_t t;
	t = clock();
	barcodeBST.search(searchProduct);
	t = clock() - t;
	cout << "time: " << t << " milliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;

}


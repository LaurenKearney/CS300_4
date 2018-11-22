#include "BinarySearchTree.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include<string>
#include <map>

using namespace std;

class Product{

	public:
		long upc;
		string info;
		friend ostream& operator<<(ostream& os, Product& prod) {
			os << prod.upc;
			return os;
		}
		friend bool operator>(Product& A, Product& B) {
			return A.upc>B.upc ;
		}
		friend bool operator<(Product& A, Product& B) {
			return A.upc<B.upc ;
		}
		friend bool operator>=(Product& A, Product& B) {
			return A.upc>=B.upc ;
		}
		friend bool operator<=(Product& A, Product& B) {
			return A.upc<=B.upc ;
		}
		friend bool operator==(Product& A, Product& B) {
			return A.upc==B.upc ;
		}
		friend bool operator!=(Product& A, Product& B) {
			return A.upc!=B.upc ;
		}
};


int main(){
	BinarySearchTree<Product> barcodeBST;
	ifstream file("upc_corpus.txt");
	string upc, info;
	while (getline(file, upc, ',') && getline(file, info)) {
		Product product;
		product.info=info;
		stringstream convert(upc);
		if (convert >> product.upc){
			barcodeBST.insert(product);
		}
	}
	barcodeBST.printInOrder();

}


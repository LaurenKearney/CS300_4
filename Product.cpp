#include "BinarySearchTree.h"
#include <iostream>

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

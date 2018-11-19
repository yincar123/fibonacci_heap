#include <iostream>
#include "fibonacci.cpp"

using namespace std;

int main(){
	fibonacci<int> carlos;

	carlos.insert(10);
	carlos.insert(12);
	carlos.insert(15);
	carlos.insert(16);
	carlos.insert(18);
	carlos.insert(9);
	carlos.insert(6);
	carlos.insert(23);
	carlos.insert(21);
	carlos.insert(13);
	carlos.insert(25);
	carlos.insert(26);
	carlos.deletemin();
	carlos.print();
	carlos.insert(8);
	carlos.insert(19);
	carlos.insert(33);
	carlos.deletemin();
//	carlos.deletemin();
	carlos.print();

	return 0;
}

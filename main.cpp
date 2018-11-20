#include <iostream>
#include "fibonacci.cpp"

using namespace std;

int main(){
	fibonacci<int> carlos;

	carlos.insert(15);
	carlos.insert(11);
	carlos.insert(2);
	carlos.insert(6);
	carlos.insert(108);
	carlos.insert(88);
	carlos.deletemin();
	carlos.insert(9);
	carlos.insert(38);
	carlos.insert(1);
	carlos.deletemin();
	carlos.insert(13);
	carlos.insert(25);
	carlos.insert(26);
	carlos.deletemin();
	carlos.insert(8);
	carlos.insert(19);
	carlos.insert(33);
	carlos.deletemin();
	carlos.deletemin();
	carlos.deletemin();
	//carlos.remove(26);
	carlos.print();

	return 0;
}

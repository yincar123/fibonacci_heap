#ifndef NODOB_H
#define NODOB_H
#include<list>

template<class T>
class nodob{
public:
	T date;
	int grade;
	int pos;
	nodob<T> *father;
	std::list<nodob<T>*> m_son;
public:
	nodob(){
		date=nullptr;
		father=nullptr;
		grade=nullptr;
	}
	nodob(T d){
		date=d;
		father=0;
		grade=0;
	}
};

#endif

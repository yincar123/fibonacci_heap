#ifndef FIBO_H
#define FIBO_H
#include "nodob.h"
#include <fstream>
#include <vector>
#include <iterator>

template<class T>
class fibonacci{
public:
	std::list<nodob<T>*> root;
	nodob<T> *min;
	int _size=0;
public:
	fibonacci(){};
	int size(){ return _size;};
	void insert(T d);
	void deletemin();
	void actualizar();
	void merge(std::vector<nodob<T>*> &v,nodob<T> *p);
	
	nodob<T>* _union(nodob<T> *p,nodob<T> *q);
	void actualizarmin();
	void remove(T d);
	bool find(T d,auto &p);
	bool findroot(T d,std::list<nodob<T>*> &son,nodob<T> **&p);
	void decresekey(nodob<T> **p);	
	void print();
	void print(std::list<nodob<T>*> son,int cont,std::ofstream &f);
};

#endif

#include "fibonacci.h"
#include <math.h>

template<class T>
void fibonacci<T>::insert(T d){
	nodob<T> *p_new=new nodob<T>(d);
	if(root.empty()){
		root.push_back(p_new);
		min=p_new;
	}
	else{
		auto p=root.begin();
		if(find(min->date,p)){
			if(min->date >= d){
				min=p_new;
				root.insert(p,p_new);
			}
			else{
				root.insert(p,p_new);
			}
		}
	}
	_size++;
}

template<class T>
bool fibonacci<T>::find(T d,auto &it){
	while(it!=root.end()){
		if((*it)->date==d){
			return 1;
		}
		++it;
	}
	return 0;
}

template<class T>
void fibonacci<T>::deletemin(){
	auto p=root.begin();
	find(min->date,p);

	auto it=(*p)->m_son.begin();
	while(it!=(*p)->m_son.end()){
		(*it)->father=0;
		++it;
	}
	if((*p)->m_son.begin()!=(*p)->m_son.end()){
		root.insert(p,(*p)->m_son.begin(),(*p)->m_son.end());
	}
	root.erase(p);
	_size--;
	actualizar();
}

template<class T>
void fibonacci<T>::actualizar(){
	auto it=root.begin();
	std::vector<nodob<T>*> temp(ceil(log(_size))+1); 
	while(it!=root.end()){
		merge(temp,*it);
		++it;
	}
	root.clear();
	for(int i=0;i<temp.size();++i){
		if(temp[i]!=0){
			root.push_back(temp[i]);
		}
	}
	actualizarmin();
}

template<class T>
void fibonacci<T>::actualizarmin(){
	auto it=root.begin();
	min=*it;
	while(it!=root.end()){
		if(min->date > (*it)->date){
			min=(*it);
		}
		++it;
	}
}

template<class T>
void fibonacci<T>::merge(std::vector<nodob<T>*> &v,nodob<T> *p){
	int po=p->grade;
	if(v[po]==0){
		v[po]=p;
	}	
	else{
		auto q=_union(p,v[po]);
		v[po]=0;
		merge(v,q);
	}
}

template<class T>
nodob<T>* fibonacci<T>::_union(nodob<T> *p,nodob<T> *q){
	if(p->date > q->date){
		q->grade++;
		p->father=q;
		q->m_son.push_front(p);
		return q;
	}
	else{
		p->grade++;
		q->father=p;
		p->m_son.push_front(q);
		return p;
	}
}

template<class T>
bool fibonacci<T>::findroot(T d,std::list<nodob<T>*> &son,nodob<T> **&p){
	auto iter=son.begin();
	while(iter!=son.end()){
		if((*iter)->date==d){
			p=&(*iter);
			return 1;
		}
		if(findroot(d,(*iter)->m_son,p)){
			return 1;
		}
		++iter;
	}
	return 0;
}

template<class T>
void fibonacci<T>::decresekey(nodob<T> **p){
	auto q=min->date-1;
	while((*p)->father){
		(*p)->date=(*p)->father->date;
		(*p)->father->date=q;
		p=&(*p)->father;
	}
}

template<class T>
void fibonacci<T>::remove(T d){
	nodob<T> **p;
	if(findroot(d,root,p)){
		decresekey(p);
		actualizarmin();
		deletemin();
	}
}


template<class T>
void fibonacci<T>::print(){
	std::ofstream file("fibonacci.dot");
	file<<"digraph{"<<std::endl;
	auto it=root.begin();
	int cont=1;
	while(it!=root.end()){
		file<<(*it)->date<<std::endl;
		print((*it)->m_son,cont,file);
		++it;
	}
	file<<"minimo ->"<<min->date<<";"<<std::endl;
	file<<"}";
	file.close();
	system("dot -Tpdf fibonacci.dot -o fibonacci.pdf");
}

template<class T>
void fibonacci<T>::print(std::list<nodob<T>*> son,int cont,std::ofstream &file){
	auto it=son.begin();
	while(it!=son.end()){
		file<<(*it)->father->date<<" ->";
		file<<(*it)->date<<";"<<std::endl;
		print((*it)->m_son,cont+1,file);
		++it;
	}
}

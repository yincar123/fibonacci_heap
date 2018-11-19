#include "fibonacci.h"
#include <math.h>

template<class T>
void fibonacci<T>::insert(T d){
	nodob<T> *p_new=new nodob<T>(d);
	if(root.empty()){
		p_new->pos=0;
		root.push_back(p_new);
		min=p_new;
	}
	else{
		int pos1=min->pos;
		auto it=root.begin();
		int j=pos1;
		while(j>0){
			++it;
			j--;
		}
		if(p_new->date <= min->date){
			p_new->pos=pos1;
			min=p_new;
			root.insert(it,p_new);
		}
		else{
			min->pos+=1;
			root.insert(it,p_new);
		}
	}
	_size++;
}

template<class T>
void fibonacci<T>::deletemin(){
	auto pos1=min->pos;
	auto it=root.begin();
	while(pos1!=0){
		++it;
		--pos1;
	}
	auto iter=(*it)->m_son.begin();
	if((iter!=(*it)->m_son.end())){
		root.insert(it,iter,(*it)->m_son.end());
	}
	root.erase(it);
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
	int count=0;
	while(it!=root.end()){
		if(min->date > (*it)->date){
			min=(*it);
			min->pos=count;
		}
		count++;
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

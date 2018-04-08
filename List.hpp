#include <cstdio>

#ifndef LIST_HPP
#define LIST_HPP

template <class T>
class Node{
public :
	// ctor
	Node(); // membuat node dengan value default dari T
	Node(const T&); // membuat node dengan value
	//getter
	T getVal() const; // mendapatkan value node yang ada
	T* getRef();
	Node<T>* getNext() const; // mendapatkan address next
	//setter
	void setNext(Node<T>*); // menge-set address next;
	void setValue(const T&) const; // meng-set node dengan value baru
private :
	T val; // nilai node/elemen
	Node<T>* next; // node selanjutnya
};

template <class T>
class List{
public :
	//ctor
	List(); // membuat list kosong
	List(const T&);	// membuat list dengan 1 elemen
	//cctor
	List(const List&); // meng-copy semua elemen list L
	//dtor
	~List(); // menghapus semua yang di alokasi di List
	
	//method lain-lain
	int find(const T&) const; // mencari indeks dimana elemen yang dicari berada, -1 jika tidak ada
	bool isEmpty() const; // mengeluarkan true jika node==NULL
	void add(const T&); // menambah elemen ke akhir List
	void addFirst(const T&); // menambah elemen ke awal List
	void remove(const T&); // menghapus satu elemen dengan nilai tertentu
	void removeIdx(int idx);
	T delFirst(); // menghapus element pertama dan mengembalikkan nilainya
	T delLast(); // menghapus elemen terakhir dan mengembalikkan nilainya
	T get(int idx) const; // ambil nilai di indeks idx (asumsi idx benar)
	T* getRef(int idx);
private :
	Node<T> *node; // node yang ada
};

template<class T>
Node<T>::Node():val(){
	next = NULL;
}

template<class T>
Node<T>::Node(const T& tval):val(tval){
	next = NULL;
}

template<class T>
T Node<T>::getVal() const
{
	return val;
}

template<class T>
T* Node<T>::getRef()
{
	return &val;
}

template<class T>
Node<T>* Node<T>::getNext() const{
	return next;
}

template<class T>
void Node<T>::setNext(Node<T>* tnext){
	next = tnext;
}

template<class T>
void Node<T>::setValue(const T& tval) const{
	val = tval;
}

template<class T>
List<T>::List(){
	node = NULL;
}

template<class T>
List<T>::List(const List& L){
	Node<T>* nl = L.node;
  while(nl!=NULL){
  	add(nl.getVal());
    nl = nl.getNext();
  }
}

template<class T>
List<T>::List(const T& temp){
	node = new Node<T>(temp);
}

template<class T>
List<T>::~List(){
	Node<T>* now = node;
	if(now!=NULL){
		Node<T>* next = now->getNext();
		while(next!= NULL){
			delete now;
			now = next;
			next = now->getNext();
		}
		delete now;
	}	
}

template<class T>
int List<T>::find(const T& tval) const{
	Node<T> *temp = node;
	int i=0;
	while(temp!= NULL){
		if(temp->getVal() == tval)
			return i;
		temp = temp->getNext();
		i++;
	}
	return -1;
}

template<class T>
bool List<T>::isEmpty() const{
	return node == NULL;
}

#include<iostream>
using namespace std;

template<class T>
void List<T>::add(const T& tval){
	if(node==NULL){
		node = new Node<T>(tval);
		return;
	}
	Node<T> *temp = node;
	while(temp->getNext() != NULL){
		temp  = temp->getNext();
	}
	temp->setNext(new Node<T>(tval));
}

template<class T>
void List<T>::addFirst(const T& tval){
	if(node == NULL){
		node = new Node<T>(tval);
		return;
	}
	Node<T> *temp = new Node<T>(tval);
	temp->setNext(node);
	node = temp;
}

template<class T>
void List<T>::remove(const T& tval){
	Node<T> *temp = node;
	if(temp==NULL){
		return;
	}
	if(temp->getVal() == tval){
		node = node->getNext();
		delete temp;
		return;
	}
	while(temp->getNext()!=NULL&& !(temp->getNext()->getVal() == tval)){
		temp = temp->getNext();
	}
	if(temp->getNext() !=NULL){
		Node<T> *del = temp->getNext();
		temp->setNext(del->getNext());
		delete del;
	}
}

template<class T>
void List<T>::removeIdx(int idx){
	Node<T> *temp = node, *prev = NULL;
	if(idx==0){
		node = node->getNext();
		delete temp;
		return;
	}
	while(temp->getNext() != NULL&& idx>1){
		temp = temp->getNext();
		idx--;
	}
	if(temp->getNext() != NULL){
		Node<T> *del = temp->getNext();
		temp->setNext(del->getNext());
		delete del;
	}
}

template<class T>
T List<T>::delFirst(){
	T a = node->getVal();
	Node<T>* del = node;
	node = node->getNext();
	delete del;
	return a;
}

template<class T>
T List<T>::delLast(){
	if(node->getNext()==NULL){
		T a = node->getVal();
		delete node;
		node = NULL;
		return a;
	}
	Node<T>* del = node;
	while(del->getNext()->getNext() !=NULL){
		del = del->getNext();
	}
	Node<T>* ndel = del->getNext();
	T a = ndel->getVal();
	delete ndel;
	del->setNext(NULL);
	return a;
}

template<class T>
T List<T>::get(int idx) const{
	Node<T> *temp = node;
	while(idx>0){
		temp = temp->getNext();
		idx--;
	}
	return temp->getVal();
}

template<class T>
T* List<T>::getRef(int idx){
	Node<T> *temp = node;
	while(idx>0){
		temp = temp->getNext();
		idx--;
	}
	return temp->getRef();	
}

#endif

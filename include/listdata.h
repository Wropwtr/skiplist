#pragma once

#include<iostream>

using namespace std;

template <class TData>
class ListNode{
public:
	int key;
	TData *data;
	ListNode<TData>* next;

	ListNode(int key, TData *&data) { this->key = key; this->data = data; next = 0;}
	ListNode(){ data = 0; next = 0;}
	~ListNode(){}
};

template <class TData>
class List{
	ListNode<TData>* pFirst;
public:
	List();
	List(const List &l);
	~List();

	void show() const;
	ListNode<TData>* search(int key) const;
	void insert(int key, TData *&data);
	void ins(int key, TData *&data);
	void erase(int key);

	ListNode<TData>* getFirst(); 
};

template <class TData>
List<TData>::List(){
	pFirst = 0;
}

template <class TData>
List<TData>::List(const List &l){
	if ( pFirst == l.pFirst ) 
		return;
	pFirst = 0;
	if ( &l == 0 || l.pFirst == 0 )
		return;

	ListNode<TData> *buf2;
	ListNode<TData> *iterator = l.pFirst;

	ListNode<TData>* buf1 = new ListNode<TData>(iterator->key, iterator->data);
	pFirst = buf1;

	iterator =  iterator->next;	
	while ( iterator ){
		buf2 = buf1;
		buf1 = new ListNode<TData>(iterator->key, iterator->data);
		buf2->next = buf1;
		iterator =  iterator->next;	
	}
}

template <class TData>
List<TData>::~List(){
	ListNode<TData>* buf;
	while ( pFirst ){
		buf = pFirst;
		pFirst = pFirst->next;
		delete buf;
	}
}

template <class TData>
void List<TData>::show() const {
	if ( !pFirst ){
		cout << "\tList is empty\n";
		return;
	} 
	ListNode<TData>* buf = pFirst;
	while ( buf ){
		cout << "key: " << buf->key << " data: " << buf->data << endl;
		buf = buf->next;
	}
}

template <class TData>
ListNode<TData>* List<TData>::search(int key) const {
	if ( !pFirst )
		return 0;

	ListNode<TData>* buf = pFirst;
	while ( buf && (buf->key != key) ){
		buf = buf->next;
	}
	if ( buf == 0 ) return 0;
	return buf;
}

template <class TData>
void List<TData>::insert(int key, TData *&data){
	ListNode<TData>* buf = new ListNode<TData>(key, data);
	buf->next = pFirst;
	pFirst = buf;
} // Insert before firsts

template <class TData>
void List<TData>::ins(int key, TData *&data){
	if (!pFirst || pFirst->key > key){
		insert(key, data);
		return;
	}

    // вставляем перед элементом с ключом, большим key
	ListNode<TData>* buf = pFirst;
	while ( buf->next && (buf->next->key < key) ){
		buf = buf->next;
    }

    if(buf->next == 0){
        ListNode<TData>* newNode = new ListNode<TData>(key, data);
        buf->next = newNode;
        return;
    }// вставляем после последнего

    if((buf->next)->key == key)
        return; // already exist

	ListNode<TData>* newNode = new ListNode<TData>(key, data);
	newNode->next = buf->next;
	buf->next = newNode;
	return;
}

template <class TData>
void List<TData>::erase(int key){
	if ( !pFirst ){
		//throw "List is empty\n";
		return;
	} 
	ListNode<TData> *buf = pFirst;
	if ( pFirst->key == key ){
		pFirst = pFirst->next;
		delete buf;
		return;
	} // Delete first element
	while ( buf->next && buf->next->key < key){
		buf = buf->next;
	} // Search element
	if ( !buf->next || buf->next->key != key) return;
	ListNode<TData> *tmp = buf->next;
	buf->next = tmp->next;
	delete tmp;
	return;
}

template <class TData>
ListNode<TData>* List<TData>::getFirst(){
	return pFirst;
}


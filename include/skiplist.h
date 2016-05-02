#pragma once
#include <iostream>
#include <climits> //INT_MAX
#include <time.h> 
#include "node.h"
#include <cstdlib>
#include <stdlib.h>

using namespace std;

//recommended number of elements ~(1 / PROBABILITY) ^ MAX_LEVEL = 128

template <class TData>
class SkipList{
private:
	Node<TData> *header;
	int MAXLEVEL;
	float probability;
	int size;
    Node<TData> *iterator;
public:
	SkipList(int maxlevel, float p);
	~SkipList();

	int randomLevel();
    Node<TData>* find(int key);
    void insert(int key, TData *&data);
	void remove(int key);

	void show();
	void showLevels();

    int getPosition(int key);

    Node<TData>* getCurrent() { return iterator; }
    void goNext(){ if(iterator) iterator = iterator->forward->at(0); }
    void reset(){ iterator = header; }
    int getSize(){ return size; }

	int isEmpty(){ return (size == 0 && header == 0); }
};

template <class TData>
SkipList<TData>::SkipList(int maxlevel, float p){
	time_t  timev;
	time(&timev);
	srand((int)timev);

	MAXLEVEL = maxlevel;
	header = 0;
	probability = (float)(p < 1.0 && p > 0.0) ? p : 0.5;
	size = 0;
}

template <class TData>
SkipList<TData>::~SkipList(){
	Node<TData> *x = header;
	Node<TData> *buffer = header;
	while (x){
		x = x->forward->at(0);
		delete buffer;
		buffer = x;
	}
}

template <class TData>
int SkipList<TData>::randomLevel(){
	int level = 1;
    while (level < MAXLEVEL && ((double)rand() / (RAND_MAX)) < probability){
		level++;
    }
	return level;
}

template <class TData>
Node<TData>* SkipList<TData>::find(int key){
	Node<TData> *x = header;
	if (size == 0) 
		return 0;
    if (header->key == key)
        return header;
	for (int i = MAXLEVEL - 1; i >= 0; i--){
        while (x->forward->at(i) && ((x->forward->at(i))->key < key))
            x = x->forward->at(i);
	}
	x = x->forward->at(0);
    if (x != 0 && x->key == key) return x;
	return 0;
}

template <class TData>
int SkipList<TData>::getPosition(int key){
    if (size == 0)
        return -1;
    if(header->key == key)
        return 0;
    reset();
    int position = 0;
    while(getCurrent() != 0){
        if(iterator->key == key)
            return position;
        if(iterator->key > key)
            return -1;
        goNext();
        position++;
    }
    return -1;
}

template <class TData>
void SkipList<TData>::insert(int key, TData *&data){
	if (size == 0){
		header = new Node<TData>(data, key, MAXLEVEL);
		size++;
        return;
	}
	if (key < header->key){
        Node<TData> *x = header;
        header = new Node<TData>(data, key, MAXLEVEL);

        int new_lvl = randomLevel();
        Node<TData> *new_node = new Node<TData>(x->data, x->key, new_lvl);

        for (int i = new_lvl; i < MAXLEVEL; i++)
            header->forward->at(i) = x->forward->at(i);
        for (int i = 0; i < new_lvl; i++){
            header->forward->at(i) = new_node;
            new_node->forward->at(i) = x->forward->at(i);
        }
        delete x;
        size++;
        return;
	}// вставка перед первым
	vector<Node<TData>*> *update = new vector<Node<TData>*>(MAXLEVEL);
	Node<TData> *x = header;
	for (int i = MAXLEVEL - 1; i >= 0; i--){
        while (x->forward->at(i)!=0 && (x->forward->at(i))->key < key )
            x = x->forward->at(i);
		update->at(i) = x;
	}
	if (x->forward->at(0) == 0){
		int newLevel = randomLevel();
		Node<TData> *newNode = new Node<TData>(data, key, newLevel);
		for (int i = 0; i < newLevel; i++){
			update->at(i)->forward->at(i) = newNode;
		}
		delete update;
		size++;
        return;
	}// вставка после последнего
	x = x->forward->at(0);
	if (x->key == key)
        return; // key is already exist

	int newLevel = randomLevel();
	Node<TData> *newNode = new Node<TData>(data, key, newLevel);
	for (int i = 0; i < newLevel; i++){
		newNode->forward->at(i) = update->at(i)->forward->at(i);
		update->at(i)->forward->at(i) = newNode;
	}
	delete update;
    size++;
}

template <class TData>
void SkipList<TData>::remove(int key){
	if (size == 0)
		throw "List is empty.";
	if (size == 1){
		delete header;
		header = 0;
		size = 0;
		return;
	}
	if (header->key == key){
		Node<TData> *next = header->forward->at(0);
		Node<TData> *newNode = new Node<TData>(next->data, next->key, MAXLEVEL);
		for (int i = 0; i < next->level; i++)
			newNode->forward->at(i) = next->forward->at(i);
		for (int i = next->level; i < MAXLEVEL; i++)
			newNode->forward->at(i) = header->forward->at(i);
		header = newNode;
		delete next;
		size--;
		return;
	}
	vector<Node<TData>*> *update = new vector<Node<TData>*>(MAXLEVEL);
	Node<TData> *x = header;
	for (int i = MAXLEVEL - 1; i >= 0; i--){
		while (x->forward->at(i) && (x->forward->at(i))->key < key)
			x = x->forward->at(i);
		update->at(i) = x;
	}
	x = x->forward->at(0);
	if (x == 0 || x->key != key){
		delete update;
		return;
	}
	for (int i = 0; i < x->level; i++){
		if (update->at(i)->forward->at(i) != x)
			break;
		update->at(i)->forward->at(i) = x->forward->at(i);
	}
	delete x;
	delete update;
	size--;
}

template <class TData>
void SkipList<TData>::show(){
	if (size == 0)
		throw "List is empty";
	Node<TData> *x = header;
	while (x){
		cout << "key: " << x->key << " data: " << x->data << endl;
		x = x->forward->at(0);
	}
}

template <class TData>
void SkipList<TData>::showLevels(){
	if (size == 0)
		throw "List is empty";
	Node<TData> *x = header;
	while (x){
		cout << "key: " << x->key << " level: " << x->level << endl;
		x = x->forward->at(0);
	}
}

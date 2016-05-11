#pragma once
#include "skiplist.h"

template <class TData>
class SkipTable{
protected:
    Node<TData> *iterator;
    SkipList<TData> *slist;
public:
    void insert(int key, TData *&data) {slist->insert(key,data); reset(); }
    void remove(int key) {slist->remove(key); reset();}
    Node<TData>* find(int key){ return slist->find(key); }
    SkipTable(int maxlevel, float p){slist = new SkipList<TData>(maxlevel, p); iterator = 0;}
    ~SkipTable(){ delete slist; if(!iterator) delete iterator; }
	int getPosition(int key);
    Node<TData>* getCurrent(){ return iterator; }
    void goNext(){ if(iterator) iterator = iterator->forward->at(0); }
    void reset(){ iterator = slist->header; }
    int getSize(){ return slist->size; }
    int isEmpty(){ return slist->isEmpty(); }
};

template <class TData>
int SkipTable<TData>::getPosition(int key){
    if (slist->size == 0)
        return -1;
    if((slist->header)->key == key)
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


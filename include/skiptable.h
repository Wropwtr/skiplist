#pragma once
#include "skiplist.h"

template <class TData>
class SkipTable: public SkipList<TData>{
protected:
    Node<TData> *iterator;
public:
    SkipTable(int maxlevel, float p) : SkipList<TData>(maxlevel, p) {}
	int getPosition(int key);
    Node<TData>* getCurrent() { return iterator; }
    void goNext(){ if(iterator) iterator = iterator->forward->at(0); }
    void reset(){ iterator = SkipList<TData>::header; }
    int getSize(){ return (SkipList<TData>::size); }
};

template <class TData>
int SkipTable<TData>::getPosition(int key){
    if (SkipList<TData>::size == 0)
        return -1;
    if((SkipList<TData>::header)->key == key)
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


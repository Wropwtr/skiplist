#pragma once
#include <vector>
using namespace std;

template <class TData>
class Node{
	//friend class SkipList<TData>;
	//protected:
public:
    int key;
	int level;
	TData *data;
	vector<Node<TData>*> *forward;
	Node(TData *&dat, int newKey = 0, int nodeLevel = 0);
	Node(const Node<TData> *&n);
	~Node();
};

template <class TData>
Node<TData>::Node(const Node<TData> *&n){
	forward = new vector<Node<TData>*>(n->level);
	level = n->level;
	for (int i = 0; i < level; i++)
		forward[i] = n->forward[i];
	key = n->key;
	data = n->data;
}

template <class TData>
Node<TData>::Node(TData *&dat, int newKey, int nodeLevel){
	key = newKey;
	data = dat;
	level = nodeLevel;
	forward = new vector<Node<TData>*>(level);
}

template <class TData>
Node<TData>::~Node(){
	delete forward;
}

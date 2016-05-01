#include <iostream>
#include "../../include/skiplist.h"
#include <stdlib.h>

int main(){
    SkipList<char> *list = new SkipList<char>(4, 0.5f);

    cout << "Show empty list: ";
    try{
        list->show();
    }
    catch (...){
        cout << "List is empty.\n";
    }

    cout << "\nInsert 1, 3, 2 and show:\n";
    char *a = "data1";
    char *b = "data3";
    char *c = "data2";
    list->insert(1, a);
    list->insert(3, b);
    list->insert(2, c);
    list->show();

    cout << "\n\nShow levels:\n";
    list->showLevels();

    cout << "\n\nShow levels:\n";
    list->showLevels();

    cout << "\n\nFind 2:\n";
    Node<char> *x = list->find(2);
    if (x == 0)
        cout << "Sorry, but x is not in list\n";
    else
        cout << "key: " << x->key << "data: " << x->data << endl;


    cout << "\n\nRemove 2 and show:\n";
    list->remove(2);
    list->show();

    cout << "\n\nRemove 1 and show:\n";
    list->remove(1);
    list->show();

    cout << "\n\nRemove 3 and show:\n";
    list->remove(3);
    try{
        list->show();
    }
    catch (...){
        cout << "List is empty.\n";
    }

    delete list;
    return 0;
}

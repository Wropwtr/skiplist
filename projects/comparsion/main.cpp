#include <iostream>
#include "../../include/skiplist.h"
#include "../../include/listdata.h"
#include <stdlib.h>
#include <ctime>

using namespace std;

//#define NELEMS 128
#define NELEMS 10000

int main(){
    volatile int key;
    int *a = new int;
    *a = 0;
    srand(time(NULL));

    List<int> *list = new List<int>();
    for (int i = 0; i < NELEMS; i++){
        int r = rand();
        list->ins(r, a);
    }
    clock_t begin = clock();
    for (int i = 0; i < 1000; i++){
        key = ((int)rand() % NELEMS);
        list->search(key);
    }
    clock_t end = clock();
    double elapsed_secs_list = double(end - begin) / CLOCKS_PER_SEC;

    SkipList<int> *slist = new SkipList<int>(18, 0.5f);
    for (int i = 0; i < NELEMS; i++){
        int r = rand();
        slist->insert(r, a);
    }
    begin = clock();
    for (int i = 0; i < 1000; i++){
        key = ((int)rand() % NELEMS);
        slist->find(key);
    }
    end = clock();
    double elapsed_secs_slist = double(end - begin) / CLOCKS_PER_SEC;
    cout << "For " << NELEMS << " elements" << endl;
    cout << "list search time: " << elapsed_secs_list << endl;
    cout << "skiplist search time: " << elapsed_secs_slist << endl;
    cout << endl;

    delete list;
    delete slist;
    delete a;
}

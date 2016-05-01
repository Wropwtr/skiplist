#include <iostream>
#include "../../include/skiplist.h"
#include "../../include/listdata.h"
#include <stdlib.h>
#include <ctime>

using namespace std;

#define NELEMS 16384

int main(){
    List<int> *list = new List<int>();
    SkipList<int> *slist = new SkipList<int>(14, 0.5f); // for 2^14 = NELEMS
    int *a = new int;
    *a = 2345;
    double no_cache = 0;

    srand(time(NULL));

    /*for (int i = 0; i < NELEMS; i++){
        list->ins(i, a);
        slist->insert(i, a);
    }*/

    for (int i = 0; i < NELEMS; i++){
        int r = rand();
        list->ins(r, a);
        slist->insert(r, a);
    }

    /*for (int i = NELEMS; i > 0; i--){
            list->ins(i, a);
            slist->insert(i, a);
        }*/

    volatile int key;
    for (int nmeasures = 1; nmeasures <= 5; nmeasures++){
        clock_t begin = clock();
        for (int i = 0; i < 10000; i++){
            key = ((int)rand() % NELEMS);
            list->search(key);
            no_cache += (double)rand() / (RAND_MAX);
        }
        clock_t end = clock();
        double elapsed_secs_list = double(end - begin) / CLOCKS_PER_SEC;

        begin = clock();
        for (int i = 0; i < 10000; i++){
            key = ((int)rand() % NELEMS);
            slist->find(key);
            no_cache += (double)rand() / (RAND_MAX);
        }
        end = clock();
        double elapsed_secs_slist = double(end - begin) / CLOCKS_PER_SEC;

        cout << "list search time: " << elapsed_secs_list << endl;
        cout << "skiplist search time: " << elapsed_secs_slist << endl;
        cout << endl;
    }
    getchar();
    slist->showLevels();
    slist->insert((int)no_cache,a);

    delete list;
    delete slist;
    delete a;
}

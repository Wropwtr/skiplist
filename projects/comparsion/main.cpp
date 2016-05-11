#include <iostream>
#include "../../include/skiplist.h"
#include "../../include/listdata.h"
#include <stdlib.h>
#include <ctime>

using namespace std;

int main(){
    volatile int key;
    int *a = new int;
    *a = 0;
    srand(time(NULL));
    int nums[6] = {128, 512, 2000, 8000, 20000,50000};
    int levels[6] = {7,9,11,14,15,16};
    for (int k = 0; k < 6; k++){
        int NELEMS = nums[k];
        List<int> *list = new List<int>();
        for (int i = 0; i < NELEMS; i++){
            list->ins(i, a);
        }
        clock_t begin = clock();
        for (int i = 0; i < 10000; i++){
            key = ((int)rand() % NELEMS);
            list->search(key);
        }
        clock_t end = clock();
        double elapsed_secs_list = double(end - begin)/10000/CLOCKS_PER_SEC;

        SkipList<int> *slist = new SkipList<int>(levels[k], 0.5f);
        for (int i = NELEMS; i > 0; i--){
            slist->insert(i, a);
        }
        begin = clock();
        for (int i = 0; i < 10000; i++){
            key = ((int)rand() % NELEMS);
            slist->find(key);
        }
        end = clock();
        double elapsed_secs_slist = double(end - begin)/10000/CLOCKS_PER_SEC;
        cout << "For " << NELEMS << " elements" << endl;
        cout << "list search time:     ";
        printf("%0.7lf\n",elapsed_secs_list);
        cout << "skiplist search time: ";
        printf("%0.7lf\n",elapsed_secs_slist);

        delete list;
        delete slist;
        delete a;
    }
    cout << "\n[ms]";
}

#include "skiplist.h"
#include "listdata.h"
#include <ctime>

using namespace std;

#define NELEMS 16384

int main(){
	List<int> *list = new List<int>();
	SkipList<int> *slist = new SkipList<int>(14, 0.5f); // for 2^14 = NELEMS
	int *a = new int;
	*a = 2345;

	srand(time(NULL));

	for (int i = 0; i < NELEMS; i++){
		list->ins(i, a);
		slist->insert(i, a);
	}
	volatile int key;
	for (int nmeasures = 1; nmeasures <= 5; nmeasures++){
		clock_t begin = clock();
		for (int i = 0; i < 10000; i++){
			key = ((int)rand() % NELEMS);
			list->search(key);
		}
		clock_t end = clock();
		double elapsed_secs_list = double(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		for (int i = 0; i < 10000; i++){
			key = ((int)rand() % NELEMS);
			slist->find(key);
		}
		end = clock();
		double elapsed_secs_slist = double(end - begin) / CLOCKS_PER_SEC;

		cout << "list search time: " << elapsed_secs_list << endl;
		cout << "skiplist search time: " << elapsed_secs_slist << endl;
		cout << endl;
	}

	delete list;
	delete slist;
	delete a;
}
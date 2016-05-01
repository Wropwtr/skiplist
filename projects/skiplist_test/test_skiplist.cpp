#include "../../gtests/gtest.h"
#include "../../include/skiplist.h"

TEST(SkipList, can_create_list)
{
	ASSERT_NO_THROW(SkipList<int> *list = new SkipList<int>(4, 0.5f););
}

TEST(SkipList, random_is_random)
{
	SkipList<int> *list = new SkipList<int>(5, 0.5f);
	int *randomLevels = new int[100];
	int maxRand = 0;
	for (int i = 0; i < 100; i++){
		int lvl = list->randomLevel();
		if (lvl > maxRand){
			maxRand = lvl;
		}
	}
	EXPECT_EQ(maxRand,5);
}

TEST(SkipList, throw_then_show_empty_list)
{
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	ASSERT_ANY_THROW(list->show());
}

TEST(SkipList, throw_then_show_levels_in_empty_list)
{
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	ASSERT_ANY_THROW(list->showLevels());
}

TEST(SkipList, find_nothing_in_empty_list){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	ASSERT_FALSE(list->find(2));
}

TEST(SkipList, throw_then_remove_from_empty_list){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	ASSERT_ANY_THROW(list->remove(2));
}

TEST(SkipList, can_insert_first_element){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	ASSERT_NO_THROW(list->insert(0, a));
}

TEST(SkipList, can_find_in_list_with_one_element){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(0, a);
	EXPECT_EQ(a, list->find(0)->data);
}

TEST(SkipList, can_insert_after_first_element){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int, *b = new int;
	*a = 5;
	*b = 6;
	list->insert(1, a);
	list->insert(2, b);
	ASSERT_TRUE(list->find(2));
}

TEST(SkipList, can_insert_before_first_element){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int, *b = new int;
	*a = 5;
	*b = 6;
	list->insert(2, a);
	list->insert(1, b);
	ASSERT_TRUE(list->find(1));
}

TEST(SkipList, find_nothing_if_key_not_in_list){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int, *b = new int;
	*a = 5;
	*b = 6;
	list->insert(2, a);
	list->insert(1, b);
	ASSERT_FALSE(list->find(3));
}

TEST(SkipList, can_remove_then_one_element){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(2, a);
	list->remove(2);
	ASSERT_FALSE(list->find(2));
}

TEST(SkipList, can_remove_second_element){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(2, a);
	list->insert(3, a);
	list->remove(3);
	ASSERT_FALSE(list->find(3));
}

TEST(SkipList, can_remove_first_element){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(2, a);
	list->insert(3, a);
	list->remove(2);
	ASSERT_FALSE(list->find(2) || !list->find(3));
}

TEST(SkipList, can_insert_and_find_on_places_12312){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(2, a);
	list->insert(4, a);
	list->insert(5, a);
	list->insert(1, a);
	list->insert(3, a);
	ASSERT_TRUE(list->find(3));
}

TEST(SkipList, can_remove_all_1){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(2, a);
	list->insert(4, a);
	list->insert(5, a);
	list->insert(1, a);
	list->insert(3, a);
	for (int i = 1; i <= 5; i++)
		list->remove(i);
	ASSERT_TRUE(list->isEmpty());
}

TEST(SkipList, can_remove_all_2){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(2, a);
	list->insert(4, a);
	list->insert(5, a);
	list->insert(1, a);
	list->insert(3, a);

	list->remove(5);
	list->remove(3);
	list->remove(2);
	list->remove(4);
	list->remove(1);
	ASSERT_TRUE(list->isEmpty());
}

TEST(SkipList, can_remove_all_3){
	SkipList<int> *list = new SkipList<int>(4, 0.5f);
	int *a = new int;
	*a = 5;
	list->insert(5, a);
	list->insert(4, a);
	list->insert(3, a);
	list->insert(2, a);
	list->insert(1, a);

	list->remove(5);
	list->remove(4);
	list->remove(3);
	list->remove(2);
	list->remove(1);
	ASSERT_TRUE(list->isEmpty());
}



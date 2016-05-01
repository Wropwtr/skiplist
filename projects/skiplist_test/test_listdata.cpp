#include <../../gtests/gtest.h>
#include "../../include/listdata.h"

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> *l1 = new List<int>());
}

TEST(List, can_copy_list)
{
	List<int> *l1 = new List<int>();
	int *a = new int;
	*a = 5;
	l1->ins(5,a);
	l1->ins(346, a);

	List<int> *l2 = new List<int>(*l1);
	EXPECT_EQ((l1->getFirst() != l2->getFirst() && l1->getFirst()->key == l2->getFirst()->key), true);
}

TEST(List, return_first_0_in_empty_stack)
{
	List<int> *l = new List<int>();
	EXPECT_EQ(0, l->getFirst());
}


TEST(List, can_insert_before_first)
{
	List<int> *l = new List<int>();
	int *a = new int;
	*a = 5;
	ASSERT_NO_THROW(l->ins(56, a));
}

TEST(List, can_show_first_element)
{
	List<int> *l = new List<int>();
	int *a = new int;
	*a = 5;
	l->ins(5, a);
	ListNode<int>* buf = l->getFirst();
	EXPECT_EQ(buf->key, 5);
}

TEST(List, can_insert_after_element_with_key)
{
	List<int> *l = new List<int>();
	int *a = new int;
	*a = 5;

	l->ins(5, a);
	l->ins(7, a);
	EXPECT_EQ((l->search(7))->key, 7);
}


TEST(List, can_insert_before_element_with_key)
{
	List<int> *l = new List<int>();

	int *a = new int;
	*a = 5;

	l->ins(7, a);
	l->ins(5, a);
	EXPECT_EQ(7, (l->search(7))->key);
}

TEST(List, can_erase_element_with_key)
{
	List<int> *l = new List<int>();
	int *a = new int;
	*a = 5;

	l->ins(5, a);
	l->ins(346, a);
	l->erase(346);
	ASSERT_EQ(0, l->search(346));
}

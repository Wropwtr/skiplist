#include "../../gtests/gtest.h"
#include "../../include/skiptable.h"

TEST(SkipTable, can_create_table)
{
    ASSERT_NO_THROW(SkipTable<int> table(4, 0.5f));
}

TEST(SkipTable, get_current_works)
{
    SkipTable<int> table(4, 0.5f);
    ASSERT_FALSE(table.getCurrent());
}

TEST(SkipTable, reset_works)
{
    SkipTable<int> table(4, 0.5f);
    int *a = new int;
    table.insert(1,a);
    table.reset();
    EXPECT_EQ(table.getCurrent()->key, 1);
}


TEST(SkipTable, can_get_position)
{
    SkipTable<int> table(4, 0.5f);
    int *a = new int;
    table.insert(2, a);
    table.insert(4, a);
    table.insert(5, a);
    table.insert(1, a);
    table.insert(3, a);
    EXPECT_EQ(table.getPosition(3), 2);
}

TEST(SkipTable, goNext_works)
{
    SkipTable<int> table(4, 0.5f);
    int *a = new int;
    table.insert(2, a);
    table.insert(4, a);
    table.insert(5, a);
    table.insert(1, a);
    table.insert(3, a);
    table.reset();
    int key = table.getCurrent()->key;
    while(table.getCurrent()){
        key = table.getCurrent()->key;
        table.goNext();
    }
    EXPECT_EQ(key, 5);
}

TEST(SkipTable, getSize_works)
{
    SkipTable<int> table(4, 0.5f);
    int *a = new int;
    table.insert(2, a);
    table.insert(4, a);
    table.insert(5, a);
    table.insert(1, a);
    table.insert(3, a);
    EXPECT_EQ(table.getSize(), 5);
}

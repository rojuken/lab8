#include "StackList.h"

#include "../gtest/gtest.h"

TEST(TStackList, can_create_stacklist)
{
	ASSERT_NO_THROW(TStackList<int> A);
}

TEST(TStackList, can_copy)
{
	TStackList<int> A;
	A.Push(2);
	TStackList<int> B(A);
	ASSERT_EQ(2,B.Get());
}

TEST(TStackList, can_push)
{
	TStackList<int> A;
	ASSERT_NO_THROW(A.Push(5));
}

TEST(TStackList, can_get)
{
	TStackList<int> A;
	A.Push(10);
	ASSERT_EQ(10,A.Get());
}

TEST(TStackList, can_equate_stacklists)
{
	TStackList<int> A;
	A.Push(2);
	TStackList<int> B;
	B = A;
	ASSERT_EQ(2, B.Get());
}

TEST(TStackList, check_is_empty)
{
	TStackList<int> A;
	ASSERT_EQ(true, A.IsEmpty());
}

TEST(TStackList, check_is_full)
{
	TStackList<int> A;
	ASSERT_EQ(false, A.IsFull());
}

TEST(TStackList, can_get_min_elem)
{
	TStackList<int> A;
	A.Push(10);
	A.Push(2);
	A.Push(3);
	A.Push(4);

	ASSERT_EQ(2, A.MinElem());
}

TEST(TStackList, can_get_max_elem)
{
	TStackList<int> A;
	A.Push(1);
	A.Push(10);
	A.Push(2);
	A.Push(3);
	A.Push(4);

	ASSERT_EQ(10, A.MaxElem());
}

TEST(STackList, can_load_to_file)
{
	TStackList<int> A;
	A.Push(1);
	A.Push(10);
	A.Push(2);
	A.Push(3);
	A.Push(4);
	ASSERT_NO_THROW(A.LoadToFile());

}
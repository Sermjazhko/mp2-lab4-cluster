#include "queue.h"
#include <gtest.h>

TEST(T_queue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(T_queue<int> st(5));
}

TEST(T_queue, cant_create_too_large_queue)
{
  ASSERT_ANY_THROW(T_queue<int> st(max_queue_size + 1));
}

TEST(T_queue, throws_when_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(T_queue<int> st(-5));
}

TEST(T_queue, can_add_and_get_element)
{
  T_queue<int> st(4);
  st.push(5);
  EXPECT_EQ(5, st.pop());
}

TEST(T_queue, throws_when_full_queue)
{
  T_queue<int> st(1);
  st.push(1);
  EXPECT_EQ(true, st.full());
}

TEST(T_queue, throws_when_add_element_to_full_queue)
{
  T_queue<int> st(1);
  st.push(1);
  ASSERT_ANY_THROW(st.push(1));
}

TEST(T_queue, throws_when_empty_queue)
{
  T_queue<int> st(1);
  EXPECT_EQ(true, st.empty());
}

TEST(T_queue, throws_when_delete_element_from_empty_queue)
{
  T_queue<int> st(1);
  ASSERT_ANY_THROW(st.pop());
}

TEST(T_queue, can_get_size)
{
  T_queue<int> st(1);
  st.push(1);
  EXPECT_EQ(1, st.get_size());
}
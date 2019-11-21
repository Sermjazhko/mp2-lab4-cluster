#include "actual_tasks.h"
#include <gtest.h>

TEST(T_actual_tasks, can_create_elem)
{
  ASSERT_NO_THROW(T_actual_tasks st);
}

TEST(T_actual_tasks, throws_when_empty_tasks)
{
  T_actual_tasks st;
  EXPECT_EQ(true, st.empty());
}

TEST(T_actual_tasks, can_add_element_and_get_size)
{
  T_actual_tasks st;
  st.add_elem(1,1);
  EXPECT_EQ(1, st.get_size());
}

TEST(T_actual_tasks, can_delete_element_with_zero_length)
{
  T_actual_tasks st;
  st.add_elem(1, 1);
  st.add_elem(2, 1);
  st.check_and_delete();
  EXPECT_EQ(1, st.get_size());
}
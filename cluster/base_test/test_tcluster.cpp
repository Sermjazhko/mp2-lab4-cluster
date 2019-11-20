#include "cluster.h"
#include <gtest.h>

TEST(T_cluster, can_create_object_with_positive_length)
{
  ASSERT_NO_THROW(T_cluster st(5));
}

TEST(T_cluster, cant_create_too_large_object)
{
  ASSERT_ANY_THROW(T_cluster st(max_size + 1));
}

TEST(T_cluster, throws_when_create_object_with_negative_length)
{
  ASSERT_ANY_THROW(T_cluster st(-5));
}

TEST(T_cluster, can_take_processors)
{
  T_cluster st(4);
  st.take_pr(3);
  EXPECT_EQ(1, st.get_free_pr());
}

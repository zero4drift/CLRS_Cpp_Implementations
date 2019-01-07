#include <gtest/gtest.h>
#include "chapter-5/hire_assistant_permute_by_sorting/sort_randomized_hire_assistant.hpp"

using namespace CLRS;

using namespace CLRS;

TEST(SortRandomizedHireAssistant, FromHighToLow)
{
  int array[5] = {5, 4, 3, 2, 1};
  int hired;
  sort_randomized_hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

TEST(SortRandomizedHireAssistant, FromLowToHigh)
{
  int array[5] = {1, 2, 3, 4, 5};
  int hired;
  sort_randomized_hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

TEST(SortRandomizedHireAssistant, RandomArray)
{
  int array[5] = {3, 1, 5, 4, 2};
  int hired;
  sort_randomized_hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

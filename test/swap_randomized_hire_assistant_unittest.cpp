#include <gtest/gtest.h>
#include "chapter-5/hire_assistant_randomize_in_place/swap_randomized_hire_assistant.h"

using namespace CLRS;

TEST(SwapRandomizedHireAssistant, FromHighToLow)
{
  int array[5] = {5, 4, 3, 2, 1};
  int hired;
  swap_randomized_hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

TEST(SwapRandomizedHireAssistant, FromLowToHigh)
{
  int array[5] = {1, 2, 3, 4, 5};
  int hired;
  swap_randomized_hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

TEST(SwapRandomizedHireAssistant, RandomArray)
{
  int array[5] = {3, 1, 5, 4, 2};
  int hired;
  swap_randomized_hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

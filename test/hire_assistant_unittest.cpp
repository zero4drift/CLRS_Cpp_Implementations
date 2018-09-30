#include <gtest/gtest.h>
#include "chapter-5/hire_assistant/hire_assistant.h"

using namespace CLRS;

TEST(HireAssistant, FromHighToLow)
{
  int array[5] = {5, 4, 3, 2, 1};
  int hired;
  hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

TEST(HireAssistant, FromLowToHigh)
{
  int array[5] = {1, 2, 3, 4, 5};
  int hired;
  hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

TEST(HireAssistant, RandomArray)
{
  int array[5] = {3, 1, 5, 4, 2};
  int hired;
  hire_assistant(array, &hired);
  EXPECT_EQ(hired, 5);
}

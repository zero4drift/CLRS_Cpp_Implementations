#include <iostream>
#include "insertion_sort.h"

using std::cout;
using std::endl;

int main()
{
  int a[4] = {4, 3, 2, 1};
  insertion_sort(a);
  for(int i = 0; i != 4; ++i)
    cout << a[i] << endl;
}

#include <iostream>
#include <fstream>
#include "alg_graphs.h"

using namespace std;

void MaximalSuffix(string pattern, bool reverseOrder,  int * maximalSuffix, int * period)
{
  *maximalSuffix = -1;
  *period = 1;
  int j = 0;
  int k = 1;
  int n = pattern.length();

  while (j + k <= n)
  {
    int a = pattern[j + k];
    int b = pattern[*maximalSuffix + k];

    if (reverseOrder)
    {
      if (a < b)
      {
        j = j + k;
        k = 1;
        *period = j - *maximalSuffix;
      }
      else if (a == b)
      {
        if (k == *period)
        {
          j = j + *period;
          k = 1;
        }
        else
        {
          k = k + 1;
        }
      }
      else
      {
        *maximalSuffix = j;
        j = *maximalSuffix + 1;
        k = 1;
        *period = 1;
      }
    }
    else
    {
      if (a > b)
      {
        *maximalSuffix = j;
        j = *maximalSuffix + 1;
        k = 1;
        *period = 1;
      }
      else if (a == b)
      {
        if (k == *period)
        {
          j = j + *period;
          k = 1;
        }
        else
        {
          k = k + 1;
        }
      }
      else
      {
        j = j + k;
        k = 1;
        *period = j - *maximalSuffix;
      }
    }
  }
}

int TwoWayMatch(string pattern, string text)
{
  int len_pattern = pattern.length();
  int l1, l2, p1, p2;
  MaximalSuffix(pattern, false, &l1, &p1);
  MaximalSuffix(pattern, true, &l2, &p2);

}

int main()
{
  // TODO: Replace this line with actual logic
  std::cout << "Part 1: TODO" << std::endl;

  return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include "alg_graphs.h"

using namespace std;

void MaximalSuffix(string pattern, bool reverseOrder,  int * maximalSuffix, int * period)
{
  *maximalSuffix = -1;
  *period = 1;
  int j = 0;
  int k = 1;
  int n = pattern.length();

  while (j + k < n)
  {
    int a = pattern[j + k];
    int b = pattern[*maximalSuffix + k];

    if (!reverseOrder)
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
  }
}

vector<int> TwoWayMatch(string pattern, string text)
{
  vector<int> positions;
  int len_pattern = pattern.length();
  int l, l1, l2, p, p1, p2, i, j;
  MaximalSuffix(pattern, false, &l1, &p1);
  MaximalSuffix(pattern, true, &l2, &p2);

  if (l1 >= l2)
  {
    l = l1;
    p = p1;
  }
  else
  {
    l = l2;
    p = p2;
  }

  if (l < len_pattern/2 &&
     (pattern.substr(0, l) == pattern.substr(l, l + p)))
  {
    int pos = 0;
    int s = 0;
    while (pos + len_pattern <= text.length())
    {
      i = max(l, s) + 1;
      while (i <= len_pattern && pattern[i] == text[pos + i])
      {
        i = i + 1;
      }
      if (i <= len_pattern)
      {
        pos = pos + max(i - l, s - p + 1);
        s = 0;
      }
      else
      {
        j = l;
        while (j > s && pattern[j] == text[pos + j])
        {
          j = j - 1;
        }
        if (j <= s)
        {
          positions.push_back(pos);
        }
        pos = pos + p;
        s = len_pattern - p;
      }
    }
  }
  else
  {
    int q = max(l, len_pattern - l) + 1;
    int pos = 0;
    while (pos + len_pattern <= text.length())
    {
      i = l + 1;
      while (i <= len_pattern && pattern[i] == text[pos + i])
      {
        i = i + 1;
      }
      if (i <= len_pattern)
      {
        pos = pos + i - l;
      }
      else
      {
        j = l;
        while (j > 0 && pattern[j] == text[pos + j])
        {
          j = j - 1;
        }
        if (j == 0)
        {
          positions.push_back(pos);
        }
        pos = pos + q;
      }
    }
  }

  return positions;
}


int main()
{
  char pattern[] = "the cat is outta the bag";
  string s_pattern = pattern;
  int n = s_pattern.length();

  TwoWayMatch(s_pattern, "");

  return 0;
}

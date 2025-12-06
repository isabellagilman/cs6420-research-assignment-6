#include <iostream>
#include <fstream>
#include <vector>
#include "alg_graphs.h"
#include "alg_boyermoore.h"
#include <cstring>

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

  cout << "l: " << l << ", p: " << p << endl;

  if (l < len_pattern/2 &&
     (pattern.substr(0, l + 1) == pattern.substr(p, l + p + 1)))
  {
    cout << "A" << endl;
    int pos = 0;
    int s = -1;
    while (pos + len_pattern <= text.length())
    {
      i = max(l, s) + 1;
      while (i <= len_pattern && pattern[i] == text[pos + i])
      {
        i = i + 1;
      }
      if (i < len_pattern)
      {
        pos = pos + max(i - l, s - p + 1);
        s = -1;
      }
      else
      {
        i = l;
        while (i > s && pattern[i] == text[pos + i])
        {
          i = i - 1;
        }
        if (i <= s)
        {
          positions.push_back(pos);
        }
        pos = pos + p;
        s = len_pattern - p - 1;
      }
    }
  }
  else
  {
    cout << "B" << endl;
    int q = max(l + 1, len_pattern - l - 1) + 1;
    int pos = 0;
    while (pos + len_pattern <= text.length())
    {
      i = l + 1;
      while (i < len_pattern && pattern[i] == text[pos + i])
      {
        i = i + 1;
      }
      if (i < len_pattern)
      {
        pos = pos + i - l;
      }
      else
      {
        i = l;
        while (i >= 0 && pattern[i] == text[pos + i])
        {
          i = i - 1;
        }
        if (i < 0)
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
  char text[] = "the cat is outta the bag";
  char pattern[] = "cat";
  string s_pattern = pattern;
  string s_text = text;
  int n = s_pattern.length();

  vector<int> matches = bm_search(s_pattern, s_text);
  for(int idx : matches)
  {
    cout << idx << ", ";
  }
  cout << endl;

  return 0;
}

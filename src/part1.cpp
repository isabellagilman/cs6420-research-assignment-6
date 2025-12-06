#include <iostream>
#include <fstream>
#include <vector>
#include "alg_graphs.h"
#include "alg_twoway.h"
#include "alg_boyermoore.h"
#include "alg_kmp.h"
#include "alg_stopwatch.h"
#include <cstring>

using namespace std;

void time_algorithms()
{
  cout << "\t|   Boyer-Moore\t|   KMP\t\t|   Two-Way" << endl;
  StopWatch stopwatch;
  for(int n = 500000; n <= 5000000; n = n + 500000)
  {
    double time_bm = 0;
    double time_kmp = 0;
    double time_tw = 0;

    // Generate random text of size n
    char text[n];
    char pattern[] = "aabbccdd";
    char alphabet[] = "abcd";
    for(int i = 0; i < n; i++)
    {
      text[i] = alphabet[rand() % 4];
    }

    string s_text = text;
    string s_pattern = pattern;

    stopwatch.reset();
    bm_search(s_pattern, s_text);
    time_bm = stopwatch.elapsed_time();

    stopwatch.reset();
    kmp_search(s_pattern, s_text);
    time_kmp = stopwatch.elapsed_time();

    stopwatch.reset();
    TwoWayMatch(s_pattern, s_text);
    time_tw = stopwatch.elapsed_time();

    cout << n << "\t|" << time_bm << "\t\t|"<< time_kmp << "\t\t|"<< time_tw << endl;
  }
}


int main()
{
  char text[] = "the cat is outta the bag";
  char pattern[] = "cat";
  string s_pattern = pattern;
  string s_text = text;
  int n = s_pattern.length();

  time_algorithms();

  // vector<int> tw_matches = TwoWayMatch(s_pattern, s_text);
  // vector<int> bm_matches = bm_search(s_pattern, s_text);
  // vector<int> kmp_matches = kmp_search(s_pattern, s_text);
  // for(int idx : matches)
  // {
  //   cout << idx << ", ";
  // }
  // cout << endl;

  return 0;
}

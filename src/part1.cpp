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
  cout << "\t|   Iterative\t|   Recursive\t|   Strassen" << endl;
  StopWatch stopwatch;
  for(int n = 2; n <= 64; n = n*2)
  {
    double time_it = 0;
    double time_rec = 0;
    double time_stra = 0;

    // Generate 2 random matrices of size nxn
    double A[n*n];
    double B[n*n];
    for(int i = 0; i < (n*n); i++)
    {
      A[i] = rand() % 1000;
      B[i] = rand() % 1000;
    }

    double * C;

    stopwatch.reset();
    //C = iterative_mult(n, A, B);
    time_it = stopwatch.elapsed_time();

    stopwatch.reset();
    //C = recursive_mult(n, A, B);
    time_rec = stopwatch.elapsed_time();

    stopwatch.reset();
    //C = strassen_mult(n, A, B);
    time_stra = stopwatch.elapsed_time();

    cout << n << "\t|" << time_it << "\t\t|"<< time_rec << "\t\t|"<< time_stra << endl;
  }
}


int main()
{
  char text[] = "the cat is outta the bag";
  char pattern[] = "cat";
  string s_pattern = pattern;
  string s_text = text;
  int n = s_pattern.length();

  vector<int> tw_matches = TwoWayMatch(s_pattern, s_text);
  vector<int> bm_matches = bm_search(s_pattern, s_text);
  vector<int> kmp_matches = kmp_search(s_pattern, s_text);
  // for(int idx : matches)
  // {
  //   cout << idx << ", ";
  // }
  // cout << endl;

  return 0;
}

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

string parseFile(string filename)
{
  ifstream infile(filename);
  string text;
  getline(infile, text);
  return text;
}


int main(int argc, char* argv[])
{
  // time_algorithms();

  if(argc != 3)
  {
    return -1;
  }
  
  string pattern = argv[1];
  string text = parseFile(argv[2]);

  vector<int> tw_matches = TwoWayMatch(pattern, text);
  for(int idx : tw_matches)
  {
    cout << idx << " ";
  }
  cout << endl;

  return 0;
}

#include <string>
#include <vector>

using namespace std;

#ifndef _ALG_TWO_WAY_H_
#define _ALG_TWO_WAY_H_

void MaximalSuffix(string pattern, bool reverseOrder,  int * maximalSuffix, int * period);
vector<int> TwoWayMatch(string pattern, string text);

#endif
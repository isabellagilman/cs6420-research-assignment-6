/**********************************************************************************/
/* This implementation of the KMP Algorithm was modified from                     */
/* the Geeks For Geeks website on 2025-05-12 for the purpose of timing against    */
/* the Two-way string-matching algorithm                                          */
/* url:                                                                           */
/* https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/         */

#include <string>
#include <vector>

using namespace std;

#ifndef _ALG_KMP_H_
#define _ALG_KMP_H_

vector<int> kmp_search(string &pat, string &txt);

#endif
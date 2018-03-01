#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

template<typename T>
void debug (T x)
{
	cerr << ">>> " << x << endl;
}

//util classes
struct Input {
  int r, c, f, n, b, t;
  //ride i = 2i->2i+1, start 2n+2, target 2n+3 -> 2n+4 nodes
  vector<vector<int>> adj;
  vector<vector<ll>> dist;
  vector<vector<int>> car;
  vector<vector<int>> paths;
};

//input handling
void readInput(Input& input, istream& in) {
	//TODO read input
}

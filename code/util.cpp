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
  vector<vector<int>> paths;
  vector<ll> ra, rb, rx, ry, rs, rf;
};

//input handling
void readInput(Input& input, istream& in) {
	in >> input.r >> input.c >> input.f >> input.n >> input.b >> input.t;
  input.ra.resize(input.n);
  input.rb.resize(input.n);
  input.rx.resize(input.n);
  input.ry.resize(input.n);
  input.rs.resize(input.n);
  input.rf.resize(input.n);
  input.paths.resize(input.n);
  for(int i = 0; i < input.n; i++) {
    in >> input.ra[i] >> input.rb[i] >> input.rx[i] >> input.ry[i] >> input.rs[i] >> input.rf[i];
  }
}

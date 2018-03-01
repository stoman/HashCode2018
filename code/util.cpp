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
  vector<ll> ra, rb, rx, ry, rs, rt;
  vector<int> curride;
};

//input handling
void readInput(Input& input, istream& in) {
	in >> input.r >> input.c >> input.f >> input.n >> input.b >> input.t;
  input.ra.resize(input.n);
  input.rb.resize(input.n);
  input.rx.resize(input.n);
  input.ry.resize(input.n);
  input.rs.resize(input.n);
  input.rt.resize(input.n);
  input.adj.resize(2*input.n+4);
  input.dist.resize(2*input.n+4);
  input.car.resize(2*input.n+4);
  input.paths.resize(input.n);
  for(int i = 0; i < input.n; i++) {
    in >> input.ra[i] >> input.rb[i] >> input.rx[i] >> input.ry[i] >> input.rs[i] >> input.rt[i];
  }
}

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

const double inf = 1e12;

//util classes
struct Input {
  int r, c, f, n, b, t;
  vector<vector<int>> paths, cntcars;
  vector<ll> ra, rb, rx, ry, rs, rf;
  int cellcnt = 5;
  char problem;
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
  input.cntcars.resize(input.cellcnt);
  for (int i = 0; i < input.cellcnt; i++)
      input.cntcars[i] = vector<int>(input.cellcnt, 0);


  switch(input.r)
  {
  	case 3: input.problem = 'a'; break;
  	case 800: input.problem = 'b'; break;
  	case 3000: input.problem = 'c'; break;
  	case 10000: input.problem = 'd'; break;
  	case 1500: input.problem = 'e'; break;
  	default: cerr << "PROBLEM NOT DETECTED" << endl; exit(0);
  }
}

double score(Input& input, int time, int r, int c, int ride, int carid);
int endtime(Input& input, int time, int r, int c, int ride);


pair<int,int> cellid(Input &input, int x, int y)  {
    // dimension of a cell
    int cellr = (input.r+input.cellcnt-1) / input.cellcnt;
    int cellc = (input.c+input.cellcnt-1) / input.cellcnt;

    return {x/cellr, y/cellc}; 
}
 
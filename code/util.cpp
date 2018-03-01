#pragma once

typedef long long ll;
typedef pair<ll, ll> Point;

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

template<typename T>
void debug (T x)
{
	cerr << ">>> " << x << endl;
}

//util classes
struct SomeClass {
	int n;
	SomeClass(int n): n(n) {};
};

struct Input {
};

//input handling
void readInput(Input& input, istream& in) {
	//TODO read input
}

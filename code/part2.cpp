#pragma once
#include "util.cpp"

int endtime(Input& input, int time, int r, int c, int ride) {
  int pretime = abs(r - input.ra[ride]) + abs(c - input.rb[ride]);
  int drivetime = abs(input.ra[ride] - input.rx[ride]) + abs(input.rb[ride] - input.ry[ride]);
  return time + pretime + drivetime;
}

double score(Input& input, int time, int r, int c, int ride, int carid) {
  //coefficients
  double drivetimefactor = 1.0;
  double pretimefactor = -1.0;
  double cardistancefactor = -0.2 / input.f;

  //end time
	int pretime = abs(r - input.ra[ride]) + abs(c - input.rb[ride]);
  int drivetime = abs(input.ra[ride] - input.rx[ride]) + abs(input.rb[ride] - input.ry[ride]);
  if(time + pretime + drivetime > input.rf[ride]) {
    return -99999999999.9;
  }

  //scoring: drive time, pre time
  double score = drivetimefactor * drivetime + pretimefactor * pretime;

  //scoring: car distance time
  for(int c = 0; c < input.f; c++) {
    if(c == carid || input.paths[c].size() == 0) {
      continue;
    }
    score += cardistancefactor * (abs(input.rx[input.paths[c].back()] - input.rx[ride]) + abs(input.ry[input.paths[c].back()] - input.ry[ride]));
  }

  //return
  return score;
}

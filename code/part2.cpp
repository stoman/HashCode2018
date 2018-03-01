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
  double bonusfactor = 1.0;
  double pretimefactor = -1.0;
  double pretimesquarefactor = -.001;
  double cardistancefactor = -0.2 / input.f;

  //end time
	int pretime = abs(r - input.ra[ride]) + abs(c - input.rb[ride]);
  if(time + pretime < input.rs[ride]) {
    pretime = input.rs[ride] - time;
  }
  int drivetime = abs(input.ra[ride] - input.rx[ride]) + abs(input.rb[ride] - input.ry[ride]);
  if(time + pretime + drivetime > input.rf[ride]) {
    return -99999999999.9;
  }

  //scoring: drive time, pre time
  double score = 0;
  debug("drive time");
  debug(drivetimefactor * drivetime);
  score += drivetimefactor * drivetime;

  debug("pre time");
  debug(pretimefactor * pretime);
  score += pretimefactor * pretime;
  debug("pre time square");
  debug(pretimesquarefactor * pretime * pretime);
  score += pretimesquarefactor * pretime * pretime;

  //score: bonus
  debug("bonus");
  double bonus = time + pretime == input.rs[ride] ? bonusfactor * input.b : 0.0;
  debug(bonus);
  score += bonus;

  //scoring: car distance
  double cardistscore = 0;
  for(int c = 0; c < input.f; c++) {
    if(c != carid && input.paths[c].size() != 0) {
      cardistscore += cardistancefactor * (abs(input.rx[input.paths[c].back()] - input.rx[ride]) + abs(input.ry[input.paths[c].back()] - input.ry[ride]));
    }
  }
  debug("car dist score");
  debug(cardistscore);
  score += cardistscore;

  //return
  return score;
}

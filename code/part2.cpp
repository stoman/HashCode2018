#pragma once
#include "util.cpp"

int endtime(Input& input, int time, int r, int c, int ride) {
  int pretime = abs(r - input.ra[ride]) + abs(c - input.rb[ride]);
  int ctime = max((ll) time + pretime, input.rs[ride]);
  int drivetime = abs(input.ra[ride] - input.rx[ride]) + abs(input.rb[ride] - input.ry[ride]);
  return ctime + drivetime;
}

vector<vector<vector<int>>> ridescore;

double score(Input& input, int time, int r, int c, int ride, int carid) {
  //coefficients
  double drivetimefactor = 1.0;
  double bonusfactor = 1.0;
  double pretimefactor = -1.0;
  double pretimesquarefactor = -.001;
  double cardistancefactor = -0.2 / input.f;
  double gridfactor = 10.0;
  int gridsize = 500;
  int timegrid = 5000;

  //end time
	int pretime = abs(r - input.ra[ride]) + abs(c - input.rb[ride]);
  if(time + pretime < input.rs[ride]) {
    pretime = input.rs[ride] - time;
  }
  int drivetime = abs(input.ra[ride] - input.rx[ride]) + abs(input.rb[ride] - input.ry[ride]);
  int endtime = time + pretime + drivetime;
  if(endtime >= input.rf[ride] || endtime > input.t) {
    return -999999999.9;
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
  auto cell = cellid(input, input.rx[ride], input.ry[ride]);
  cardistscore += cardistancefactor * input.cntcars[cell.first][cell.second];
  debug("car dist score");
  debug(cardistscore);
  score += cardistscore;

  //fill ridescore
  if(ridescore.size() == 0) {
    ridescore.resize(input.r/gridsize + 2);
    for(int i = 0; i < ridescore.size(); i++) {
      ridescore[i].resize(input.c/gridsize + 2);
      for(int j = 0; j < ridescore[i].size(); j++) {
        ridescore[i][j].resize(input.t/timegrid + 2);
      }
    }
    for(int i = 0; i < input.n; i++) {
      int laststart = input.rf[i] - abs(input.ra[i] - input.rx[i]) - abs(input.rb[i] - input.ry[i]);
      for(int t = input.rs[i]; t < laststart; t += timegrid) {
        ridescore[input.ra[i]/gridsize][input.rb[i]/gridsize][t/timegrid];
      }
    }
  }

  //scoring: grid
  double gridscore = gridfactor * ridescore[input.rx[ride]/gridsize][input.ry[ride]/gridsize][endtime/timegrid];
  debug("grid score");
  debug(gridscore);
  score += gridscore;

  //return
  return score;
}

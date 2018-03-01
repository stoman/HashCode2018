#pragma once
#include "util.cpp"

ll lastStartPoint(Input &input, int ride)
{
    ll last = input.rf[ride];
    ll drivetime = abs(input.ra[ride] - input.rx[ride]) + abs(input.rb[ride] - input.ry[ride]);
    return last - drivetime;
}


void assignrides(Input& input) {
    set<pair<int,int>> q;
  // set<int> rides;
    set<pair<int,int>> priorides;
    
    for (int i = 0; i < input.f; i++)
        q.insert({0,i});
    for (int i = 0; i < input.n; i++)
    {
        priorides.insert(make_pair(input.rs[i],i));
        //rides.insert(i);
    }
         
    while (q.size() && q.begin()->first < input.t)    {
    
        int t = q.begin()->first;

        while (priorides.size() && lastStartPoint(input, priorides.begin()->second) < t)
        {
            priorides.erase(priorides.begin());
        }


        int car = q.begin()->second;
        cerr << t << ' ' << car << endl;
        q.erase(q.begin());
        
        int r = 0, c = 0;
        if (input.paths[car].size())    {
            int last_ride = input.paths[car].back();
            r = input.rx[last_ride];
            c = input.ry[last_ride];
        }
        
        auto cell = cellid(input, r, c);
        input.cntcars[cell.first][cell.second]--;
        double max_score = -inf;

        int bi = -1;
        int prio = -1;
        
        if (priorides.size() > 700)//if (rides.size() == 1)
        {
            for (auto i = priorides.begin(); i != priorides.end(); i++) {
                int next_ride = i->second;
                double sc1 = score(input, t, r, c, next_ride, car);
                if (sc1 > max_score)
                {
                    max_score = sc1;
                    bi = i->second;  
                    prio = i->first;
                }
            }
        }
        
        else    
        {
            for (auto i = priorides.begin(); i != priorides.end(); i++) {
                for (auto j = priorides.begin(); j != priorides.end(); j++) 
                {
                    if (i == j)
                        continue;
                
                    int next_ride = i->second;
                    double sc1 = score(input, t, r, c, next_ride, car);
                
                    int nr = input.rx[next_ride];
                    int nc = input.ry[next_ride];
                
                    double sc2 = score(input, t, nr, nc, j->second, car);
            
                    if (sc1 + sc2 > max_score)
                    {
                        max_score = sc1+sc2;
                        bi = i->second;
                        prio = i->first;
                    }
                }
            }
        }
        
        if (bi != -1)
        {
            input.paths[car].push_back(bi);
            priorides.erase({prio,bi});
            q.insert({endtime(input, t, r, c, bi), car});
    
            auto cell = cellid(input, input.rx[bi], input.ry[bi]); 
            input.cntcars[cell.first][cell.second]++;
        }
    }
}
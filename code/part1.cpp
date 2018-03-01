#pragma once
#include "util.cpp"

void assignrides(Input& input) {
    set<pair<int,int>> q;
    set<int> rides;
    
    for (int i = 0; i < input.f; i++)
        q.insert({0,i});
    for (int i = 0; i < input.n; i++)
        rides.insert(i);
         
    while (q.size() && q.begin()->first < input.t)    {
    
        int t = q.begin()->first;
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
        double max_score = -99999999.9;

        int bi = -1;
        
        if (true)//if (rides.size() == 1)
        {
            for (auto i = rides.begin(); i != rides.end(); i++) {
                int next_ride = *i;
                double sc1 = score(input, t, r, c, next_ride, car);
                if (sc1 > max_score)
                {
                    max_score = sc1;
                    bi = *i;  
                }
            }
        }
        
        else    
        {
            for (auto i = rides.begin(); i != rides.end(); i++) {
                for (auto j = rides.begin(); j != rides.end(); j++) 
                {
                    if (i == j)
                        continue;
                
                    int next_ride = *i;
                    double sc1 = score(input, t, r, c, next_ride, car);
                
                    int nr = input.rx[next_ride];
                    int nc = input.ry[next_ride];
                
                    double sc2 = score(input, t, nr, nc, *j, car);
            
                    if (sc1 + sc2 > max_score)
                    {
                        max_score = sc1+sc2;
                        bi = *i;
                    }
                }
            }
        }
        
        if (bi != -1)
        {
            input.paths[car].push_back(bi);
            rides.erase(bi);
            q.insert({endtime(input, t, r, c, bi), car});
    
            auto cell = cellid(input, input.rx[bi], input.ry[bi]); 
            input.cntcars[cell.first][cell.second]++;
        }
    }
}
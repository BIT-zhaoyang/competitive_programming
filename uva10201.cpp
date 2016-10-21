#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 25
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

int main(){ _
    int tc; cin >> tc;
    while(tc--){
        int dist;   cin >> dist;    cin.ignore();

        vector< ii > station;
        station.push_back(ii(0, BIGINT));   // dummy station at start point, for easier operation
        string line;
        while(getline(cin, line)){
            if(line == "")  break;
            stringstream ss(line);
            int d, price;
            ss >> d >> price;
            station.push_back(ii(d, price));
        }

        int nStation = station.size();
        vector< vector<int> > table(nStation, vector<int> (210, BIGINT));
        table[0][100] = 0;  // state at dummy station
        for(int i = 1; i < nStation; ++i){
            // drive from last station to current station
            for(int j = i - 1; j >= 0; --j){
                int distDiff = station[i].first - station[j].first;
                // if too far, it's impossible
                if(distDiff > 200)   break;
                for(int fuel = 0; fuel + distDiff <= 200; ++fuel){
                    // to get current station i with 'fuel' fuel, the truck must have
                    // 'fuel + distDiff' at last station
                    table[i][fuel] = min(table[i][fuel], table[j][fuel + distDiff]);
                }
            }

            // fuel the tank at current station
            int price = station[i].second;
            for(int after = 1; after <= 200; ++after)
                for(int before = 0; before < after; ++before)
                    // table[i][after] is minimum by going from last station to current
                    // station directly with exact 'after' fuel. Or the truck can have less
                    // fuel which equals 'before', then fuel the truck at current station to
                    // have 'after' fuel
                    table[i][after] = min(table[i][after],
                            table[i][before] + (after - before) * price);
        }

        // drive to the destination from some station
        // notice the station can go beyond our destination city. For example, the city is at
        // 500, the station is at 501.
        int ans = BIGINT;
        for(int i = 0; i < nStation; ++i){
            int distDiff = abs(station[i].first - dist);
            if(distDiff > 200)  continue;
            for(int fuel = 100; fuel + distDiff <= 200; ++fuel)
                ans = min(ans, table[i][fuel + distDiff]);
        }

        if(ans == BIGINT)   cout << "Impossible" << endl;
        else    cout << ans << endl;
        if(tc)  cout << endl;
    }
    return 0;
}

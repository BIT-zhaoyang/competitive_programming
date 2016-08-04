#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
/* Similiar to uva10166.
    AdjList contains three elements:
        Running time of this train: run_time
        Departure time of this train: dep_curr
        Next arrival station: next
    Problem state also consists of three elements:
        Distance of curr: dist[curr]    // different to uva10166
        Current time: curr_time
        Current station: curr
    Condition NOT to choose an edge:
        int arr_next = (dep_curr + run_time) % 24;
        if(dep_curr == 6 && run_time == 12) continue;
        if(dep_curr > 6 && dep_curr < 18)   continue;
        if(arr_next > 6 && arr_next < 18)   continue;
        if(run_time > 12)   continue;

    Additional difference to uva10166:
    The distance represents how much blood the vampire has.
    if(curr_time <= 6 && dep_curr >= 18)    dist[next] = dist[curr] + 1;
    else    dist[next] = dist[curr];

    PS: Oh!!!!!!!!! Man!!!!!!!!!!!!!!! The corner cases almost killed me......
    Time at 24 equals 0! Time at 3 comes after time at 21! Omg...Learned something with time now!
*/

map<string, int> s2i;
vector< vector< tuple<int, int, int> > > AdjList;
priority_queue< iii, vector< iii >, greater< iii > > pq;
vector<int> dist;
int nCity;

void dijkstra(int curr, int curr_time){
    dist[curr] = 0;
    pq.push(iii(dist[curr], curr_time, curr));

    int next, dep_curr, run_time, dist_curr, dist_next;
    while(!pq.empty()){
        tie(dist_curr, curr_time, curr) = pq.top();
        pq.pop();

        if(dist_curr > dist[curr])  continue;
        for(int i = 0; i < AdjList[curr].size(); ++i){
            tie(next, dep_curr, run_time) = AdjList[curr][i];
            int arr_next = (dep_curr + run_time) % 24;

            if(dep_curr == 0){
                if(curr_time <= 6 && curr_time > 0)  dist_next = dist_curr + 1;
                else dist_next = dist_curr;
            } else {
                if(abs(curr_time - dep_curr) <= 6){
                    if(dep_curr < curr_time)    dist_next = dist_curr + 1;
                    else    dist_next = dist_curr;
                } else {
                    if(dep_curr >= 18 && dep_curr <=24) dist_next = dist_curr + 1;
                    else    dist_next = dist_curr;
                }
            }

            if(dist_next > dist[next])  continue;

            pq.push(iii(dist_next, arr_next, next));
            dist[next] = dist_next;
        }
    }
}

int main(){ _
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cout << "Test Case " << tc << "." << endl;
        s2i.clear();
        AdjList.clear();

        int nRoad, id1, id2, dep_curr, run_time;  cin >> nRoad;
        string city1, city2;
        nCity = 0;
        for(int i = 0; i < nRoad; ++i){
            cin >> city1 >> city2 >> dep_curr >> run_time;
            dep_curr %= 24;

            if(s2i.count(city1)){
                id1 = s2i[city1];
            } else {
                s2i[city1] = id1 = nCity++;
                AdjList.push_back(vector< tuple<int, int, int> > (0));
            }

            if(s2i.count(city2)){
                id2 = s2i[city2];
            } else {
                s2i[city2] = id2 = nCity++;
                AdjList.push_back(vector< tuple<int, int, int> > (0));
            }

            int arr_next = (dep_curr + run_time) % 24;
            if(dep_curr == 6 && run_time == 12) continue;
            if(dep_curr > 6 && dep_curr < 18)   continue;
            if(arr_next > 6 && arr_next < 18)   continue;
            if(run_time > 12)   continue;

            AdjList[id1].push_back(make_tuple(id2, dep_curr, run_time));
        }

        cin >> city1 >> city2;
        if(city1 == city2){
            cout << "Vladimir needs 0 litre(s) of blood." << endl;
            continue;
        } else if(s2i.count(city1) == 0 || s2i.count(city2) == 0){
            cout << "There is no route Vladimir can take." << endl;
            continue;
        }

        id1 = s2i[city1],   id2 = s2i[city2];
        int ans = INT_MAX, next, arr_next;
        for(int i = 0; i < AdjList[id1].size(); ++i){
            tie(next, dep_curr, run_time) = AdjList[id1][i];
            dist.assign(nCity, INT_MAX);
            dijkstra(id1, dep_curr);
            ans = min(ans, dist[id2]);
        }

        if(ans == INT_MAX)  cout << "There is no route Vladimir can take." << endl;
        else    cout << "Vladimir needs " << ans << " litre(s) of blood." << endl;
    }
    return 0;
}

#include <algorithm>
#include <bitset>
#include <cstring>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <vector>

#define UNVISITED -1
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

/* AdjList records three elements:
	departure time at current node: dep_curr
	arrival time at next node: arr_next
	index of next node:	next
  Problem state consists of two elements:
    index of current node: curr
	arrival time of current node: arr_curr
  Condition to choose an edge:
    arr_curr <= dep_curr
*/

typedef long long int64;
typedef pair<int, int> ii;

map<string, int> s2i;
vector< vector< tuple<int, int, int> > > AdjList;
vector<int> dist;
priority_queue< ii, vector< ii >, greater< ii > > pq;
vector<string> names;

void dijkstra(int curr, int dep_curr){
	pq.push(ii(dep_curr, curr));
	dist[curr] = dep_curr;

	int next, arr_next, arr_curr;
	while(!pq.empty()){
		arr_curr = pq.top().first,	curr = pq.top().second;
		pq.pop();

		if(arr_curr > dist[curr])	continue;	// lazy delete
		for(int i = 0; i < AdjList[curr].size(); ++i){
			tie(next, dep_curr, arr_next) = AdjList[curr][i];
			if(dep_curr < arr_curr)	continue;	// if the train leaves before we arrive, then it's not possible
			if(arr_next >= dist[next])	continue;	// if we arrive at a station no better than the best plan, then continue

			pq.push(ii(arr_next, next));
			dist[next] = arr_next;
		}
	}
}

int main(){ _
	int nCity;
	while(cin >> nCity){
		if(nCity == 0)	break;

		s2i.clear();
		names.clear();
		string city;
		for(int i = 0; i < nCity; ++i){
			cin >> city;
			s2i[city] = i;
			names.push_back(city);
		}
		AdjList.assign(nCity, vector< tuple<int, int, int> > (0));

		int nRoad;	cin >> nRoad;
		for(int i = 0; i < nRoad; ++i){
			int nStop;	cin >> nStop;

			vector< ii > vii;
			int dep, idx;
			for(int j = 0; j < nStop; ++j){
				cin >> dep >> city;
				idx = s2i[city];
				vii.push_back(ii(dep, idx));
			}

			for(int j = 0; j + 1 < nStop; ++j){
				int curr, next, dep_curr, arr_next;
				curr = vii[j].second, next = vii[j+1].second;
				dep_curr = vii[j].first, arr_next = vii[j+1].first;
				AdjList[curr].push_back(make_tuple(next, dep_curr, arr_next));
			}
		}

		int startTime, startCity, arrCity;
		cin >> startTime;
		cin >> city;	startCity = s2i[city];
		cin >> city;	arrCity = s2i[city];

		int ansStart = -1, ansArr = INT_MAX;
		for(int i = 0; i < AdjList[startCity].size(); ++i){
			int next, dep_curr, arr_next;
			tie(next, dep_curr, arr_next) = AdjList[startCity][i];

			if(dep_curr >= startTime){
				dist.assign(nCity, INT_MAX);
				dijkstra(startCity, dep_curr);


				/* I made a very nasty mistake at here!! Took me several hours to discover it with others help!!!!
				Originally, I wrote:
				if(dist[arrCity] < ansArr){
					ansArr = dist[arrCity];
					ansStart = max(dep_curr, ansStart);
				}
				The mistake is that:
				In the first interation, we may reach arrCity at a late time, say 1900, and we start at 1000. In the second interation, we reach arrCity at the optimal time 1800, and we start at 0900. But since we have set ansStart = 1000 in last iteration, this time, this one will remain! Then...Well, everything goes wront...
				*/

				if(dist[arrCity] < ansArr){
					ansArr = dist[arrCity];
					ansStart = dep_curr;
				} else if(dist[arrCity] == ansArr){
					ansStart = max(dep_curr, ansStart);
				}
			}
		}

		if(ansArr != INT_MAX)	cout << setw(4) << setfill('0') << ansStart << " "
								 <<	setw(4) << setfill('0') << ansArr << endl;
		else	cout << "No connection" << endl;
	}
    return 0;
}

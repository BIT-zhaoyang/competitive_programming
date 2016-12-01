#include <bits/stdc++.h>
#define UNVISITED -1
#define POS_INF 1 << 25
#define NEG_INF -1 << 25
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

double length;

double dist(double x1, double y1, double x2, double y2){
    x1 /= 1000.0;   y1 /= 1000.0;
    x2 /= 1000.0;   y2 /= 1000.0;
    double diffX = x1 - x2, diffY = y1 - y2;
    return sqrt(pow(diffX, 2) + pow(diffY, 2));
}

int main(){ _
    int tc; cin >> tc;
    string line;    cin.ignore();   getline(cin, line); // read the first blank line
    while(tc--){
        length = 0.0;
        getline(cin, line); // start corrdinates, no use
        while(getline(cin, line)){
            if(line == "")  break;
            stringstream ss(line);
            int x1, y1, x2, y2;
            ss >> x1 >> y1 >> x2 >> y2;
            length += dist(x1, y1, x2, y2);
        }

        length *= 2;    // two lanes per road
        double fracTime = length / 20.0;
        int hour = int(fracTime / 1.0);
        int minute = int((fracTime - hour) * 60.0 + 0.5);
        if(minute == 60)    hour += 1, minute = 0;

        cout << hour << ":" << setw(2) << setfill('0') << minute << endl;
        if(tc)  cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define UNVISITED -1
#define BIGINT 1 << 28
#define maxN 20
using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

/* Good problem. An expansion to Floyd-Warshall. */

double AdjMat[maxN][maxN][maxN+1];
int parent[maxN][maxN][maxN+1];

void print(int i, int j, int l){
    if(l == 0)  cout << i + 1;
    else{
        print(i, parent[i][j][l], l-1);
        cout << " " << j + 1;
    }
}

int main(){ _
    int n;
    while(cin >> n){
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                for(int l = 0; l <= n; ++l)
                    AdjMat[i][j][l] = 0.0;


        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                parent[i][j][1] = i;
                if(j == i)  AdjMat[i][i][1] = 1.0;
                else    cin >> AdjMat[i][j][1];
            }


        for(int l = 2; l <= n; ++l)
            for(int k = 0; k < n; ++k)
                for(int i = 0; i < n; ++i)
                    for(int j = 0; j < n; ++j)
                        if(AdjMat[i][k][l-1] * AdjMat[k][j][1] > AdjMat[i][j][l]){
                            AdjMat[i][j][l] = AdjMat[i][k][l-1] * AdjMat[k][j][1];
                            parent[i][j][l] = k;
                        }

        bool success = false;
        for(int l = 2; l <= n; ++l){
            for(int i = 0; i < n; ++i)
                if(AdjMat[i][i][l] > 1.01){
                    success = true;
                    print(i, i, l);
                    cout << endl;
                    break;
                }
            if(success) break;
        }
        if(!success)    cout << "no arbitrage sequence exists" << endl;
    }
    return 0;
}

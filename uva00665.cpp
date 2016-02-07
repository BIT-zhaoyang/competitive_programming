//#include <iostream>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//int main(){
//    int M;
//    cin >> M;
//    while(M--){
//        int N, K;
//        cin >> N >> K;
//        bool *barr = (bool*) new bool[N + 1];
//        memset(barr, false, sizeof(bool) * (N+1));
//        
//        char ch;
//        int p, idx;
//        vector<int> vi;
//        for(int i = 0; i < K; ++i){
//            vi.clear();
//            cin >> p;
//            for(int j = 0; j < 2*p; ++j){
//                cin >> idx;
//                vi.push_back(idx);
//            }
//            cin >> ch;
//            if(ch == '='){
//                for(int j = 0; j < vi.size(); ++j){
//                    barr[vi[j]] = true;
//                }
//            }
//        }
//        
//        int count = 0;
//        for(int i = 1; i <= N; ++i){
//            if(!barr[i]){
//                count++;
//                idx = i;
//            }
//        }
//        
//        if(count == 1){
//            cout << idx << endl << endl;
//        } else {
//            cout << "0" << endl << endl;
//        }
//    }
//    return 0;
//}

#include <stdio.h>
struct record{
    int numl[50];
    int numr[50];
    int pi;
    char op;
}data[100];
int main()
{
    int T, n, k, i, j, l;
    scanf("%d", &T);
    while(T--){
        int possible[101]={}, judge = 0, Ans;
        scanf("%d%d", &n, &k);
        for(i = 0; i < k; i++){
            scanf("%d", &data[i].pi);
            for(j = 0; j < data[i].pi; j++)
                scanf("%d", &data[i].numl[j]);
            for(j = 0; j < data[i].pi; j++)
                scanf("%d", &data[i].numr[j]);
            scanf(" %c", &data[i].op);
            if(data[i].op == '='){
                for(j = 0; j < data[i].pi; j++){
                    possible[data[i].numl[j]] = 1;
                    possible[data[i].numr[j]] = 1;
                }
            }
        }
        for(i = 1; i <= n; i++){
            if(possible[i])  continue;
            for(j = 0; j < k; j++){
                int ll = 0, lr = 0, hl = 0, hr = 0;
                for(l = 0; l < data[j].pi; l++){
                    if(data[j].numl[l] != i)    ll--, hl++;
                    if(data[j].numr[l] != i)    lr--, hr++;
                }
                if(data[j].op == '=' && ll == lr) continue;
                else if(data[j].op == '=' && hl == hr) continue;
                else if(data[j].op == '<' && ll < lr) continue;
                else if(data[j].op == '<' && hl < hr) continue;
                else if(data[j].op == '>' && ll > lr) continue;
                else if(data[j].op == '>' && hl > hr) continue;
                else    break;
            }
            if(j == k)  judge++, Ans = i;
        }
        if(judge == 1)  printf("%d\n", Ans);
        else    printf("0\n");
        if(T)   puts("");
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>
#include <set>
#include <bitset>
#include <sstream>
#include <iomanip>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
using namespace std;

enum instruct {L = -1, F, R};
enum direction {N, E, S, W};
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct robot{
    bool lost;
    int x, y, maxX, maxY;
    int lastX, lastY;   // for recovery
    direction direct;

    robot(int _x, int _y, char _direct, int _maxX, int _maxY){
        lost = false;
        x = _x, y = _y, maxX = _maxX, maxY = _maxY;
        switch(_direct){
            case 'N':   direct = N; break;
            case 'E':   direct = E; break;
            case 'S':   direct = S; break;
            case 'W':   direct = W; break;
        }
    }

    void takeInstruct(instruct inst){
        direct = direction((direct + 4 + inst) % 4);
        lastX = x, lastY = y;
        if(inst == F){
            x += dx[direct];
            y += dy[direct];
        }
    }

    bool fail(){
        lost = (x < 0 || x > maxX || y < 0 || y > maxY);
        return lost;
    }

    void recovery(){
        x = lastX;
        y = lastY;
    }

    void print(){
        cout << x << " " << y << " ";
        switch (direct) {
            case N:   cout << "N";    break;
            case S:   cout << "S";    break;
            case W:   cout << "W";    break;
            case E:   cout << "E";    break;
        }

        if(lost)    cout << " LOST" << endl;
        else    cout << endl;
    }
};

int main(){ _
    int maxX, maxY, x, y;   cin >> maxX >> maxY;
    vector< vector<bool> > scent(maxX+1, vector<bool> (maxY+1, false)); // at first none instruct leading to fall off is recorded

    char direct;
    while(cin >> x >> y >> direct){
        robot bot(x, y, direct, maxX, maxY);

        string instructions;
        cin >> instructions;
        instruct inst;
        for(int i = 0; i < instructions.size(); ++i){
            x = bot.x,  y = bot.y;
            switch (instructions[i]) {
                case 'L':   inst = L;   break;
                case 'R':   inst = R;   break;
                case 'F':   inst = F;   break;
            }

            bot.takeInstruct(inst);

            if(bot.fail()){
                if(!scent[x][y]){
                    scent[x][y] = true;
                    bot.recovery();
                    break;
                } else {
                    bot.recovery();
                }
            }
        }

        bot.print();
    }
    return 0;
}

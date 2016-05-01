#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct Point{
    int x;
    int y;
    int time;
};

int n, m, si, sj, ei, ej;
int moves[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char prison[200][200];
bool isVisited[200][200];
priority_queue<Point> findStack;

bool operator < (Point a, Point b){
    return a.time > b.time;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/skiluo/workspace2/test/test/in.txt", "r", stdin);
    #endif

    while(cin>>n>>m){
        memset(isVisited, false, sizeof(isVisited));
        while(!findStack.empty())
            findStack.pop();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>prison[i][j];
                if(prison[i][j] == 'r'){
                    si = i;
                    sj = j;
                }
                if(prison[i][j] == 'a'){
                    ei = i;
                    ej = j;
                }
            }
        }
        
        Point point;
        point.x = si;
        point.y = sj;
        point.time = 0;
        isVisited[si][sj] = true;
        findStack.push(point);

        Point result;
        result.time = 0;
        while(!findStack.empty()){
            Point now = findStack.top();
            findStack.pop();
            if(now.x == ei && now.y == ej){
                result = now;
                break;
            }
            for(int i=0; i<4; i++){
                int x = now.x + moves[i][0];
                int y = now.y + moves[i][1];
                
                if(x<0 || y<0 || x>=n || y>=m || prison[x][y] == '#' || isVisited[x][y]){
                    continue;
                }
                Point p;
                p.x = x;
                p.y = y;
                if(prison[x][y] == 'x'){
                    p.time = now.time + 2;
                }
                else{
                    p.time = now.time + 1;
                }
                isVisited[x][y] = true;
                findStack.push(p);
            }
        }
        if(result.time != 0){
            cout<<result.time<<endl;
        }
        else{
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
        }
    }
}
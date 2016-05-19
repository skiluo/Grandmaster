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
#define endl '\n'
#define   MAX           100005
#define   MAXN          1000005
#define   maxnode       10
#define   sigma_size    2
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   lrt           rt<<1
#define   rrt           rt<<1|1
#define   middle        int m=(r+l)>>1
#define   LL            long long
#define   ull           unsigned long long
#define   mem(x,v)      memset(x,v,sizeof(x))
#define   lowbit(x)     (x&-x)
#define   pii           pair<int,int>
#define   bits(a)       __builtin_popcount(a)
#define   mk            make_pair
#define   limit         10000

struct Edge{
    int b, next, c;
}edge[2*100005];
int n, m;
int numE = 0;
int head[2*100005];
int option[2*100005];
int vis[2*100005];
int flag[2], cflag[2];
vector<int>  result[2], ans[2];

void addEdge(int a, int b, int c){
    edge[numE] = (Edge){b, head[a], c};
    head[a] = numE++;
}

void dfs(int s, int c, int o){
    vis[s] = 1;
    option[s] = o;
    queue<int> stack, resume;
    stack.push(s);
    
    while(!stack.empty()){
        int now = stack.front(); stack.pop();
        
        if(option[now]){
            result[o].push_back(now);
        }
        resume.push(now);
        for(int e=head[now]; e!=-1; e=edge[e].next){
            int p = edge[e].b;
           
            if(vis[p] && option[now]^option[p]^edge[e].c != c){
                flag[o] = 1;
                break;
            }
            else if(!vis[p]){
                option[p] = option[now]^c^edge[e].c;
                vis[p] = 1;
                stack.push(p);
            }
        }
        if(flag[o]){
            break;
        }
    }
    if(o == 0){
        while(!resume.empty()){
            vis[resume.front()] = 0;
            resume.pop();
        }
    }
}

void solve(int color){
    mem(vis, 0);
    for(int i=1; i<=n; i++){
        if(vis[i]){
            continue;
        }
        result[0].clear();
        result[1].clear();
        flag[0] = 0;
        flag[1] = 0;
        dfs(i, color, 0);
        dfs(i, color, 1);
        
        if(flag[0] && flag[1]){
            cflag[color] = 1;
            return;
        }
        int k;
        if(flag[0]){
            k = 1;
        }
        else if(flag[1]){
            k=0;
        }
        else{
            if(result[0].size() < result[1].size()){
                k = 0;
            }
            else{
                k = 1;
            }
        }
        
        for(int i=0; i<result[k].size(); i++){
            ans[color].push_back(result[k][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("/Users/skiluo/workspace2/test/test/in.txt", "r", stdin);
#endif
    mem(head, -1);
    mem(vis, 0);
    mem(flag, 0);
    mem(cflag, 0);
    
    cin>>n>>m;
    int a, b;
    char c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        addEdge(a, b, (c=='R')?1:0);
        addEdge(b, a, (c=='R')?1:0);
    }

    solve(0);
    solve(1);
    
    if(cflag[0] && cflag[1]){
        cout<<-1<<endl;
    }
    else{
        int k;
        if(cflag[0]){
            k = 1;
        }
        else if(cflag[1]){
            k = 0;
        }
        else{
            if(ans[0].size() < ans[1].size()){
                k = 0;
            }
            else{
                k = 1;
            }
        }
        cout<<ans[k].size()<<endl;
        for(int i=0; i<ans[k].size(); i++){
            cout<<ans[k][i]<<" ";
        }
    }
    return 0;
}



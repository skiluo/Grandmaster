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

int s[15];
int t, n, prevc=0;
vector<int> stack;
vector<vector<int> > answer;

void dfs(int pos, int sum){
    if(sum < 0){
        return;
    }
    if(sum == 0){
        answer.push_back(stack);
        return;
    }
    for(int i=pos+1; i<n; i++){
        if(s[i] == prevc){
            continue;
        }
        stack.push_back(s[i]);
        dfs(i, sum-s[i]);
        prevc = s[i];
        stack.pop_back();
    }
}

void pout(vector<int> a){
    for(int i=0; i<a.size()-1; i++){
        cout<<a[i]<<"+";
    }
    cout<<a.back()<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/skiluo/workspace2/test/test/in.txt", "r", stdin);
    #endif
    while(cin>>t>>n){
        if(n == 0){
            break;
        }
        cout<<"Sums of "<<t<<":"<<endl;
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        dfs(-1, t);
        if(answer.size() == 0){
            cout<<"NONE"<<endl;
        }
        else{
            vector<int> prev = answer[0];
            pout(prev);
            for(int i=1; i<answer.size(); i++){
                prev = answer[i];
                pout(prev);
            }
            
        }
        answer.clear();
        stack.clear();
        memset(s, 0, sizeof(s));
        prevc=0;
    }
}
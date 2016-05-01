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

bool isPrime(unsigned int n){
    if(n < 2){
        return true;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int n;
bool hashA[20];
vector<int> primes;
vector<int> answer;
vector<vector<int> > answers;

void findPrime(int n){
    for(int i=3; i<n; i++){
        if(i%2 & 1){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
    }
}

bool find(vector<int> in, int s){
    return find(in.begin(), in.end(), s) != in.end();
}

void dfs(int x){
    answer.push_back(x);
    hashA[x] = true;
    if(answer.size() == n){
        if(isPrime(answer.back() + 1)){
            answers.push_back(answer);
        }
    }
    int prev = answer.back();
    for(int i=2; i<=n; i++){
        if(hashA[i] || !find(primes, prev+i)){
            continue;
        }
        dfs(i);
    }
    answer.pop_back();
    hashA[x] = false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/skiluo/workspace2/test/test/in.txt", "r", stdin);
    #endif
    int index = 1;
    while(cin>>n){
        primes.clear();
        answer.clear();
        answers.clear();
        memset(hashA, 0, 20);
        
        findPrime(2*n);
        if((n&1) == 0){
            dfs(1);
        }
        
        printf("Case %d:\n", index++);
        for(int i=0; i<answers.size(); i++){
            vector<int> out = answers[i];
            for(int j=0; j<out.size(); j++){
                if(j==out.size()-1){
                    printf("%d\n",out[j]);
                }
                else{
                    printf("%d ",out[j]);
                }
            }
        }
        printf("\n");
    }
}



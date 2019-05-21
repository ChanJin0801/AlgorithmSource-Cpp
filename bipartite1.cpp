#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n,m,k,s;

bool dfs(int x){
    for(int i=0; i<a[x].size(); i++){
        int t = a[x][i];
        if(c[t]) continue;
        c[t] = true;
        if(d[t] == 0 || dfs(d[t])){
            d[t] = t;
            return true;
        }
    }
    return false;
}

int main(void){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> s;
        for(int j=1; j<=s; j++){
            int t;
            cin >> t;
            a[i].push_back(t);
        }
    }
    int count = 0;

    for(int i=1; i<=n; i++){
        fill(c, c+MAX, false);
        if(dfs(i)) count ++;
    }
    //일을 두번 할 수 잇는 사람에 한에서 한번 더 수행
    int extra = 0;
    for(int i=1; i<=n; i++ && extra < k){
        fill(c, c+MAX, false);
        if(dfs(i)) extra++;
    }
    
    cout << count + extra << endl;
}

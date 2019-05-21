#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX]; //노드를 점령하고 있는 것을 담아두는
bool c[MAX];
int n = 3, m;

bool dfs(int x){
    for(int i=0; i<a[x].size(); i++){
        int t = a[x][i];
        if(c[t]) continue;
        c[t] = true;
        //점령이 안되었거나 다른 곳으로 이동이 가능한 경우
        if(d[t] == 0 || dfs(t)){
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void){
    a[1].push_back(1);
    a[1].push_back(2);
    a[1].push_back(3);
    a[2].push_back(1);
    a[3].push_back(2);
    int count = 0;
    for(int i=1; i<=n; i++){
        fill(c, c + MAX, false);
        if(dfs(i)) count++;
    }
    cout << count << "개의 매칭이 이루어졌습니다." << endl;
    for(int i=1; i<MAX; i++){
        if(d[i] != 0){
            cout << d[i] << "->" << i << endl;
        }
    }
    return 0;
}

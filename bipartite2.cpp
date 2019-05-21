#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int stat[MAX][3];
int n;

bool dfs(int x){
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        if(c[y]) continue;
        c[y] = true;
        if(d[y]==0 || dfs(d[y])){
            d[y] = x;
            return true;
        }
    }
    return false;
}

int main(void){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> stat[i][0] >> stat[i][1] >> stat[i][2];
    }
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            if(stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]){
                a[i].push_back(j);
            }
            if(stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]){
                a[i].push_back(j);
            }
            if(stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]){
                a[j].push_back(i);
            }
        }
    }
    //잡아먹히게 될 상어의 개수
    int count = 0;
    //최대 2개의 상어를 먹을 수 있음
    for(int k=0; k<2; k++){
        for(int i=1; i<=n; i++){
            fill(c, c+MAX, false);
            if(dfs(i)) count++;
        }
    }
    cout << n-count << endl;
    return 0;


}
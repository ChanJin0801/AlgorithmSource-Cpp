#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
//SCC에서는 stack이 무조건 사용됨.
stack<int> s;

int dfs(int x){
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        //방문하지 않은 이웃, 고유한 번호를 할당받지 못해 0인 경우
        //3 즉, dfs(1)과 dfs(3)을 비교
        if(d[y] == 0) parent = min(parent, dfs(y));
        //처리 중인 이웃
        //2
        else if(!finished[y]) parent = min(parent, d[y]);
    }

    if(parent == d[x]){
        vector<int> scc;
        while(1){
            //거꾸로 진행해 부모가 나올때까지 반복
            //3-2-1
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == x) break;
        }
        SCC.push_back(scc);
    }
    //자신의 부모의 값을 반환
    return parent;
}

int main(void){
    int v = 11;
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[2].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(6);
    a[8].push_back(5);
    a[8].push_back(9);
    a[9].push_back(10);
    a[10].push_back(11);
    a[11].push_back(3);
    a[11].push_back(8);
    for(int i=1; i<=v; i++){
        if(d[i] == 0) dfs(i);
    }
    cout << "SCC의 갯수: " << SCC.size() << endl;
    for(int i=0; i<SCC.size(); i++){
        cout << i+1 << "번째 SCC: ";
        for(int j=0; j<SCC[i].size(); j++){
            cout << SCC[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
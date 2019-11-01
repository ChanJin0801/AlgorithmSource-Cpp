#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, V;
const int MAX = 1001;
int a[MAX][MAX];
int c[MAX];

void DFS(int x){
    //DFS는 처음에 출력
    cout << x << ' ';
    for(int i=1; i<=N; i++){
        if(a[x][i] && !c[i]){
            c[i] = true;
            DFS(i);
        }
    }
}
void BFS(int x){
    queue<int> q;
    q.push(x);
    c[x] = true;
    while(!q.empty()){
        x = q.front();
        q.pop();
        cout << x << ' ';
        for(int i=1; i<=N; i++){
            //if(a[x][i]) === if(1) 이면 조건 충족
            if(a[x][i] && !c[i]){
                c[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    cin >> N >> M >> V;
    for(int i=0; i<M; i++){
        int from, to;
        cin >> from >> to;
        //1은 연결이 되어있다는 의미
        a[from][to] = 1;
        a[to][from] = 1;
    }
    c[V] = true;
    DFS(V);
    cout << endl;
    memset(c, false, sizeof(c));
    BFS(V);
    cout << endl;

    return 0;
}
/*

연결요소의 개수 문제
이어져 있는 선이 몇 개인지 구하는 문제
vector로 그래프 표현
int next = map[node][i];
for(int i=0; i<map[next].size(); i++)
DFS

*/


#include <iostream>
#include <vector>
using namespace std;

int N, M;
const int MAX = 1001;
vector<int> map[MAX];
bool visited[MAX];

void DFS(int node){
    visited[node] = true;
    for(int i=0; i<map[node].size(); i++){
        int next = map[node][i];
        if(!visited[next]){
            DFS(next);
        }
    }
}

int main(void){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int node1, node2; 
        cin >> node1 >> node2;
        map[node1].push_back(node2);
        map[node2].push_back(node1);
    }
    int result = 0;
    //노드니까 1부터 시작
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            DFS(i);
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
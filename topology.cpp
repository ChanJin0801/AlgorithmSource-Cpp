#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge{
public:
    int node;
    int time;
    Edge(int node, int time){
        this->node = node;
        this->time = time;
    }
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX];

void topologySort(){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<a[x].size(); i++){
            Edge y = Edge(a[x][i].node, a[x][i].time);
            //1과 2가 3을 하기 위한 필수조건이라고 가정할때, 1과 2중 더 시간이 많이 걸리는 것으로 업데이트
            //이것 또한 순서를 정하는 과정
            if(result[y.node] <= y.time + result[x]){
                //임계경로(최장거리)로 설정
                result[y.node] = y.time + result[x];
            }
            if(--inDegree[y.node] == 0){
                q.push(y.node);
            }
        }
    }
    int count = 0;
    q.push(finish);
    while(!q.empty()){
        int y = q.front();
        q.pop();
        for(int i=0; i<b[y].size(); i++){
            Edge x = Edge(b[y][i].node, b[y][i].time);
            //최장경로인지 확인
            //result[y] - result[x.node] : y에서 x까지의 최장거리
            if(result[y] - result[x.node] == x.time){
                count++;
                if(c[x.node] == 0){
                    q.push(x.node);
                    c[x.node] = 1;
                }
            }
        }
    }
    cout << result[finish] << ' ' << count << endl;
}

int main(void){
    int m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, node, time;
        cin >> x >> node >> time;
        a[x].push_back(Edge(node, time));
        b[node].push_back(Edge(x, time));
        inDegree[node]++;
    }
    cin >> start >> finish;
    
    cout << '\n';
    topologySort();
}
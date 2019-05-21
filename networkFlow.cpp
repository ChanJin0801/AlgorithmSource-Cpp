#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100
#define INF 1000000000;

using namespace std;

int n = 6, result;
//수용유량, 흐르는 유량, 방문했는지 확인하는 유량
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

//BFS를 사용하는 에드몬드 카프 알고리즘
void maxFlow(int start, int end){
    while(1){
        //방문하지 않은 상태
        fill(d, d+MAX, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            //x의 인접노드를 방문
            for(int i=0; i<a[x].size(); i++){
                //인접노드
                int y = a[x][i];
                //(수용유량 - 흐르는 유량), d[인접노드] == 방문하지 않았다면
                if(c[x][y] - f[x][y] > 0 && d[y] == -1){
                    q.push(y);
                    d[y] = x; //경로 기억
                    if(y == end) break;
                }
            }
        }
        //경로 끝까지 가지 못하는 경우, 즉 경우의 수가 끝난 경우
        if(d[end] == -1) break;

        int flow = INF;
        //d[i]는 자기 이전의 노드
        //5에서 3까지 유량이 1만큼 남은 상태에서 3에서 2로 음의 유량으로 1을 흘려보내주기
        for(int i=end; i != start; i=d[i]){
            //3-2=1
            flow = min(flow, c[d[i]][i] - f[d[i]][i] );
        }
        for(int i=end; i != start; i=d[i]){
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }

        result += flow;

    }
}

int main(void){
    a[1].push_back(2);
    a[2].push_back(1);
    c[1][2] = 12;

    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4] = 11;

    a[2].push_back(3);
    a[3].push_back(2);
    c[2][3] = 6;

    a[2].push_back(4);
    a[4].push_back(2);
    c[2][4] = 3;

    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5] = 5;

    a[2].push_back(6);
    a[6].push_back(2);
    c[2][6] = 9;

    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6] = 8;

    a[4].push_back(5);
    a[5].push_back(4);
    c[4][5] = 9;

    a[5].push_back(3);
    a[3].push_back(5);
    c[5][3] = 3;

    a[5].push_back(6);
    a[6].push_back(5);
    c[5][6] = 4;

    maxFlow(1, 6);
    cout << result << ' ';

}

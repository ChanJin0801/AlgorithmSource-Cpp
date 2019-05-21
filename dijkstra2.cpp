#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 10000000;
//간선정보
vector<pair<int, int> > a[7];
//최단거리
int d[7];

void dijkstra(int start){
    d[start] = 0;
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, start));
    while(!pq.empty()){
        //second 원소 위치 처음에는 current=0
        int current = pq.top().second;
        //first는 거리, 짧은 것이 먼저 모도록 음수화, distance=0으로 시작
        int distance = -pq.top().first;
        pq.pop();
        //1에서 3으로 바로 가는 게 더 빠른지 아님 4를 거치고 가는 데 더 빠른지
        if(d[current] < distance) continue;
        for(int i=0; i<a[current].size(); i++){
            //current와 연결된 노드
            int next = a[current][i].second;  
            //current를 거쳐서 인전노드로 가는 거리
            int nextDistance = distance + a[current][i].first;
            //처음에는 d[next]가 다 무한대로 설정
            if(nextDistance < d[next]){
                d[next] = nextDistance;
                //음수화시켜서 priority queue에 저장(큰 순서대로 저장되기 때문)
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main(void){

    for(int i=1; i<=number; i++){
        d[i] = INF;
    }

    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(5, 3));
    a[1].push_back(make_pair(1, 4));

    a[2].push_back(make_pair(2, 1));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(2, 4));

    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(3, 2));
    a[3].push_back(make_pair(3, 4));
    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(5, 6));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(1, 5));

    a[5].push_back(make_pair(1, 3));
    a[5].push_back(make_pair(1, 4));
    a[5].push_back(make_pair(2, 6));

    a[6].push_back(make_pair(5, 3));
    a[6].push_back(make_pair(2, 5));

    dijkstra(1);

    for(int i=1; i<=number; i++){
        cout << d[i] << ' ';
    }


    return 0;
}
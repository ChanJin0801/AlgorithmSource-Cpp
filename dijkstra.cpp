#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int number = 6;
int INF = 1000000000;

//전체 그래프
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};
//방문한 노드
bool v[6];
//최단거리
int d[6];

//최소거리를 구하는 함수
int getSmallIndex(){
    int min = INF;
    int index = 0;
    for(int i=0; i<number; i++){
        if(d[i] < min && !v[i]){
            min = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start){
    for(int i=0; i<number; i++){
        d[i] = a[start][i];
    }
    v[start] = true;
    for(int i=0; i<number-2; i++){
        int current = getSmallIndex();
        //1과 4를 방문한 상태.
        v[current] = true;
        for(int j=0; j<6; j++){
            if(!v[j]){
                //4를 거쳐서 가는 게 더 짧다면 최단거리 업데이트.
                if(d[current] + a[current][j] < d[j]){
                    d[j] = d[current] + a[current][j];
                }
            }
        }
    }
}

int main(void){
    dijkstra(0);

    for(int i=0; i<number; i++){
        cout << d[i] << ' ';
    }

    return 0;
}
/*
moveDir 동서남북
방문처리 있으면 안됨

q에 모든 익음 토마토 추가

allRipe

q empty
!empty- currentSize(현재 tomato 개수) 이거 다하면 while loop 다시

전부 다 익은 경우
나머지는 BFS

*/

#include <iostream>
#include <queue>
using namespace std;

typedef struct{
    int y, x;
}Dir;
Dir moveDir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int M, N;
const int MAX = 1000;
int map[MAX][MAX];
int noTomato;
queue< pair<int, int> > q;

bool allRipe(void){
    int possible = N * M - noTomato;
    int tomatoNum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 1){
                tomatoNum++;
            }
        }
    }
    return possible == tomatoNum;
}

int BFS(){
    int day = 0;
    /*
    //토마토가 없을 때 && 큐에 아무 것도 안 담겨있을때
    if(q.empty()){
        return -1;
    }
    */
    while(!q.empty()){
        int currentSize = q.size();
        //현재 토마토의 개수만큼만(추가된 토마토들은 나중에 while loop 다시 돔)
        for(int i=0; i<currentSize; i++){
            //현재 익은 토마토의 자리
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int j=0; j<4; j++){
                int nextY = y + moveDir[j].y;
                int nextX = x + moveDir[j].x;
                if(0 <= nextY && nextY < N && 0 <= nextX && nextX < M && map[nextY][nextX] == 0){
                    map[nextY][nextX] = 1;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
        if(q.size() == 0 && !allRipe()){
            return -1;
        }
        if(q.size() == 0 && allRipe()){
            return day;
        }
        //day 위치가 끝에 가야됨
        //만역 앞에 있으면 다 익은 상태인데 1을 더하고 리턴하는 상황 
        day++;
    }
}

int main(void){
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            //토마토가 없으면 noTomato 추가
            if(map[i][j] == -1){
                noTomato++;
            }
            //토마토가 익었으면 큐에 추가
            if(map[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }
    cout << BFS() << endl;
    
    return 0;
}
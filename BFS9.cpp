/*

lab temp 생성

afterSpread 생성
q에 감염된 곳 추가
BFS 수행
empty count

void makeWall()
재귀함수

*/


#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct{
    int y, x;
}Dir;
Dir moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int N, M;
const int MAX = 8;
//처음 입력한 맵의 상태
int lab[MAX][MAX];
//벽돌을 추가한 후의 맵의 상태
int temp[MAX][MAX];
int result = 0;

void BFS(void){
    //temp와 같은 afterSpread 생성
    int afterSpread[MAX][MAX];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            afterSpread[i][j] = temp[i][j];
        }
    }
    queue< pair<int, int> > q;
    //감염된 곳을 큐에 추가
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(afterSpread[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }
    //BFS 수행
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nextY = y + moveDir[i].y;
            int nextX = x + moveDir[i].x;
            if(0 <= nextY && nextY < N && 0 <= nextX && nextX < M){
                if(afterSpread[nextY][nextX] == 0){
                    afterSpread[nextY][nextX] = 2;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
    int empty = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(afterSpread[i][j] == 0){
                empty++;
            }
        }
    }
    //매번 안전영역의 최대치를 result의 값으로 경신
    result = max(result, empty);
}

void makeWall(int cnt){
    if(cnt == 3){
        BFS();
        return;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                makeWall(cnt + 1);
                temp[i][j] = 0;
            }
        }
    }  
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> lab[i][j];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //0 발견 시 맵 복사
            if(lab[i][j] == 0){
                for(int y=0; y<N; y++){
                    for(int x=0; x<M; x++){
                        temp[y][x] = lab[y][x];    
                    }    
                }
                temp[i][j] = 1;
                makeWall(1);
                temp[i][j] = 0;    
            }    
        }    
    }

    cout << result << endl;

    return 0;
}
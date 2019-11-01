/*

BFS
동서남북
queue

*/


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
const int MAX = 101;
int maze[MAX][MAX];
bool visited[MAX][MAX];

typedef struct dir {
    int y, x, pathLength;
} dir;

int minStep(int y, int x, int pathLength){
    queue<dir> q;
    dir start = {y, x, pathLength};
    q.push(start);
    //리턴을 해주려면 loop 밖에서 해줘야함.
    int result = 0;
    //start 시작처리 
    visited[y][x] = true;
    while(!q.empty()){
        int curY = q.front().y;
        int curX = q.front().x;
        int curLength = q.front().pathLength;
        if(curY == N-1 && curX == M-1){
            result = curLength;
            //break;
        }
        q.pop();

        //E
        if(curX+1 < M && maze[curY][curX+1] && !visited[curY][curX+1]){
            dir east = { curY, curX+1, curLength+1 };
            q.push(east);
            visited[curY][curX+1] = true;
        }
        //W
        if(curX-1 >= 0 && maze[curY][curX-1] && !visited[curY][curX-1]){
            dir west = { curY, curX-1, curLength+1 };
            q.push(west);
            visited[curY][curX-1] = true;
        }
        //S
        if(curY+1 < N && maze[curY+1][curX] && !visited[curY+1][curX]){
            dir south = { curY+1, curX, curLength+1};
            q.push(south);
            visited[curY+1][curX] = true;
        }
        //N
        if(curY-1 >= 0 && maze[curY-1][curX] && !visited[curY-1][curX]){
            dir north = { curY-1, curX, curLength+1};
            q.push(north);
            visited[curY-1][curX] = true;
        }
    }
    return result;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<M; j++){
            maze[i][j] = temp[j]-'0';
        }
    }
    //memset(visited, false, sizeof(visited));
    cout << minStep(0, 0, 1) << endl; 

    return 0;
}
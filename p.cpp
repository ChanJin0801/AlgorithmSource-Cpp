#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
const int MAX = 101;
int map[MAX][MAX];
bool visited[MAX][MAX];

typedef struct{
    int y, x, pathLength;
}Dir;

int minStep(int y, int x, int pathLength){
    queue<Dir> q;
    Dir start = {y, x, pathLength};
    q.push(start);
    int result = 0;
    while(!q.empty()){
        int curY = q.front().y;
        int curX = q.front().x;
        int curLength = q.front().pathLength;
        if(curY < N-1 && curX < M-1){
            result = curLength;
            break;
        }
        q.pop();
        visited[y][x] = true;
        if(curY + 1 <= N && map[curY+1][curX] && !visited[curY+1][curX] ){
            Dir east = { curY+1, curX, pathLength+1};
            q.push(east);
            visited[curY+1][curX] = true;
        }

    }


}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<M; j++){
            map[i][j] = temp[j]-'0';
        }
    }

    return 0;
}
/*
동서남북
DFS
큰 for loop 안에
*/


#include <iostream>
#include <cstring>
using namespace std;

typedef struct{
    int y, x;
}Dir;
Dir moveDir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
const int MAX = 50;

int M, N, vege;
int map[MAX][MAX];
bool visited[MAX][MAX];

void DFS(int y, int x){
    //if(visited[y][x]) return;
    visited[y][x] = true;
    for(int i=0; i<4; i++){
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;
        if(0 <= nextY && nextY < N && 0 <= nextX && nextX < M){
            if(map[nextY][nextX] == 1 && !visited[nextY][nextX]){
                DFS(nextY, nextX);
            }
        }
    }
}


int main(){
    int number;
    cin >> number;
    for(int i=0; i<number; i++){
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> vege;
        for(int j = 0; j<vege; j++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        int worm = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(map[j][k] == 1 && !visited[j][k]){
                    DFS(j,k);
                    worm++;
                }
            }
        }

        cout << worm << endl;
    }

    return 0;
}
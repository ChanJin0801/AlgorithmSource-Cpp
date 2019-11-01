/*

DFS: number++; 가 포인트
moveDir 동서남북
nextY, nextX

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 25;

typedef struct{
    int y, x;
}Dir;
Dir moveDir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int N;
int cnt;
vector<int> residence;
bool visited[MAX][MAX];
//string으로 설정해야 graph[i][j]가 가능해짐.
string graph[MAX];

void DFS(int y, int x){
    //처음 칸은 1로 시작 && 다음 칸으로 이동할때마다 1씩 증가.
   cnt++;
   visited[y][x] = true;
   for(int i=0; i<4; i++){
       int nextY = y + moveDir[i].y;
       int nextX = x + moveDir[i].x;
       //범위 안에 있고
       if(0 <= nextY && nextY < N && 0 <= nextX && nextX < N){
           //갈 수 있는 곳이고 방문하지 않은 곳이면 DFS 수행
           if(graph[nextY][nextX] == '1' && !visited[nextY][nextX]){
               DFS(nextY, nextX);
           }
       }
   }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> graph[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            //존재하고 방문하지 않은 곳들만 dfs 수행
            if(graph[i][j] == '1' && !visited[i][j]){
                //번지 수를 0으로 초기화
                cnt = 0;
                DFS(i,j);
                residence.push_back(cnt);
            }
        }
    }
    sort(residence.begin(), residence.end());
    cout << residence.size() << endl;
    for(int i=0; i<residence.size(); i++){
        cout << residence[i] << endl;
    }

    return 0;
}



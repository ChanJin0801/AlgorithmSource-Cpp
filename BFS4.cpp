
/*
BFS
queue< pair<loc, time> >
map이 필요 없음

*/


#include <iostream>
#include <queue>
using namespace std;

int N, K;
const int MAX = 1000001;
bool visited[MAX];

int minTime(int N, int K){
    queue< pair<int, int> > q;
    q.push(make_pair(N,0));
    visited[N] = true;
    while(!q.empty()){
        int curLoc = q.front().first;
        int curTime = q.front().second;
        q.pop();
        if(curLoc == K){
            return curTime;
        }
        if(curLoc+1 < MAX && !visited[curLoc+1]){
            q.push(make_pair(curLoc+1, curTime+1));
            visited[curLoc+1] = true;
        }
        if(curLoc-1 >= 0 && !visited[curLoc-1]){
            q.push(make_pair(curLoc-1, curTime+1));
            visited[curLoc-1] = true;
        }
        if(curLoc*2 < MAX && !visited[curLoc*2]){
            q.push(make_pair(curLoc*2, curTime+1));
            visited[curLoc*2] = true;
        }
    }
}

int main(void){
    cin >> N >> K;
    cout << minTime(N, K) << endl;

    return 0;
}
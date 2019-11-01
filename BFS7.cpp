/*

경로 찾기: 플로이드 마샬 문제
거챠서 갈수 있으면 1로 표시.

*/


#include <iostream>
using namespace std;
int N;
const int MAX = 1001;
int map[MAX][MAX];

void floyd(void){
    //모든 자리를 다 검사해야되기 때문에 <N 으로 표현
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][k] && map[k][j]){
                    map[i][j] = 1;
                }
            }
        }
    }
}

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
    //map[i][j]가 1이면 그냥 바로 출력하면됨.
    floyd();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
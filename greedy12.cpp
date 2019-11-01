/*

input은 string 형태

XOR(int y, int x)
    for(int i=y; i<y+3; i++)

int result = 0; bool change = false;
if(N>=3 && M>=3)
    for(int i=0; i<=N-3; i++)
        for(int j=0; j<=M-3; M++)
else

*/


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 50;
bool arr[MAX][MAX];
bool result[MAX][MAX];
int N, M;

void XOR(int x, int y){
    //i, j가 어디서 시작하든간에 무조건 3칸씩 이동
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            int temp = arr[i][j];
            arr[i][j] = 1 - temp;
        }
    }
}

int main(void){
    cin >> N >> M;
    //입력값
    //0000은 하나의 string으로 간주
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<temp.length(); j++){
            if(temp[j] == '0'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }
    //결과값
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        for(int j=0; j<temp.length(); j++){
            if(temp[j] == '0'){
                result[i][j] = 0;
            }
            else{
                result[i][j] = 1;
            }
        }
    }
    //N과 M이 둘다 3보다 커야지 XOR 가능.
    int cnt = 0;
    bool change = false;
    if(N>=3 && M>=3){
        //xor는 3칸까지 커버하기에 -3을 해줘야함.
        //부등호 주의!!
        for(int i=0; i<=N-3; i++){
            for(int j=0; j<=M-3; j++){
                if(arr[i][j] != result[i][j]){
                    XOR(i, j);
                    cnt++;
                }
                bool same = true;
                for(int x=0; x<N; x++){
                    for(int y=0; y<M; y++){
                        if(arr[x][y] != result[x][y]){
                            same = false;
                            break;
                        }
                    }
                }
                if(same){
                    change = true;
                    break;
                }
            }
            if(change){
                break;
            }
        }
    }
    //N 또는 M이 3보다 작은 경우
    else{
        change = true;
        for(int x=0; x<N; x++){
            for(int y=0; y<M; y++){
                if(arr[x][y] != result[x][y]){
                    change = false;
                }
            }
        }
    }

    if(change){
        cout << cnt << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
/*

재귀함수

*/

#include <iostream>
using namespace std;

int N;
const int MAX = 6;
int arr[13];
int lotto[MAX];

void printLotto(int idx1, int idx2){
    if(idx2 == MAX){
        for(int i=0; i<MAX; i++){
            cout << lotto[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i=idx1; i<N; i++){
        lotto[idx2] = arr[i];
        printLotto(i+1, idx2+1);
    }
}

int main(void){

    while(1){
        cin >> N;
        if(N == 0){
            break;
        }
        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
        printLotto(0,0);
        cout << endl;
    }

    return 0;
}
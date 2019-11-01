#include <iostream>
using namespace std;
int N;
const int MAX = 10;
int line[MAX];

int main(void){
    cin >> N;
    //키가 1인 사람부터 N까지의 사람
    for(int i=1; i<=N; i++){
        int left;
        cin >> left;
        //자리를 loop 돌면서
        for(int j=0; j<N; j++){
            if(left == 0 && line[j] == 0){
                line[j] = i;
                break;
            }
            else if(line[j] == 0){
                left--;
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << line[i] << ' ';
    }
    cout << endl;

    return 0;
}
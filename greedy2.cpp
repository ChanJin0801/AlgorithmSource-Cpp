#include <iostream>

using namespace std;

int main(){

    int N, K;
    cin >> N >> K;
    int coin[N];
    for(int i=0; i<N; i++){
        cin >> coin[i];
    }
    //int result = 0 필수!
    int result = 0;
    for(int i=N-1; i>=0; i--){
        result += K/coin[i];
        K %= coin[i];
    }

    cout << result << endl;

    return 0;
}
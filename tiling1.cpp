#include <iostream>
#include <algorithm>
using namespace std;

//Dynamic Programming의 원리
//memorization 기법을 사용->시간이 줄어듬
int d[1001];

int dp(int x){
    if(x == 0) return 1;
    if(x == 1) return 0;
    if(x == 2) return 3;
    if(d[x] != 0) return d[x];
    int result = 3 * dp(x-2);
    for(int i=3; i<=x; i++){
        if(i%2==0){
            result += 2 * dp(x-1);
        }
    }
    
    return d[x] = result;
}

int main(void){
    int x;
    cin >> x;
    cout << dp(x) << endl;

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

//Dynamic Programming의 원리
//memorization 기법을 사용->시간이 줄어듬
int d[100];

int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 1;
    if(d[x] != 0) return d[x];
    
    return d[x] = dp(x-1) + dp(x-2);
}

int main(void){
    cout << dp(30) << endl;

    return 0;
}
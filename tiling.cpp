#include <iostream>
#include <algorithm>
using namespace std;

//Dynamic Programming의 원리
//memorization 기법을 사용->시간이 줄어듬

//int d[1001];

/*
int dp(int x){
    if(x==0) return 1;
    if(x==1) return 2;
    if(x==2) return 7;
    if(d[x] != 0) return d[x];

    int result = 2*dp(x-1) + 3*dp(x-2);
    for(int i=3; i<=x; i++){
        result += (dp(x-i)*2) % 1000000007;
    }

    return d[x] = result;
    
}
*/
long long int d[100001][2];

int dp(int x){
    d[0][0] = 0;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 1;
    for(int i=3; i<=x; i++){
        d[i][1] = (d[i-1][1] + d[i-3][0]) % 1000000007;
        d[i][0] = (3*d[i-2][0] + 2*d[i-1][0] + d[i][1]*2) % 1000000007;
    }

    return d[x][0];
}

int main(void){
    int x;
    cin >> x;
    cout << dp(x) << endl;

    return 0;
}
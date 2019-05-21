#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int number = 100000;
int a[100001];

//2의 배수부터 시작해 지워주는 원리 다만 2,3 같은 본인 제외하고 i+i(2i) 부터 시작
void primeNumberSieve(){
    for(int i=2; i<=number; i++){
        a[i] = i;
    }
    for(int i=2; i<=number; i++){
        if(a[i] == 0) continue;
        for(int j=i+i; j<=number; j+=i){
            a[j] = 0;
        }
    }
    for(int i=2; i<=number; i++){
        if(a[i] != 0){
            cout << a[i] << ' ';
        }
    }
}

int main(void){

    primeNumberSieve();

    return 0;
}
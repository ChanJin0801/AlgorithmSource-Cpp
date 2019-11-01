/*

30의 배수는 모든 자리수의 합이 3의 배수고 마지막 자리수가 0이어야함.

*/


#include <iostream>
#include <algorithm>

using namespace std;

//오름차순 정렬
bool cmp(char a, char b){
    if(a > b) {
        return true;
    }
    return false;
}

int main(void){
    string N;
    cin >> N;
    int sum = 0;
    bool zero = false;
    //사실상 숫자의 입력인데 string으로 표현한 것이므로 마지막이 null 값이 아님.
    for(int i=0; i<N.size(); i++){
        sum += (N[i]-'0');
        if(!(N[i]-'0')){
            zero = true;
        }
    }
    if(sum % 3 || !zero){
        cout << -1 << "\n";
    }
    else{
        sort(N.begin(), N.end(), cmp);
        cout << N << "\n";
    }

    return 0;
}
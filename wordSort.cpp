#include <iostream>
#include <algorithm>
using namespace std;

string a[20000];
int n;

int getSum(string a){
    int length = a.length(), sum;
    for(int i=0; i<length; i++){
        if(a[i] - '0' <= 9 && a[i] - '0' >= 0){
            sum += a[i] - '0';
        }
    }
    return sum;
}

bool compare(string a, string b){
    //길이 짧은 것이 우선
    if(a.length() < b.length()){
        return 1;
    }
    else if(a.length() > b.length()){
        return 0;
    }
    //길이가 같은 경우
    else{
        int aSum = getSum(a);
        int bSum = getSum(b);
        if(aSum != bSum){
            return aSum < bSum;
        }
        else{
            //알파벳 순으로 정렬
            return a < b;
        }
    }
}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n, compare);
    for(int i=0; i<n; i++){
        if(i>0 && a[i]==a[i-1]){
            continue;
        }
        else{
            cout << a[i] << endl;
        }
    }
    return 0;
}

/*

char temp
string sign
vector<int> maxNum, minNum

for
while

*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
string sign;
vector<int> maxNum, minNum;

bool valid(vector<int> v){
    for(int i=0; i<sign.length(); i++){
        if(sign[i] == '>' && v[i] < v[i+1]){
            return false;
        }
        if(sign[i] == '<' && v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        char temp;
        cin >> temp;
        sign += temp;
    }
    //숫자는 부등호보다 무조건 1이 큼.
    //최대값
    for(int i=9; i>9-(N+1); i--){
        maxNum.push_back(i);
    }
    while(1){
        if(valid(maxNum)){
            break;
        }
        prev_permutation(maxNum.begin(), maxNum.end());
    }
    //최소값
    for(int i=0; i<N+1; i++){
        minNum.push_back(i);
    }
    while(1){
        if(valid(minNum)){
            break;
        }
        next_permutation(minNum.begin(), minNum.end());
    }

    for(int i=0; i<maxNum.size(); i++){
        cout << maxNum[i];
    }
    cout << endl;
    for(int i=0; i<minNum.size(); i++){
        cout << minNum[i];
    }
    cout << endl;

    return 0;
}

/*

string은 array 가능
s1과 s2의 길이 차이로 loop을 돌리고 
int diff = 0 ㅇㅟ치 조심
나머지 알파벳은 같은 것으로 간주해 다른 수만큼 계산

*/


#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
string s1, s2;
int result;

int minDiff(string s1, string s2){
    for(int i=0; i<=s2.length()-s1.length(); i++){
        //diff 위치가 loop 안에 있어야지 리셋될 수 있음.
        int diff = 0;
        for(int j=0; j<s1.length(); j++){
            if(s1[j] != s2[j+i]) diff++;
        }
        result = min(result, diff);
    }
    return result;
}

int main(void){
    cin >> s1 >> s2;
    result = INF;
    cout << minDiff(s1, s2) << endl;

    return 0;
}
/*

string은 array 가능
'-' 부호 뒤에는 무조건 다 마이어스 처리해주면 됨.
for loop
if 부호일 때 continue
나머지는 temp += str[i]

*/



#include <iostream>
#include <string>
using namespace std;

string str;

int minVal(void){
    int result = 0;
    bool minus = false;
    string temp = " ";
    //string은 마지막이 null 값이므로 <= 으로 처리
    for(int i=0; i<=str.length(); i++){
        //부호일 때
        if(str[i] == '+' || str[i] == '-' || str[i] == '\0'){
            if(minus){
                result -= stoi(temp);
            }
            else{
                result += stoi(temp);
            }
            if(str[i] == '-'){
                minus = true;
            }
            //부호가 나올 때 다음 수 미리 초기화
            temp = " ";
            //부호일 경우는 continue로 for loop으로 점프
            continue;
        }
        //부호가 아닌 숫자일 때
        temp += str[i];
    }
    return result;
}

int main(void){
    cin >> str;
    cout << minVal() << endl;
    
    return 0;
}
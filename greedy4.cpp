#include <iostream>

using namespace std;

int result = 0;
int money;

int changeM(void){

    money = 1000 - money;
    int change[6] = {500, 100, 50, 10, 5, 1};
    for(int i=0; i<sizeof(change); i++){
        result += money/change[i];
        money %= change[i];
        //sizeof()ㄹㅡㄹ 쓸 경우 break 필수!!
        if(money == 0) break;
    }

    return result;

}

int main(void){

    cin >> money;
    cout << changeM() << endl;

    return 0;
}


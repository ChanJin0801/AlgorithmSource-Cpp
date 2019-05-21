#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void){
    //pop은 튕겨버리기 혹은 빼버리기
    stack<int> s;
    s.push(7);
    s.push(5);
    s.push(4);
    s.pop();
    s.push(6);
    s.pop();
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}
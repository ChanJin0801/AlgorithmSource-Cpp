#include <iostream>
#include <algorithm>

using namespace std;

/*
bool compare(int a, int b){
    //a가 더 작아여 true 값을 리턴
    return a < b;
}
*/

int main(void){
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a+10);
    for(int i=0; i<10; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
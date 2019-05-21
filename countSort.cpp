#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int temp;
    int count[5];
    int array[30] = {1,3,2,4,5, 5,4,3,2,1, 1,4,3,2,5, 1,2,3,4,5, 1,4,3,2,5, 1,4,3,2,5};

    for(int i=0; i<5; i++){
        count[i] = 0;
    }
    for(int i=0; i<30; i++){
        //array[i]이 나오면 count를 하나씩 올리기
        count[array[i] - 1]++;
    }
    for(int i=0; i<5; i++){
        if(count[i] != 0){
            for(int j=0; j<count[i]; j++){
                cout << i+1 << ' ';
            }
        }
    }


}
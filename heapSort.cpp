#include <iostream>
#include <algorithm>
using namespace std;

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};


//완전 이진트리인 경우 
int main(void){
    //최대 힙(상향식 힙) 정렬 구조 만들기
    for(int i=1; i<number; i++){
        int c = i;
        do{
            int root = (c-1)/2;
            if(heap[root] < heap[c]){
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        }
        while(c != 0);
    }
    //큰 값과 맨 뒤에 값을 일단 바꾸고 다시 힙 정렬 반복
    for(int i=number-1; i>=0; i--){
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do{
            c = 2*root + 1;
            //좀 더 큰 자식이랑 스와핑
            if(heap[c] < heap[c+1] && c < i-1){
                c++;
            }
            if(heap[root] < heap[c] && c < i){
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        }
        while(c < i);
    }

    for(int i=0; i<number; i++){
        cout << heap[i] << ' ';
    }

}

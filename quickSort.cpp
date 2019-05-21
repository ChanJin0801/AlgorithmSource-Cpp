#include <stdio.h>

int number = 10;
int data[10] = {1,10,5,8,7,6,4,3,2,9};

void show(){
    int i;
    for(i = 0; i<number; i++){
        printf("%d ", data[i]);
    }
}

void quickSort(int *data, int start, int end){
    if(start >= end){
        return;
    }
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while(i <= j){//엇갈릴 때만
        while(data[i] <= data[key]){ //key보다 더 큰값을 찾아라(앞에서부터 시작)
            i++;
        }
        while(data[j] >= data[key] && j > start){ //key보다 더 작은 값을 찾아라(뒤에서부터 시작)
            j--;
        }
        if(i >= j){ //현재 엇갈려있는 경우 스와핑
            temp = data[key];
            data[key] = data[j];
            data[j] = temp;
        }
        else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j-1);
    quickSort(data, j+1, end);

}

int main(void){

    quickSort(data, 0, number-1);
    show();
    
    return 0;
}
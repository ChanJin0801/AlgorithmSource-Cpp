#include <stdio.h>

int number = 8;
int sorted[8];
int count = 0;

void merge(int a[], int m, int middle, int n){
    int i = m;
    int j = middle+1;
    int k = m;

    //둘로 나누어 앞에 있는 원소들끼리 비교
    while(i<=middle && j<=n){
        if(a[i] < a[j]){
            sorted[k] = a[i];
            i++;
        }
        else{
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    //나머지 남은 원소들 정렬
    //첫번째 집합 다 소진됬으면 남은 건 두번째 집합뿐
    if(i > middle){
        for(int t=j; t<=n; t++){
            sorted[k] = a[t];
            k++;
        }
    }
    //남아 있는 건 첫번째 집합뿐
    else{
        for(int t=i; t<=middle; t++){
            sorted[k] = a[t];
            k++;
        }
    }
    //sorted 배열을 실제 함수로
    for(int t=m; t<=n; t++){
        a[t] = sorted[t];
    }
    
}

void mergeSort(int a[], int m, int n){
    if(m < n){
        int middle = (m+n)/2;
        mergeSort(a, m, middle);
        mergeSort(a, middle+1, n);
        merge(a, m, middle, n);
    }
}

int main(void){
    int array[8] = {7,6,5,8,3,5,9,1};
    mergeSort(array, 0, number-1);
    for(int i=0; i<number; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
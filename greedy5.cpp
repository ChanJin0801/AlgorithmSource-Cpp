


#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int maxWeight(void){
    //10, 15, 20, 25의 경우를 생각
    int weight = 0, result = 0;
    for(int i=0; i<N; i++){
        weight = arr[i];
        for(int j=i+1; j<N; j++){
            //그냥 더해주는 것이 아닌 최소값을 더햐주는 것이기에 arr[i]
            weight += arr[i];
        }
        result = max(result, weight);
    }
    return result;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    cout << maxWeight() << endl;

    return 0;
}
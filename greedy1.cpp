/*
누적값을 계속 더해줘야함
*/


#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000;
int n;
int arr[MAX];

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int time = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            time += arr[j];
        }
    }
    cout << time << endl;
    
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int MAX = 40001;
int cache[MAX];
int connect[MAX];

int portLIS(void){
    cache[1] = connect[1];
    int length = 1;
    for(int i=2; i<=N; i++){
        if(cache[length] < connect[i]){
            cache[++length] = connect[i];
        }
        int idx = lower_bound(cache+1, cache+1+length, connect[i]) - cache;
        cache[idx] = connect[i];
    }

    return length;
}

int main(void){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin  >> connect[i];
    }

    cout << portLIS() << endl;

    return 0;
}
/*

끊어진 기타줄 개수가 6개 이하일 때
이상일 때
범위 주의

*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
const int MAX = 100000;
int package = MAX, unit = MAX;

int main(){

    cin >> N >> K;
    for(int i=0; i<K; i++){
        int packageCost, unitCost;
        cin >> packageCost >> unitCost;
        package = min(package, packageCost);
        unit = min(unit, unitCost);
    }
    if(N <= 6){
        cout << min(package, unit*N) << endl;
    }
    else{
        const int INF = 987654321;
        int result = INF;
        //0(package 개수가 0인 경우)부터 (N/6+1)개수까지
        //범위 주의
        for(int i=0; i<=(N/6+1); i++){
            result = min(result, package*i + unit*max(N-6*i, 0));
        }
        cout << result << endl;
    }

    return 0;
}

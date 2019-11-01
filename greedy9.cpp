/*

pair<int, int> employee[MAX]

서류순위 순서대로 정렬한 다음
서류순위 1등의 면점순위와 나머지 면점순위랑 비교.


*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, num, interviewS;
const int MAX = 100000;
pair<int, int> score[MAX];


int main(){
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        for(int j=0; j<num; j++){
            cin >> score[j].first >> score[j].second;
        }
        sort(score, score+num);
        int result = 1;
        int interviewS = score[0].second;
        for(int j=1; j<num; j++){
            if(score[j].second < interviewS){
                result++;
                interviewS = score[j].second;
            }
        }

        cout << result << endl;
    }

    return 0;
}
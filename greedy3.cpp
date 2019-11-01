/*
vector에 cBegin cEnd 추가
earliest, selected
meetingBegin, mettingEnd
earliest <= meetingBegin(끝나고 바로 시작 가능)

*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int cBegin[1000000]; int cEnd[1000000];

int schedule(void){
   vector< pair<int, int> > order;
   for(int i=0; i<N; i++){
       order.push_back(make_pair(cEnd[i], cBegin[i]));
   }
   sort(order.begin(), order.end());
   int earliest = 0, selected = 0;
   for(int i=0; i<N; i++){
       int meetingBegin = order[i].second, meetingEnd = order[i].first;
       if(earliest <= meetingBegin){
           earliest = meetingEnd;
           selected++;
       }
   }

   return selected;
}

int main(void){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> cBegin[i] >> cEnd[i];
    }

    cout << schedule() << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a, 
            pair<string, pair<int, int> > b){
    if(a.second.first == b.second.first){
        //나이가 더 클수록 생년월일이 커짐. 즉, 큰 값을 리턴 어린사람을 리턴.
        return a.second.second < b.second.second;
    }
    else{
        //점수가 더 큰 사람을 리턴.
        return a.second.first > b.second.first;
    }
}

int main(void){
    vector<pair<string, pair<int, int> > > v;
    v.push_back(pair<string, pair<int, int> >("박찬진", pair<int, int>(90, 19980801) ));
    v.push_back(pair<string, pair<int, int> >("이승준", pair<int, int>(95, 19981026) ));
    v.push_back(pair<string, pair<int, int> >("신동훈", pair<int, int>(90, 19990120) ));
    v.push_back(pair<string, pair<int, int> >("이석주", pair<int, int>(70, 19980525) ));
    v.push_back(pair<string, pair<int, int> >("백민구", pair<int, int>(80, 19980615) ));

    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << ' ';
    }

    return 0;

}
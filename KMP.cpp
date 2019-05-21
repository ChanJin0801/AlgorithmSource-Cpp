#include <iostream>
#include <vector>

using namespace std;

//접두사와 접미사를 찾는 함수
vector<int> makeTable(string pattern){
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j=0;
    for(int i=1; i<patternSize; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i=0; i<parentSize; i++){
        //일치하지 않을 때 j가 한칸씩 뒤로
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        } 
        if(parent[i] == pattern[j]){
            //전체가 다 맞았을 때
            if(j == patternSize-1){
                cout << i-patternSize+2 << "번째에서 찾았습니다." << endl;
                j = table[j];
            }
            //맞고 있는 과정(단어가 일치해가고 있는 과정)
            else{
                j++;
            }
        }
    }
}

int main(void){
    string parent = "ababacabacaabacaabaabacaaba";
    string pattern = "abacaaba";
    KMP(parent, pattern);

    return 0;
}
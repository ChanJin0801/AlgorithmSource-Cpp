#include <iostream>

using namespace std;

void findString(string parent, string pattern){
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int parentHash, patternHash = 0; int power=1;
    for(int i=0; i<=parentSize-patternSize; i++){
        //처음에 맨 앞 칸에서 시작할 때의 설정
        if(i==0){
            for(int j=0; j<patternSize; j++){
                //뒤에서부터 앞으로
                parentHash = parentHash + parent[patternSize-1-j] * power;
                patternHash = patternHash + pattern[patternSize-1-j] * power;
                if(j < patternSize-1) power *= 2;
            }
        }
        else{
            //뒤로 한칸씩 밀리기에 곱하기 2
            parentHash = 2* (parentHash - parent[i-1]*power) + parent[patternSize-1+i];
        }
        if(parentHash == patternHash){
            bool finded = true;
            //hash 값이 우연치 않게 일치했을 경우를 대비해 하나하나 다 비교
            for(int j=0; j<patternSize; j++){
                if(parent[i+j] != pattern[j]){
                    finded = false;
                    break;
                }
            }
            if(finded){
                cout << i+1 << "번째에서 발생했습니다." << endl;
            }
        }
    }
}

int main(void){
    string parent = "ababacabacaabacaabaabacaaba";
    string pattern = "abacaaba";
    findString(parent, pattern);

    return 0;
}
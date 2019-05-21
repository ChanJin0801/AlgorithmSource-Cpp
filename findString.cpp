#include <iostream>

using namespace std;

int findString(string parent, string pattern){
    int parentSize = parent.size();
    int patternSize = pattern.size();
    for(int i=0; i <= parentSize-patternSize; i++){
        bool finded = true;
        for(int j=0; j < patternSize; j++){
            if(parent[i+j] != pattern[j]){
                finded = false;
                break;
            }
        }
        if(finded){
            //몇 번째에서 문자열이 겹치는지 확인
            return i;
        }
    }
    return -1;
}

int main(void){

    string parent = "Hello World";
    string pattern = "llo W";
    int result = findString(parent, pattern);

    cout << result + 1 << endl;

}
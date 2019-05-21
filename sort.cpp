#include <iostream>
#include <algorithm>
using namespace std;

class Student{
public:
    string name; 
    int score;
    Student(string name, int score){
        this->name = name;
        this->score = score;
    }
    bool operator <(Student &student){
        return this->score < student.score;
    }
};

bool compare(Student &a, Student &b){
    //a가 더 작아여 true 값을 리턴
    return a.score < b.score;
}


int main(void){
    Student students[] = {
        Student("박찬진", 90),
        Student("이주신", 87),
        Student("홍은기", 95),
        Student("김찬규", 49),
        Student("박찬빈", 88)
    };
    sort(students, students + 5, compare);
    for(int i=0; i<5; i++){
        cout << students[i].name << ' ';
    }

}
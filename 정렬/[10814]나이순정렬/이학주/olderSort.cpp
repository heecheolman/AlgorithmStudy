#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Student{
public:
    int age;
    string name;
    Student(int age, string name): age(age), name(name){}
};

void print (vector<Student> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].age << " " << v[i].name << "\n";
    }
}

bool compare (Student a, Student b) {
    return a.age < b.age;
}

int main () {
    int N, a;
    string b;
    cin >> N;

    vector<Student> v;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(Student(a, b));
    }

    stable_sort(v.begin(), v.end(), compare);

    print(v);
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a , b ;
    cin >> a >> b ;
    if (a > b) {
        cout << "a is greater than b << endl" ;
    }else if (a == b) {
        cout << "a is equal to b << endl" ;
    }
    else {
        cout << "b is greater than a << endl" ;
    }

    int age ;
    cin >>age;

    if (age < 18) {
        cout << "you cannot apply for job" << endl;
    }else if (age >= 18 && age < 25) {
        cout << "you can apply for job but with restrictions" << endl;
    }
    else {
        cout << "you cannot apply for job" << endl;
    }



}



#include <bits/stdc++.h>
using namespace std ;


// functions 4 types
// void functions -> does not return any value
// return type functions
// parameterised functions
// non parameterised functions

// void name(){
//     cout << "manas" ;
// }

// wont give any output


// int main (){
//     name(); // function call
//     return 0;

//}

// parameterinsed function

// void printnname(string name) {
//     cout << "hey " << name ;
// }

// int main () {
//     string name;
//     cin >> name;
//     printnname(name);
//     return 0;
// }



// addition of two numbers
 
void add (int a, int b) {
    cout << a + b << endl;
}

int main () {
    int a , b ;
    cin >> a >> b;
    add (a,b);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    int sum = 0;
    int revn;
    int ld;
    while (n > 0){
        ld = n % 10;
        sum  = sum + (ld*ld*ld);
        
        revn = revn*10 + ld;
        n = n / 10;
    }
    if (sum == revn){
        cout << "Armstrong Number";
    }
    else{
        cout << "Not an Armstrong Number";
    }
    return 0;

}
#include <bits/stdc++.h>
using namespace std;

void printdivisors(int n){
    vector<int> ls;

    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            ls.push_back(i);

            if (i != n / i){
                ls.push_back(n / i);
            }
        }
    }

    sort(ls.begin(), ls.end());

    for (auto it : ls){
        cout << it << " ";
    }
}

int main () {
    int n;
    cin >> n;
    printdivisors(n);
    return 0;
}



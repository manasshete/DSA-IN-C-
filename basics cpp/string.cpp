#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "manas";
    int len = s.size();
    s[len-1] = 'k'; // modifying last character of string
    cout  << s[len - 1] << endl; // accessing last character of string
    return 0;
}
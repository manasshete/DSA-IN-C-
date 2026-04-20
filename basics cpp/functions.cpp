#include <bits/stdc++.h>
using namespace std;

// --- FUNCTION DEFINITION ---
// 1. "void": Means this machine DOES NOT give a value back to main(). It just does work (prints).
// 2. "add": The name of the function.
// 3. "(int a, int b)": The Parameters. These are empty placeholders waiting for values.
void add(int a, int b) { 
    // The logic happens here
    cout << "Sum is: " << a + b << endl;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2; // Assume user types 5 and 10

    // --- FUNCTION CALL ---
    // We pass the VALUES of 'num1' and 'num2' into the placeholders 'a' and 'b'.
    // num1 (5)  --> copies to --> a
    // num2 (10) --> copies to --> b
    add(num1, num2); 

    return 0;
}
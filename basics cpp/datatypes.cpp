#include <bits/stdc++.h>
using namespace std;

int main() {
    // --- 1. INTEGERS (Whole Numbers) ---
    int a = 10;           // Standard integer (approx -2 billion to +2 billion)
    long long c = 123456; // Very large integer (used in Competitive Programming)
    
    // --- 2. DECIMALS (Floating Point) ---
    float d = 5.5f;       // Low precision (avoid in CP, barely used)
    double e = 10.5555;   // High precision (Standard for math problems)


    // --- 3. STRINGS (Text) ---
    // Rule: 'cin' stops reading when it sees a space!
    string s1, s2;
    cout << "Enter two words (e.g., 'Hello World'): ";
    cin >> s1 >> s2; 
    cout << "Word 1: " << s1 << "  Word 2: " << s2 << endl;  


    // --- 4. THE GETLINE PROBLEM (Important!) ---
    // 'cin' leaves the "Enter" key (\n) in the buffer. 
    // 'getline' sees that "Enter" immediately and thinks the line is finished.
    // We must "ignore" that leftover Enter key before using getline.
    
    string str;
    cout << "Enter a full sentence: ";
    cin.ignore(); // <--- FIX: Throws away the leftover 'Enter' from previous cin
    getline(cin, str); 
    cout << "Sentence: " << str << endl;


    // --- 5. CHARACTERS (Single Symbols) ---
    // Rule: char uses SINGLE quotes ('a'), string uses DOUBLE quotes ("a")
    
    char character1 = 'a'; 
    cout << "Char 1: " << character1 << endl;

    // We changed the name to 'strChar' because 'character1' (or 'ch') is already used above.
    // You cannot have two variables with the same name!
    string strChar = "g"; 
    cout << "String masquerading as char: " << strChar << endl;

    return 0;
}
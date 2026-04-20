#include <bits/stdc++.h>
using namespace std;

int main() {
    int day , motnth , year ;
     cout << "enter day number (1-7): " ;
    cin >> day ;
    switch (day) {
        case 1 :
            cout << "monday" << endl;
            break;
        case 2 : 
            cout << "tuesday" << endl;
            break;
        case 3:
             cout << "wednesday" << endl;
                break;
        case 4:
             cout << "thursday" << endl;
                break;
        case 5:
             cout << "friday" << endl;
                break;
        case 6:
             cout << "saturday" << endl;
                break;
        case 7:
             cout << "sunday" << endl;
                break;
        default:
            cout << "invalid day" << endl;
            break;
    
    }
    cout << "enter month number (1-12): " ;
    cin >> motnth ;
    switch (motnth) {
        case 1 :
            cout << "january" << endl;
            break;
        case 2 : 
            cout << "february" << endl;
            break;
        case 3:
             cout << "march" << endl;
                break;
        case 4:
             cout << "april" << endl;
                break;
        case 5:
             cout << "may" << endl;
                break;
        case 6:
             cout << "june" << endl;
                break;
        case 7:
             cout << "july" << endl;
                break;
        case 8:
             cout << "august" << endl;
                break;
        case 9:
             cout << "september" << endl;
                break;
        case 10:
             cout << "october" << endl;
                break;
        case 11:
             cout << "november" << endl;
                break;
        case 12:
             cout << "december" << endl;
                break;        
        default:
            cout << "invalid month" << endl;
            break;
    
    }

    return 0;

}
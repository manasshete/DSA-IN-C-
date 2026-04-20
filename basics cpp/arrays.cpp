#include <bits/stdc++.h>
using namespace std;

int main() {
    // --- PART 1: 1D ARRAY ---
    
    // Declare an array of size 5.
    // Think of this as reserving 5 lockers side-by-side, numbered 0 to 4.
    int arr[5]; 

    // Read 5 inputs from the user and fill the lockers one by one.
    // arr[0] is the first number, arr[4] is the last.
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    // Modify specific elements using their index (position).
    arr[2] += 100; // Go to the 3rd locker (index 2) and add 100 to the value inside.
    arr[0] += 50;  // Go to the 1st locker (index 0) and add 50 to the value inside.

    // Print all the values in the array to see the changes.
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;


    // --- PART 2: 2D ARRAY ---

    // Declare a 2D array (Matrix) with 3 Rows and 4 Columns.
    // Think of this as a spreadsheet or a grid.
    int arr2d[3][4];

    // Read inputs row by row.
    // arr2d[row_number][column_number]
    cin >> arr2d[0][0] >> arr2d[0][1] >> arr2d[0][2] >> arr2d[0][3]; // Fill Row 0
    cin >> arr2d[1][0] >> arr2d[1][1] >> arr2d[1][2] >> arr2d[1][3]; // Fill Row 1
    cin >> arr2d[2][0] >> arr2d[2][1] >> arr2d[2][2] >> arr2d[2][3]; // Fill Row 2

    // Modify a specific cell in the grid.
    // Go to Row index 1 (the 2nd row) and Column index 2 (the 3rd column).
    arr2d[1][2] += 500;

    // Print ONLY the first row (Row 0).
    // Note: The change we made above (to Row 1) will NOT be seen in this output.
    cout << arr2d[0][0] << " " << arr2d[0][1] << " " << arr2d[0][2] << " " << arr2d[0][3] << endl;

    return 0;
}
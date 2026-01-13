#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    arr[2] += 100;
    arr[0] += 50;
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;


    //2d array
    int arr2d[3][4];
    cin >> arr2d[0][0] >> arr2d[0][1] >> arr2d[0][2] >> arr2d[0][3];
    cin >> arr2d[1][0] >> arr2d[1][1] >> arr2d[1][2] >> arr2d[1][3];
    cin >> arr2d[2][0] >> arr2d[2][1] >> arr2d[2][2] >> arr2d[2][3];
    arr2d[1][2] += 500;
    cout << arr2d[0][0] << " " << arr2d[0][1] << " " << arr2d[0][2] << " " << arr2d[0][3] << endl;

    return 0;
}
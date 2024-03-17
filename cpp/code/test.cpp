#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

// void test(int &a){
//     a = 1;
// }

int main() {
    vector<vector<int>> a = {{1,2}, {1,2}};
    vector<vector<int>> b = a;
    b[1][1] = 100;
    cout << a[1][1];
    a = b;
    cout << a[1][1];
}
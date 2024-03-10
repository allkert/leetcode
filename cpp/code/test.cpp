#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void test(int &a){
    a = 1;
}

int main() {
    int a = 1;
    int b = 2;
    int* ptr1 = &a;
    int* ptr2 = ptr1;
    ptr1 = &b;
    cout<<*ptr2;

}
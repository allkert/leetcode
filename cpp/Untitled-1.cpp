#include <iostream>

using namespace std;
int n, m, lst[10] = {0};
// 函数作用是：从a到b中选出c个数，存入lst数组中
void func(int a, int b, int c)
{
    if (c != 0 && c <= b - a + 1)
    {
        lst[m - c] = a;//作用是将a存入lst数组中
        func(a + 1, b, c - 1);//作用是将a+1存入lst数组中
        func(a + 1, b, c);//作用是将a+1存入lst数组中
    }
    else if (c == 0)
    {
        cout << lst[0];
        for (int j = 1; j < m; ++j)
            cout << ' ' << lst[j];
        cout << endl;
    }

}
int main()
{
    while (cin >> n >> m)
        func(1, n, m);
    return 0;
}
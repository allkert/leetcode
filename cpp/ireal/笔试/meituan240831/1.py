# T是整数
T = int(input())
for i in range(T):
    # 一行输入四个整数
    d1, d2, v1, v2 = map(int, input().split())
    print((d1 - d2)/ (v2 - v1))

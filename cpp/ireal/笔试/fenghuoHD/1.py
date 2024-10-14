# d读入一个数字表示方阵的大小，然后读入一个方阵
import sys
def sqr_gap(n):
    a = n - 1
    b = a ** 0.5
    # b取整
    b = (int)(b)
    return (b + 1)**2 - n


n = int(input())
a = [list(map(int, input().split())) for i in range(n)]
b = [[sqr_gap(a[i][j]) for j in range(n)] for i in range(n)]

# 求b的最小行和 或 最小列和
minSum = sys.maxsize
for i in range(n):
    minSum = min(minSum, sum(b[i]))
    minSum = min(minSum, sum(b[j][i] for j in range(n)))

print(minSum)

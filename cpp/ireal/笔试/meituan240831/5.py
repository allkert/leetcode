



n, q = map(int, input().split())  
# 输入一个长度为n的整数数组
arr = list(map(int, input().split()))
max_ = max(arr)


for _ in range(q):
    l, r = map(int, input().split())
    max1 = max(arr[l - 1:r])
    if(max1 < max_):
        print("lose", end="\n")
        tempIndex = 2 * n
        rtn = 1
        delta = n
        for i in range(0, n):
            if(arr[i] > max1):
                if(i < l - 1 and l - i - 1 < delta):
                    delta = l - i - 1
                    tempIndex = i
                if(i >= r and i - r + 1 < delta):
                    delta = i - r + 1
                    tempIndex = i
        print(r - l + 1 + delta, end="\n")
    else:
        if(arr.count(max_) == 1): 
            print("lose\n")
            if(l == r): print("2\n")
            else: print(r - l + 1, end="\n")
        else:
            print("draw", end="\n")
            print(r - l + 1, end="\n")



        



        

    
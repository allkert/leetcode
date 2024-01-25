# # 递归
# def isPalindrome(x: int) -> bool:
#     x = str(x)
#     l = len(x)
#     if(l<=1):return True
#     elif(x[0]==x[-1]):return isPalindrome(x[1:-1])
#     else:return False

# # 双指针
# def isPalindorme(x: int) -> bool:
#     x = str(x)
#     l = len(x)
#     out = True
#     for i in range(int(l/2)):
#         if x[i]!=x[l-i-1]:
#             out = False
#             break
#     return out

def isPalindorme(x: int) -> bool:
    if x<=0: return False
    r = 0
    while(r < x):
        r = 10*r + x%10
        x = int(x/10)
    return (x == r or x == int(r/10))

print(isPalindorme(12321))
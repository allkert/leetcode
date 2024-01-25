class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        out = []
        tag = 1 if x>=0 else -1
        x = abs(x)
        while(x!=0):
            [x,r]=divmod(x,10)
            out.append(r)
        rev = 0
        for i in range(len(out)):
            rev = rev + out[i]*pow(10,len(out)-i-1)
        if rev < INT_MIN // 10 + 1 or rev > INT_MAX // 10:
            return 0
        return rev if tag==1 else -rev



S = Solution()
print(S.reverse(-123))

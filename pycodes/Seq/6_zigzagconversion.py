# class Solution:
#     def convert(self, s: str, numRows: int) -> str:
        # if numRows < 2: return s
        # res = ["" for _ in range(numRows)]
        # i, flag = 0, -1
        # for c in s:
        #     res[i] += c
        #     if i == 0 or i == numRows - 1: flag = -flag
        #     i += flag
        # return "".join(res)

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows==1):return s
        out = [""]*numRows
        T = 2*numRows - 2
        for i in range(len(s)):
            r = i%T
            line = min(r,T-r)
            out[line]=out[line]+s[i]
        return "".join(out)
S = Solution()
print(S.convert("PAYPALISHIRING",4))
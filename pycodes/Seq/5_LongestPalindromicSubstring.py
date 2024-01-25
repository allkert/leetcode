class Solution:
    def longestPalindrome(self, s: str) -> str:
        out = ''
        length = len(s)
        for i in range(length):
            j = k = i
            while True:
                if(j>=0 and s[j]==s[i]):j=j-1
                else:break
            while True:
                if(k<length and s[k]==s[i]):k=k+1
                else:break
            while True:
                if(j>=0 and k<length):
                    if(s[j]==s[k]):
                        j=j-1
                        k=k+1
                    else:break
                else:break
            if(k-j-1>len(out)):out=s[j+1:k]
        return out
S = Solution()
print(S.longestPalindrome('cbbd'))
            


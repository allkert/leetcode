class Solution():
    def _344(self,s):
        left,right=0,len(s)-1
        while left<right:
            s[left],s[right]=s[right],s[left]
            left+=1
            right-=1

    def _541(self,s,k):
        p = 0
        while p < len(s):
            p2 = p + k
            # Written in this could be more pythonic.
            s = s[:p] + s[p: p2][::-1] + s[p2:]
            p = p + 2 * k
        return s
    
    def LCR122(self, path):
        l=len(path)
        for i in range(l):
            if path[i]==".":
                path=path[:i]+" "+path[i+1:] if i+1<l else path[:i]+" "
        return path

    # 反转字符串中的单词
    def _151_1(self, s):
        return  " ".join(s.split()[::-1])
    
    def _151_2(self, s):
        l=len(s)
        left,right=0,0
        news=""
        while right<l:
            while right<l and s[right]==" ":
                left+=1
                right+=1
            while right<l and s[right]!=" ":
                right+=1
            if left!=right:
                news=s[left:right]+" "+news
                left=right
        return news[:-1]
    
    # LCR 182. 动态口令
    def dynamicPassword(self, password, target):
        return password[target:]+password[:target]

    # 28.找出字符串中第一个匹配项的下标
    """ 
        其实可以把求解next的过程也理解为一个字符串匹配的过程就好理解了 
    """
    def strStr(self, haystack, needle):
        def getnext(s,l):
            next = [0]*l
            i,j=0,1
            while j<l:
                if s[i]==s[j]:
                    next[j]=i+1
                    i+=1
                    j+=1
                elif i!=0:
                    i=next[i-1]
                else:j+=1
            return next
        a,b=len(haystack),len(needle)
        n = getnext(needle,b)
        i,j=0,0
        while j < a and i < b:
            if haystack[j]==needle[i]:
                i+=1
                j+=1
            elif i:i=n[i-1]
            else:j+=1
        return j-b if i==b else -1
    
    # 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
    def repeatedSubstringPattern(self, s):
        def getn(nxt, s):
            nxt[0] = 0
            j = 0
            for i in range(1, len(s)):
                while j > 0 and s[i] != s[j]:
                    j = nxt[j - 1]
                if s[i] == s[j]:
                    j += 1
                nxt[i] = j
            return nxt
        if len(s) == 0:
            return False
        nxt = [0] * len(s)
        getn(nxt, s)
        if nxt[-1] != 0 and len(s) % (len(s) - nxt[-1]) == 0:
            return True
        return False
    
    



            

         

tmp=Solution()
print(tmp.repeatedSubstringPattern("abcabcabc"))

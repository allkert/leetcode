def isMatch(self, s: str, p: str) -> bool:
    if s == p: return True
    elif p[-1] == "*":
        l = len(p)-1
        
        

def getnext(s: str) -> list:
    l = len(s)
    next = [0]*l
    k = 0
    i = 1
    while i<l:
        if s[i] == s[k]:
            k = k + 1
            next[i] = k
            i = i + 1
        elif k == 0:
            next[i] = 0
            i = i + 1
        else:
            k = k - 1
    return next

def kmp(s,p):
    tar,pos = 0
    
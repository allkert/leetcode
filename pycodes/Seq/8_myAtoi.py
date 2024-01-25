def myAtoi(self,s: str) -> int:
    out = '0'
    tag = 0
    begin = False
    for char in s:
        if char ==' ' and not begin:continue
        asc2 = ord(char)
        if asc2 == 45 and not begin:
            tag=-1
            begin = True
        elif asc2 == 43 and not begin:
            tag=1
            begin = True
        elif asc2>=48 and asc2<=57:
            if begin==False:
                tag=1
            begin =True
            out = out + char
        else:break
    if tag == 1: return min(int(out),2**31-1)
    if tag == -1:return -min(int(out),2**31)
    if tag == 0:return 0


print(myAtoi(s = 'ds-af12adfs324'))

name_list = list(map(str, input().split()))
res = 0
for name in name_list:
    # 如果首字母是大写字母
    if name[0].isupper():
        res += 1
print(res)
s = input()
dp = [[0 for i in range(len(s))] for j in range(len(s))]
for i in range(len(s)):
    dp[i][i] = 1

maxlen = 0

for l in range(1, len(s)):
    for i in range(len(s)):
        j = i + l - 1
        if j >= len(s):
            break
        if(s[i] != s[j]):
            dp[i][j] = 0
        else:
            if(j - i < 3):
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i + 1][j - 1]
        if(dp[i][j] and j - i + 1 > maxlen and '0' in s[i:j+1] and '1' in s[i:j+1]):
            maxlen = j - i + 1

print(maxlen)
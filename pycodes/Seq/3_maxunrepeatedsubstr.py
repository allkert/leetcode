# 最长无重复子串长度
class Solution:
    # def lengthOfLongestSubstring(self, s: str) -> int:
    #     s_len = len(s)
    #     if(s_len == 0):
    #         return 0
    #     else:
    #         max_length = 1
    #         i = 0
    #         j = 1
    #         while j < s_len:
    #             tag = 1  # 标记s[j]是否可以加入到无重复字串中
    #             temp_length = j - i
    #             for k in range(i, j):
    #                 if(s[k] == s[j]):
    #                     tag = 0
    #                     i = k + 1
    #                     break
    #             if(tag == 1):
    #                 temp_length = temp_length + 1
    #             max_length = max(max_length, temp_length)
    #             j = j + 1
    #     return max_length

    def lengthOfLongestSubstring(self, s: str) -> int:
        res, i, maxlen = {}, 0, 0
        for j in range(len(s)):
            if s[j] in res:
                if res[s[j]] >= i:
                    i = res[s[j]] + 1
            res[s[j]] = j
            maxlen = max(maxlen, j-i+1)
        return maxlen

t = Solution()
s = "aabaab!bb"
print(t.lengthOfLongestSubstring(s))


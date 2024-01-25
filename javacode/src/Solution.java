/* 
 * leetcode hot 100，
 * 不包含代码随想录中已经出现过的题目
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    public static void main(String[] args){
        int[] a = {0,-1};
        System.out.println(longestConsecutive(a));
    }

    // 49. 字母异位词分组
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        for(String str: strs){
            int[] counts = new int[26];
            StringBuilder key = new StringBuilder();
            for(int i = 0; i < str.length(); i++){
                counts[str.charAt(i)-'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(counts[i] != 0){
                    key.append((char)(i+'a'));
                    key.append(counts[i]);
                }
            }
            List<String> list = map.getOrDefault(key.toString(), new ArrayList<String>());
            list.add(str);
            map.put(key.toString(), list);
        }
        return new ArrayList<List<String>>(map.values());
    }

    // 128. 最长连续序列
    // dp
    public static int longestConsecutive(int[] nums){
        if (nums.length == 0){
            return 0;
        }
        Arrays.sort(nums);
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < nums.length; i++){
            if(nums[i] == nums[i-1]){
                dp[i] = dp[i-1];
            }
            else if(nums[i]-nums[i-1]==1){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 1;
            }
            if (dp[i] > res){
                res = dp[i];
            }
        }
        return res;
    }
}

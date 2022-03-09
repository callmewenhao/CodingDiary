// https://leetcode-cn.com/problems/unique-binary-search-trees/
// DP方法，这题的官方题解不错
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0); // 构造dp数组
        dp[0] = dp[1] = 1; // 边界
        for(int n = 2; n < dp.size(); n++) {
            // 状态转移方程
            for(int i = 1; i <= n; i++) {
                dp[n] += dp[i-1] * dp[n-i];
            }
        }
        return dp.back();
    }
};


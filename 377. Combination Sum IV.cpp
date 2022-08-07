class Solution {
public:
    int ans = 0;
    
    /*void DP(int sum, vector<int> nums, int target, vector<int> & memo){
        if(sum == target){
            ++ans;
            return;
        }else if(sum > target) return;
        
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if(memo[sum] != -1){
                //cout << ans;
                ans += memo[sum];
            }else{
                DP(sum, nums, target, memo);
            }
            if(sum == nums[i]) memo[nums[i]] = ans;
            sum -= nums[i];
            
        }
    }*/
    
    int combinationSum4(vector<int>& nums, int target) {
        /*vector<int> memo(1e3, -1);
        DP(0, nums, target, memo);
        
        return ans;*/
        int n = nums.size();
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            for(int j = 0; j < n; ++j){
                if(i >= nums[j])
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
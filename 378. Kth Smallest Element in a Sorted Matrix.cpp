class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> nums;
        
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                nums.push(matrix[i][j]);
                if(nums.size() > k)  nums.pop();
            }
        }
        
        return nums.top();
    }
};
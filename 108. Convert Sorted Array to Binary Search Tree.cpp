/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* BuildUsingBinarySearch(vector<int>& nums, int l,int r){
        if(l <= r){
            int mid = l + (r-l)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = BuildUsingBinarySearch(nums, l, mid-1);
            root->right = BuildUsingBinarySearch(nums, mid+1, r);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildUsingBinarySearch(nums, 0, nums.size()-1);
    }
};
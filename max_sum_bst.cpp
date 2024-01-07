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
class info
{
    public:
    int mini;
    int maxi;
    bool BST;
    int sum;
};
class Solution {
public:
    info solve(TreeNode* root, int &ans){
        if (root==NULL)
        {
            return {INT_MAX,INT_MIN,true,0};
        }
        info left=solve(root->left,ans);
        info right = solve(root->right,ans);
        
        info curr;
        curr.sum = left.sum + right.sum + root->val;
        curr.mini = min(root->val,left.mini);
        curr.maxi = max(root->val,right.maxi);
        if(left.BST && right.BST && (left.maxi < root->val) && (right.
        mini>root->val))
        {
            curr.BST = true;
        }
        else
        {
            curr.BST = false;
        }
        
        if(curr.BST)
        {
            ans = max(ans,curr.sum);
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) 
    {
        int  maxSum=0;
        solve(root,maxSum);
        return maxSum;
    }
};
// 1CE, 1RE, 1AC, fair well
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeNodeSt {
public:
    TreeNode *ptr;
    int count;
    // 1CE here, forgot to add default value
    TreeNodeSt(TreeNode *_ptr = nullptr) {
        ptr = _ptr;
        count = 0;
    }
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        result.clear();
        stack.clear();
        if(root == nullptr){
            return result;
        }
        
        TreeNodeSt st;
        TreeNode *tmp;
        sp = 0;
        stack.push_back(TreeNodeSt(root));
        // 1RE here, forgot to add sp by 1
        ++sp;
        while(stack.size() > 0){
            if(stack[sp - 1].count >= 2){
                result.push_back(stack[sp - 1].ptr->val);
                stack.pop_back();
                --sp;
                continue;
            }
            if(stack[sp - 1].count == 0){
                ++stack[sp - 1].count;
                if(stack[sp - 1].ptr->left != nullptr){
                    tmp = stack[sp - 1].ptr;
                    stack.push_back(TreeNodeSt(tmp->left));
                    ++sp;
                }
            }else{
                ++stack[sp - 1].count;
                if(stack[sp - 1].ptr->right != nullptr){
                    tmp = stack[sp - 1].ptr;
                    stack.push_back(TreeNodeSt(tmp->right));
                    ++sp;
                }
            }
        }
        stack.clear();
        
        return result;
    }
private:
    vector<TreeNodeSt> stack;
    vector<int> result;
    int sp;
};
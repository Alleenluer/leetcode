/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} rootw
 * @return {number}
 */
var maxDepth = function(root) {
  return root !== null ? Math.max(maxDepth(root.left), maxDepth(root.right)) + 1 : 0;
};

int isLeaf(TreeNode *root){
  if(root->right == NULL && root->left == NULL){
    return 1;
  }
  return 0;
}

int twoChildNode(TreeNode *root){
  if(root == NULL) return 0;
  
  if(isLeaf(root)) return 1;
  
  if(root->right == NULL || root->left == NULL) return 0;
  
  return twoChildNode(root->right) && twoChildNode(root->left);
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SPACE 2

typedef struct TreeNode{
  int data;
  struct TreeNode *left, *right;
}TreeNode;

typedef struct BinaryTree{
  TreeNode* root;
}BinaryTree;

void initTree(BinaryTree* tree){
  tree->root = NULL;
}

TreeNode* createNode(int data){
  TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void freeTree(TreeNode* current){
  if(current == NULL){
    return;
  }
  
  freeTree(current->left);
  freeTree(current->right);
  free(current);
}

void printTree(TreeNode* root, int space, char branch){
  if(root == NULL){
    return;
  }

  space += SPACE;

  // In nhánh phải trước
  printTree(root->right, space, '/');

  // In node hiện tại
  printf("\n");
  for(int i = SPACE; i < space; i++){
    printf(" ");
  }

  if(branch == '/')
    printf("↗ %d\n", root->data);
  else if(branch == '\\')
    printf("↘ %d\n", root->data);
  else
    printf("%d\n", root->data);   // root

  // In nhánh trái
  printTree(root->left, space, '\\');
}

void insertTree(TreeNode** current, int data){
  if((*current) == NULL){
    (*current) = createNode(data);
    return;
  }
  
  if(data < (*current)->data){
    insertTree(&(*current)->left, data);
  }
  else{
    insertTree(&(*current)->right, data);
  }
  
}


int main()
{
    BinaryTree tree;
    initTree(&tree);
    int po[16] = {};
    for(int i = 0; i < 16; i++){
      po[i] = i + 1;
      insertTree(&tree.root, po[i]);
    }
    printTree(tree.root, 0, " ");
    freeTree(tree.root);
    return 0;
}

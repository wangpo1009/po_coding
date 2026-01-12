/*
tree 2:
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SPACE 2

//================================== STRUCTING =================================
typedef struct TreeNode{
  int data;
  struct TreeNode *left, *right;
}TreeNode;

typedef struct BinaryTree{
  TreeNode* root;
}BinaryTree;



//=================================== INITING ===================================
void initTree(BinaryTree* tree){
  tree->root = NULL;
}


//================================== TREEING =====================================
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

  printTree(root->right, space, '/');

  // In node hiện tại
  printf("\n");
  for(int i = SPACE; i < space; i++){
    printf("  ");
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

//===================================== INSERTING ====================================

void insertTree(TreeNode** root, int inVal){
  TreeNode* newNode = createNode(inVal);
  
  if((*root) == NULL){
    (*root) = newNode;
    return;
  }
  
  if((*root)->data < inVal){
    insertTree(&(*root)->right, inVal);
  }
  if((*root)->data > inVal){
    insertTree(&(*root)->left, inVal);
  }
}


int main()
{
    BinaryTree tree;
    initTree(&tree);
    int po[MAX] = {50, 17, 76, 9, 23, 54, 14, 19, 72, 12, 67};
    for(int i = 0; i < 11; i++){
      insertTree(&tree.root, po[i]);
    }
    printTree(tree.root, 0, ' ');
    freeTree(tree.root);
    return 0;
}
/*
        ↗ 9

                ↗ 12

            ↘ 14

    ↗ 17

            ↗ 19

        ↘ 23

50

        ↗ 54

                ↗ 67

            ↘ 72

    ↘ 76
*/

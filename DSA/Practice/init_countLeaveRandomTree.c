#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 0
#define MAX_NODE 10 

typedef struct TreeNode{
  int data;
  struct TreeNode *left, *right;
}TreeNode;

typedef struct BinaryTree{
  TreeNode *root;
}BinaryTree;

TreeNode* createNode(int data){
  TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void freeTree(TreeNode *root){
  if(root == NULL) return ;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

TreeNode* insertSearchTree(TreeNode *root, int data){
  if(root == NULL)
    return createNode(data);

  if(data < root->data)
    root->left = insertSearchTree(root->left, data);
  else
    root->right = insertSearchTree(root->right, data);

  return root;
}

void countLeaveNode(TreeNode *root, int *count){
  if(root == NULL){
    return;
  }
  else if(root->right == NULL && root->left == NULL){
    (*count)++;
    return;
  }
  
  countLeaveNode(root->right, count);
  countLeaveNode(root->left, count);
}

float average(int arr[], int n, int k){
  float sum = 0;
  for(int i = 0; i < n; i++){
    sum += (float)arr[i] * (float)i;
  }
  return sum/k;
}

int main(){
  time_t t;
  srand((unsigned)time(&t));
  
  BinaryTree tree;
  tree.root = NULL;
  int freqTab[MAX_NODE+1] = {};
  int k = 1000;
  
  for(int i = 0; i < k; i++){
    int count = 0;
    tree.root = NULL;
    for(int j = 0; j < MAX_NODE; j++){
      int data = MIN + rand() % (MAX - MIN + 1);
      tree.root = insertSearchTree(tree.root, data);
    }
    
    countLeaveNode(tree.root, &count);
    freqTab[count]++;
    freeTree(tree.root);
  }
  
  printf("Expectation for leaves node: %f", average(freqTab, MAX_NODE, k));
  return 0;
  
}
//Expectation for leaves node: 3.678000





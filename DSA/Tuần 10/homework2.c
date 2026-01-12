/*
tree 1: level ordered tree
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

typedef struct NodeQueue{
  TreeNode* arr[MAX];
  int head, tail;
}NodeQueue;

//=================================== INITING ===================================
void initTree(BinaryTree* tree){
  tree->root = NULL;
}

void initNodeQueue(NodeQueue *q){
  q->head = 0;
  q->tail = -1;
}

//================================== QUEUEING ===================================
void pushNodeQueue(NodeQueue *q, TreeNode* node){
  q->arr[++(q->tail)] = node;
}

TreeNode* getNodeQueue(NodeQueue *q){
  return q->arr[(q->head)++];
}

int isQueueFull(NodeQueue *q){
  if(q->tail == MAX-1) return 1;
  return 0;
}

int isQueueEmpty(NodeQueue *q){
  if(q->tail < q->head) return 1;
  return 0;
}
//================================== TREEING =====================================
TreeNode* createNode(int data){
  TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void freeTree(TreeNode** current){
  if((*current) == NULL){
    return;
  }
  
  freeTree(&(*current)->left);
  freeTree(&(*current)->right);
  free(*current);
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

void insertLevelOrederedTree(TreeNode** root, int inVal){
  TreeNode* newNode = createNode(inVal);
  
  if((*root) == NULL){
    (*root) = newNode;
    return;
  }
  
  NodeQueue q;
  initNodeQueue(&q);
  pushNodeQueue(&q, (*root));
  
  while(!isQueueEmpty(&q)){
    TreeNode* current = getNodeQueue(&q);
    
    if(current->left == NULL){
      current->left = newNode;
      return;
    }
    else{
      pushNodeQueue(&q, current->left);
    }
    
    if(current->right == NULL){
      current->right = newNode;
      return;
    }
    else{
      pushNodeQueue(&q, current->right);
    }
    
  }
}

void insertSearchTree(TreeNode** root, int inVal){
  TreeNode* newNode = createNode(inVal);
  
  if((*root) == NULL){
    (*root) = newNode;
    return;
  }
  
  if((*root)->data < inVal){
    insertSearchTree(&(*root)->right, inVal);
  }
  if((*root)->data > inVal){
    insertSearchTree(&(*root)->left, inVal);
  }
}

//==================================== SEARCHING ======================================
//asume that all the tree given is not empty

TreeNode* searchLevelOrderedTree(TreeNode* root, int val){
  NodeQueue q;
  initNodeQueue(&q);
  pushNodeQueue(&q, root);
  
  while(!isQueueEmpty(&q)){
    TreeNode* current = getNodeQueue(&q);
    
    if(current->data == val){
      return current;
    }
    
    if(current->left != NULL){
      pushNodeQueue(&q, (current->left));
    }
    
    if(current->right != NULL){
      pushNodeQueue(&q, (current->right));
    }
  }
  printf("Not found!\n");
  return NULL;
}


TreeNode* searchSearchTree(TreeNode* root, int val){
  if(root == NULL){
    return NULL;
  }
  
  if(root->data == val){
    return root;
  }   
  
  if(root->data < val){
    return searchSearchTree(root->right, val);
  }
  else{
    return searchSearchTree(root->left, val);
  }

}

//====================================== DELETE =================================
TreeNode* findMin(TreeNode* root){
  while(root->left != NULL)
    root = root->left;
  return root;
}

TreeNode* deleteNodeSearchTree(TreeNode* root, int val){
  if(root == NULL) return NULL;

  if(val < root->data){
    root->left = deleteNodeSearchTree(root->left, val);
  }
  else if(val > root->data){
    root->right = deleteNodeSearchTree(root->right, val);
  }
  else{
    // Case 1 & 2: 0 hoặc 1 con
    if(root->left == NULL){
      TreeNode* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      TreeNode* temp = root->left;
      free(root);
      return temp;
    }

    // Case 3: 2 con
    TreeNode* successor = findMin(root->right);
    root->data = successor->data;
    root->right = deleteNodeSearchTree(root->right, successor->data);
  }
  return root;
}


int main()
{
    BinaryTree tree1, tree2, tree3, tree4;
    initTree(&tree1);
    initTree(&tree2);
    initTree(&tree3);
    initTree(&tree4);
    
    //insert tree1
    for(int i = 0; i < 16; i++){
      insertLevelOrederedTree(&tree1.root, i+1);
    }
    
    //insert tree2
    int po1[MAX] = {50, 17, 76, 9, 23, 54, 14, 19, 72, 12, 67};
    for(int i = 0; i < 11; i++){
      insertSearchTree(&tree2.root, po1[i]);
    }
    
    //insert tree 2
    int po2[MAX] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 35};
    for(int i = 0; i < 11; i++){
      insertSearchTree(&tree3.root, po2[i]);
    }
    
    //insert tree 4 
    int po[MAX] = {
      3, 
      1, 10, 
      13, 5, 11, 16,
      NULL, NULL, 6, NULL, NULL, NULL, 15, 2,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 9, 4, NULL, NULL
    };
    for(int  i = 0; i < 31; i++){
      insertLevelOrederedTree(&tree4.root, po[i]);
    }
    
    
    freeTree(&tree1.root);
    freeTree(&tree2.root);
    freeTree(&tree3.root);
    freeTree(&tree4.root);
    return 0;
}

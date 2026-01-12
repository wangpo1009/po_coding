/*
tree 4: level ordered tree with some NULL val
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
int main()
{
    BinaryTree tree;
    initTree(&tree);
    int po[MAX] = {
      3, 
      1, 10, 
      13, 5, 11, 16,
      NULL, NULL, 6, NULL, NULL, NULL, 15, 2,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 9, 4, NULL, NULL
    };
    for(int  i = 0; i < 31; i++){
      insertLevelOrederedTree(&tree.root, po[i]);
    }
    printTree(tree.root, 0, ' ');
    freeTree(&tree.root);
    return 0;
}

/*
               ↗ 0

            ↗ 2

                ↘ 0

        ↗ 16

                ↗ 4

            ↘ 15

                ↘ 9

    ↗ 10

                ↗ 0

            ↗ 0

                ↘ 0

        ↘ 11

                ↗ 0

            ↘ 0

                ↘ 0

3

                ↗ 0

            ↗ 0

                ↘ 0

        ↗ 5

                ↗ 0

            ↘ 6

                ↘ 0

    ↘ 1

                ↗ 0

            ↗ 0

                ↘ 0

        ↘ 13

                ↗ 0

            ↘ 0

                ↘ 0
*/

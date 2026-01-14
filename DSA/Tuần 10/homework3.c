#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SPACE 5

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
//==================================== TREEING =============================================

void printTree(TreeNode* root, int space, char branch){
  if(root == NULL){
    return;
  }

  space += SPACE;

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

void initTree(BinaryTree* tree){
  tree->root = NULL;
}


TreeNode* createNode(int val){
  TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
  newNode->data = val;
  newNode->right = newNode->left = NULL;
  return newNode;
}

void freeTree(TreeNode* root){
  if(root == NULL) return;
  
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

void insertTree(TreeNode** root, int val){
  TreeNode* newNode = createNode(val);
  
  if((*root) == NULL){
    (*root) = newNode;
  }
  
  if((*root)->data > val){
    insertTree(&(*root)->left, val);
  }
  if((*root)->data < val){
    insertTree(&(*root)->right, val);
  }
}

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

//================================= PROBLING ==========================================
//3.2
int MostElementsLevel(TreeNode *root){
    if(root == NULL) return -1;

    NodeQueue q;
    initNodeQueue(&q);
    pushNodeQueue(&q, root);

    int maxLevel = 0;
    int maxCount = 0;
    int currentLevel = 0;

    while(!isQueueEmpty(&q)){
      int levelSize = q.tail - q.head + 1; 

      if(levelSize > maxCount){
        maxCount = levelSize;
        maxLevel = currentLevel;
      }
      //scan through all element in 1 level and push in queue
      for(int i = 0; i < levelSize; i++){
        TreeNode* current = getNodeQueue(&q);

        if(current->left)
          pushNodeQueue(&q, current->left);
        if(current->right)
          pushNodeQueue(&q, current->right);
      }

      currentLevel++;
    }

    return maxLevel;
}

//3.3
void sumSingleParentNode(TreeNode *root, int *sum){
  if(root == NULL) return NULL;
  
  if(root->left == NULL && root->right != NULL){
    (*sum) += root->data;
  }
  
  if(root->left != NULL && root->right == NULL){
    (*sum) += root->data;
  }
  
  sumSingleParentNode(root->left, sum);
  sumSingleParentNode(root->right, sum);
}

//3.4 sumSingleParentNode minus all the node with single left child is 
//the same with sum all the node with single right child 
void sumRightParentNode(TreeNode *root, int *sum){
  if(root == NULL) return ;
  
  if(root->left == NULL && root->right != NULL){
    (*sum) += root->data;
  }
  
  sumRightParentNode(root->left, sum);
  sumRightParentNode(root->right, sum);
}

//3.5 find the node that have the closest val to the 3.4 
int abs_cal(int a, int b){
  if(a - b > 0){
    return a - b;
  }
  else return b-a;
}

//3.5
int searchNearest(TreeNode *root, int val){
  if(root == NULL) return -1;
  
  int nearestVal = -1;
  int minDiff = 10000000;
  
  NodeQueue q;
  initNodeQueue(&q);
  pushNodeQueue(&q, root);
    
  while(!isQueueEmpty(&q)){
    TreeNode* current = getNodeQueue(&q);
    
    if(abs_cal(current->data, val) < minDiff){
      nearestVal = current->data;
      minDiff = abs_cal(current->data, val);
    }
    
    if(current->left != NULL){
      pushNodeQueue(&q, current->left);
    }
    if(current->right != NULL){
      pushNodeQueue(&q, current->right);
    }
    
  }
  return nearestVal;
}




int main(){
  BinaryTree tree;
  initTree(&tree);
  
  printf("TREE :");
  int po2[MAX] = {15, 11, 26, 8, 12, 20, 30, 6, 9, 14, 1, 35};
  for(int i = 0; i < 12; i++){
    insertLevelOrederedTree(&tree.root, po2[i]);
  }
  printTree(tree.root, 0, ' ');
  
  printf("The level has the most element: %d\n", MostElementsLevel(tree.root));
  int sum = 0;
  sumSingleParentNode(tree.root, &sum);
  printf("Total of all node that have 1 child: %d\n", sum);
  
  int sumRight = 0;
  sumRightParentNode(tree.root, &sumRight);
  printf("Total of all node that have 1 child on the right: %d\n", sumRight);
  
  printf("The closest val to sumRight is: %d\n", searchNearest(tree.root, sumRight));
  freeTree(tree.root);
  return 0;
}

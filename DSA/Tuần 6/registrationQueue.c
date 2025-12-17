/*
  Bài 4: (Registration Queue) 
-Yêu cầu thực hiện:
Viết chương trình bằng ngôn ngữ lập trình C để triển khai hệ thống quản lý hàng đợi đăng ký sự kiện.
Sử dụng cấu trúc dữ liệu Queue để lưu trữ hàng đợi người dùng.
-Triển khai các hàm sau:
 +put(): Thêm một người dùng vào hàng đợi.
 +get(): Lấy thông tin người dùng đầu hàng đợi và xóa khỏi hàng đợi.
 +cancelRegistration(): Hủy đăng ký của một người dùng khỏi hàng đợi.
 +displayQueue(): Hiển thị danh sách toàn bộ người dùng đã đăng ký tham gia sự kiện.
*/
#include <stdio.h>

#define MAX 10

typedef struct{
  int data[MAX];
  int head, tail;
}queue;

void init(queue *q){
  q -> head = -1;
  q -> tail = -1;
}

int isEmpty(queue *q){
  if(q -> head == -1){
    return 1;
  }
  return 0;
}

int isFull(queue *q){
  if(q -> head == MAX - 1 && q -> tail == 0 ||
     q -> tail == (q -> head - 1)){
       return 1;
  }
  return 0;
}

void put(queue *q, int val){
  
  if( isEmpty(q) ){
    q -> head = q -> tail = 0;
  }
  
  if( !isFull(q) ){
    
    q -> tail++;
    
    if(q -> tail >= MAX - 1){
      q -> tail = (q -> tail + 1) % MAX;
      q -> data[q -> tail] = val;
    }
    
  }
  
  return;
}

int get(queue *q){
  
  if( !isEmpty(q) ){
    
    int val = q -> data[q -> head++];
    
    if(q->head == q->tail){
      q->head = q->tail = -1;
    }
    else{
      q->head = (q->head + 1) % MAX;
    }
    
    return val;
  }
  
  return;
}


void displayQueue( queue q ){
  if( isEmpty(&q) ){
    return;
  }
  
  int j = 0;
  int i = q.head;
  
  while(1){
    printf("STT %d: %d", j++, q.data[i]);
    if(i == q.tail){
      break;
    }
    i = (i + 1) % MAX;
  }
}


void cancelRegis( queue *q, int ind){
  if( isEmpty(q) ){
    return;
  }
  
  int i = ind;
  while( i != q-> tail ){
    q -> data[i] = q -> data[(i+1) % MAX];
    i = (i + 1) % MAX;
  }
  
  if(q->head == q->tail){
    q->head = q->tail = -1;
  }
  else{
    q->tail = (q->tail - 1 + MAX) % MAX;
  }
  
}

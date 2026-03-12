//Version 1:
typedef struct {
    int* data;
    int top;
    int capacity;
} MinStack;


MinStack* minStackCreate() {
    MinStack* newStack = (MinStack*)malloc(sizeof(MinStack));
    newStack->capacity = 100; 
    newStack->data = (int*)malloc(sizeof(int) * newStack->capacity);
    newStack->top = -1;
    return newStack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, sizeof(int) * obj->capacity);
    }
    obj->data[++(obj->top)] = val;
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    int min = obj->data[0];
    for(int i = 0; i < obj->top + 1; i++){
        if(obj->data[i] < min){
            min = obj->data[i];
        }
    }
    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}


//Version 2:
typedef struct {
    int* data;
    int* minData; // Mảng lưu lịch sử các giá trị nhỏ nhất
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 100; 
    obj->data = (int*)malloc(sizeof(int) * obj->capacity);
    obj->minData = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    // 1. Kiểm tra và mở rộng bộ nhớ cho cả 2 mảng
    if (obj->top == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (int*)realloc(obj->data, sizeof(int) * obj->capacity);
        obj->minData = (int*)realloc(obj->minData, sizeof(int) * obj->capacity);
    }

    // 2. Push vào mảng data chính
    obj->data[++(obj->top)] = val;

    // 3. Cập nhật lịch sử min
    if (obj->top == 0) {
        obj->minData[obj->top] = val;
    } else {
        int currentMin = obj->minData[obj->top - 1];
        obj->minData[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minData[obj->top]; // Lấy giá trị nhỏ nhất tại vị trí top hiện tại
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj->minData);
    free(obj);
}


//Version 1:
typedef struct{
    int* data;
    int top;
}Stack;

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    (*returnSize) = temperaturesSize;
    int* result = (int*)malloc(sizeof(int) * temperaturesSize);

    if(temperaturesSize == 1){
        result[0] = 0;
        return result;
    }

    Stack index;
    index.top = -1;
    index.data = (int*)malloc(sizeof(int) * temperaturesSize);
    for(int i = 0; i < temperaturesSize; i++){
        result[i] = 0;
    }

    for(int i = 0; i < temperaturesSize; i++){
        while(index.top >= 0 && temperatures[i] > temperatures[index.data[index.top]]){
            result[index.data[index.top]] = i - index.data[index.top];
            index.top--;
        }
        index.data[++index.top] = i;
    }
    return result;
}

//Version 2:

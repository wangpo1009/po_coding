/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int compare(const void *a, const void *b){
    return (*(char*)a - *(char*)b);
 }

//Struct quản lý chuỗi sau khi đã sort
 typedef struct{
    char *sortedStr;
    int originInd;
 }Word;

 int WordComp(const void *a, const void *b){
    return strcmp(((Word*)a)->sortedStr, ((Word*)b)->sortedStr);
 }

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    if (strsSize == 1) {
        *returnSize = 1;//Có 1 nhóm được trả về
        
        *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
        (*returnColumnSizes)[0] = 1; // Nhóm đầu tiên có 1 phần tử

        char*** result = (char***)malloc(sizeof(char**) * (*returnSize));
        result[0] = (char**)malloc(sizeof(char*) * (*returnColumnSizes)[0]);
        result[0][0] = strdup(strs[0]);

        return result;
    }
    (*returnSize) = 0;

    //Đưa chuỗi vào mảng kiểm soát rồi sort lại chuỗi
    Word* WordArr = (Word*)malloc(strsSize * sizeof(Word));
    for(int i = 0; i < strsSize; i++){
        WordArr[i].sortedStr = strdup(strs[i]);
        qsort(WordArr[i].sortedStr, strlen(strs[i]), sizeof(char), compare);
        WordArr[i].originInd = i;
    }

    //sort lại mảng kiểm soát
    qsort(WordArr, strsSize, sizeof(Word), WordComp);

    
    char*** result = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));

    for(int i = 0; i < strsSize;){
        //Duyệt qua nhóm đầu tiên(dừng lại khi khác với chuỗi đầu)
        int start = i;
        while (i < strsSize && strcmp(WordArr[i].sortedStr, WordArr[start].sortedStr) == 0) {
            i++;
        }

        //Gán các chuỗi đầu vào một nhóm trong mảng result
        (*returnColumnSizes)[(*returnSize)] = i - start;
        result[(*returnSize)] = (char**)malloc((*returnColumnSizes)[(*returnSize)] * sizeof(char*));

        for (int j = 0; j < (*returnColumnSizes)[(*returnSize)]; j++) {
            result[(*returnSize)][j] = strdup(strs[WordArr[start + j].originInd]);
        }
        (*returnSize)++;
    }

    for (int i = 0; i < strsSize; i++) {
        free(WordArr[i].sortedStr);
    }
    free(WordArr);
    return result;
}

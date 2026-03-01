//Version 1:
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    char* prefix = strs[0];
    
    for (int index = 1; index < strsSize; index++) {
        int i = 0;

        while (prefix[i] != '\0' &&
               strs[index][i] != '\0' &&
               prefix[i] == strs[index][i]) {
            i++;
        }

        prefix[i] = '\0';

        if (prefix[0] == '\0')
            return prefix;
    }

    return prefix;
}

//Version 2:
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (strs[0][j] &&
               strs[i][j] &&
               strs[0][j] == strs[i][j]) {
            j++;
        }
        strs[0][j] = '\0';
    }

    return strs[0];
}

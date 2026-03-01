//Version 1: full reverse
bool isPalindrome(int x) {
    if(x<0) return false;

    int phanDu, orix = x;
    long reversex = 0;

    else{
        while(x!=0){
            phanDu =x % 10;
            reversex = phanDu + reversex*10;
            x /= 10;
        }
        if(orix == reversex)
            return true;
    }

    return false;

}

//Version 2: half reverse
bool isPalindrome(int x) {
    if (x < 0) return false;

    if (x % 10 == 0 && x != 0) return false;

    int reversedHalf = 0;

    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    return (x == reversedHalf) || (x == reversedHalf / 10);
}

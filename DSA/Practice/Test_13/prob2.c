/*Hãy viết hàm đệ quy tính giá trị của phần tử thứ n của dãy số được định nghĩa như sau:
Phần tử thứ 1 bằng 1.
Phần tử thứ n bằng n cộng với phần tử đứng trước đó.
Phân tích hàm đệ quy theo quy trình 4 bước.
*/

int find_N(int n){
  if(n == 1){
    return 1;
  }
  
  return n + find_N(n-1);
  
}

/*
1)base case: when n = 1;
2)result of base case: 1;
3)before base case: happen when n = 2;
    call func find(2) = 2 + find(1) 
                  = 2 + 1 = 3;
4)before before base case: happen when n = 3;
    call func find(3) = 3 + find(2)
                      = 3 + (2 + find(1))
                      = 3 + (2 + 1)
                      = 6;
*/

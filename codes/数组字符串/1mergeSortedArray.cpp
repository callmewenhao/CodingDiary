/*  
leetcode: https://leetcode-cn.com/problems/sorted-merge-lcci/
Merge Sorted Array
1.Merge Two Sorted Array into a new Arraay
2.Merge Two Sorted Array A and B into A, assume A has enough space.
注意：A的末尾有足够的缓存空间
思路：从后向前合并！
*/
#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArray(int A[], int m, int B[], int n){
    int index = n + m;
    while(m > 0 && n > 0){
        if(A[m - 1] > B[n - 1])
            A[--index] = A[--m];
        else
            A[--index] = B[--n];
    }
    while(n > 0){
        A[--index] = B[--n];
    }
    // 下面这段代码可以省略
    // while(m > 0){
    //     A[--index] = A[--m];
    // }
}

int main(int argc, char *argv[]){
    int A[] = {1,2,3,0,0,0};
    int B[] = {2,5,6};
    mergeSortedArray(A, 3, B, 3);
    for(int i : A){
        cout<<i;
    }
    return 0;
}



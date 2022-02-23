/* 
Remove Element
Given an array and a value, 
remove all occurrences of that value inplace and return the new length.
The order of elements can be changed,
and the elements after the newlength don't matter.

Example
Given an array [0,4,4,0,0,2,4,4], value=4
return 4 and front four elements of the array is [0,0,0,2]

分析：
- 双指针
- vector遍历删除
*/
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &A, int elem){
    for(vector<int>::iterator it = A.begin(); it != A.end(); it++){
        if(*it == elem){
            A.erase(it);
            it--;  // 与后面的it++抵消
        }
    }
    return A.size();
}

int removeElement(int A[], int n, int elem){
    for(int i = 0; i < n; i++){
        if(A[i] == elem){
            A[i] = A[n - 1];  // 这样会改变内容
            --i;
            --n;
        }
    }
    return n;
}

int main(int argc, char *argv[]){
    vector<int> v = {0,4,4,0,0,2,4,4};
    int i[] = {0,4,4,0,0,2,4,4};
    int l = removeElement(i, 8, 4);
    printf("%d\n", l);
    return 0;
}




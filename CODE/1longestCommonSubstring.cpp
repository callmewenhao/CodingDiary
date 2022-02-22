/* 
Longest Common Substring
Given two strings, find the longest common substring.
Return the length of it.
Example:
Given A="ABCD",B="CBCE",return 2.
Note:
The characters in substring should occur continuously in original string.
This is different with subsequence.
使用双指针方法，时间复杂度O(n^2)
*/
#include <iostream>
#include <string>
using namespace std;

int longestCommonSubstring(string &A, string &B) {
    if(A.empty() || B.empty())
        return 0;
    
    int lcs = 0, lcs_temp = 0;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j< B.size(); j++){
            lcs_temp = 0;
            while((i + lcs_temp < A.size()) &&\
                  (j + lcs_temp < B.size()) &&\
                  (A[i + lcs_temp] == B[j + lcs_temp]))
            {
                lcs_temp++;
            }
            if(lcs_temp > lcs)
                lcs = lcs_temp;
        }
    }
    return lcs;
}




int main(int argc, char *argv[]){
    string A="ABCD", B="CBCE";
    int lcs = longestCommonSubstring(A, B);
    printf("%d\n", lcs);
    return 0;
}



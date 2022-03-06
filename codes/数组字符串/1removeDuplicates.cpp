/*  
remove Duplicates from Sorted Array 1
Given a sorted array, remove the duplicates in place such that eachelement appear only once and return the new length.
Do not allocate extra space for another array, you must do this in placewith constant memory.
For example,
Given input array nums =[1,1,2],
Your function should return length = 2, 
with the first two elements ofnums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the new length.
*/
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums){
    if(nums.empty())
        return 0;

    int size = 0;
    for(vector<int>::size_type i = 0; i < nums.size(); i++){
        if(nums[i] != nums[size]){
            nums[++size] = nums[i];
        }
    }
    return size + 1;
}


int main(int argc, char *argv[]){
    vector<int> raw = {1,1,2};
    int l = removeDuplicates(raw);
    printf("%d\n", l);
    return 0;
}



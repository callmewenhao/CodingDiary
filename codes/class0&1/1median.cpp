/*  
Median
Given a unsorted array with integers, find the median of it.
A median is the middle number of the array after it is sorted.
lf there are even numbers in the array,
return the N/2-th number after
sorted.
Example
Given[4,5,1,2,3], return 3
Given[7,9,4,5], return 5

解题思路：
- quick sort:快排解法
*/
#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int> &nums, int l, int u, int size){
    // if(l >= u) return nums[u];
    int m = l;
    for(int i = l + 1; i <= u; i++){
        if(nums[i] < nums[l]){
            ++m;
            int temp = nums[i];
            nums[i] = nums[m];
            nums[m] = temp;
        }
    }
    int temp = nums[l];
    nums[l] = nums[m];
    nums[m] = temp;
    
    if(m - l +1 == size)
        return nums[m];
    else if(m - l +1 > size)
        return helper(nums, l, m - 1, size);
    else
        return helper(nums, m + 1, u, size - (m - l + 1));
}

int median(vector<int> &nums){
    if(nums.empty()) return 0;
    int len = nums.size();
    return helper(nums, 0, len - 1, (len + 1) / 2);
}

int main(int argc, char *argv[]){
    vector<int> n = {4,5,1,2,3};
    int m = median(n);
    cout<<m;
    return 0;
}



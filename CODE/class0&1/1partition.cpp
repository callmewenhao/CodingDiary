/*  
Given an array nums of integers and an int k, 
partition the array(i.e move the elements in "nums") such that:
All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.
Example if nums=[3,2,2,1] and k=2, a valid answer is 1.
If all elements in nums are smaller than k, then return nums.length
Challenge:
Can you partition the array in-place and in O(n)?

解题思路：
- 同向双指针法：两个指针（right代表长度，i指示遍历）从前向后遍历！
遇到小于k的值时更新right！
- 反向双指针法：
*/
#include <iostream>
#include <vector>
using namespace std;

/* 同向双指针 */
// int partitionArray(vector<int> &nums, int k){
//     int right = 0;
//     const int size = nums.size();
//     for(vector<int>::size_type i = 0; i < nums.size(); i++){
//         if(nums[i] < k){
//             int temp = nums[i];
//             nums[i] = nums[right];
//             nums[right] = temp;
//             right++; 
//         }
//     }
//     return right;
// }

/* 反向双指针 */
int partitionArray(vector<int> &nums, int k){
    int left = 0, right = nums.size() - 1; 
    while(left <= right){
        while(left <= right && nums[left] < k) left++;
        while(left <= right && nums[right] >= k) right--;
        if(left <= right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
    return left;
}

int main(int argc, char *argv[]){
    vector<int> n = {1,3,2,2,1,0};
    int l = partitionArray(n, 2);
    cout<<l<<endl;
    return 0;
}

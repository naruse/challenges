/*
  https://leetcode.com/problems/two-sum/description/

  Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

#include <iostream>
#include <vector>

using namespace::std;

vector<int> twoSum(vector<int> const & nums, int target);

int main(int arch, char* argv[]) {
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
}


vector<int> twoSum(vector<int> const & nums, int target) {
    vector<int> result;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j]+nums[i] == target) {
                result.push_back(j);
                result.push_back(i);
                return result;
            }
        }
    }
    cout << "cannot find values" << endl;
    return result;
}

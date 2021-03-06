/*

   LEETCODE# 350

   Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result 
   must appear as many times as it shows in both arrays and you may return the result in any order.

 

   Example 1:

     Input: nums1 = [1,2,2,1], nums2 = [2,2]
     Output: [2,2]

   Example 2:

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [4,9]
    Explanation: [9,4] is also accepted.

*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hashmap;    // need a counter to keep track of #of occurence
    vector<int> result{};
    
    // Construct hashmap of numbers in one array
    //
    for (auto i : nums1) {
        auto itr = hashmap.find(i);
        if (itr != hashmap.end())
            itr->second++;
        else
            hashmap.insert(make_pair(i, 1));
    }
    // Check for intersection in second array
    //
    for (auto i : nums2) {
        auto itr = hashmap.find(i);
        if (itr != hashmap.end()) {
            if (itr->second > 0) {
                result.push_back(i);
                itr->second--;
            }
        }
    }
    return result;        
}

int main() {
    vector<int> nums1 = {4,9,5, 4};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> result;

    cout << "[";
    for (auto i : nums1) {
        cout << i << ", ";
    }
    cout << "]" << endl;
    cout << "[";
    for (auto i : nums2) {
        cout << i << ", ";
    }
    cout << "]" << endl;

    result = intersect(nums1, nums2);

    cout << "==> [";
    for (auto i : result) {
        cout << i << ", ";
    }
    cout << "]" << endl;

}



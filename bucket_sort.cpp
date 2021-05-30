// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.

 

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
// Example 2:

// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 109

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int maxx=INT_MIN,minn=INT_MAX;
        
        for(int &n:nums){
            maxx = max(maxx,n);
            minn = min(minn,n);
        }
        
        int bucket_gap = max((maxx-minn)/(n-1),1);
        int bucket_size = (maxx-minn)/bucket_gap+1;
        
        vector<int> emax(bucket_size,INT_MIN);
        vector<int> emin(bucket_size,INT_MAX);
        
        for(int i=0;i<n;i++){
            int ind = (nums[i]-minn)/bucket_gap;
            emax[ind] = max(emax[ind],nums[i]);
            emin[ind] = min(emin[ind],nums[i]);
        }
        
        int ans = 0;
        int prev = emax[0];
        
        for(int i=1;i<bucket_size;i++){
            if(emin[i]==INT_MAX)    continue;
            ans = max(emin[i]-prev,ans);
            prev = emax[i];
        }
        
        return ans;
    }
};
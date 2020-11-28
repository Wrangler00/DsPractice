#include<bits/stdc++.h>
using namespace std;

/***
Algorhitm : Brute forces
Time Complexity: O(N * K). 
The outer loop runs n-k+1 times and the inner loop runs k times for every iteration of outer loop. So time complexity is O((n-k+1)*k) which can also be written as O(N * K).
Space Complexity: O(1). 
No extra space is required.
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int sz = nums.size();
        
        for(int i=0;i<=sz-k;i++){
            int maxx = nums[i];
            for(int j=i;j<k+i;j++){
                maxx = max(maxx,nums[j]);
            }
            ans.push_back(maxx);
        }
        return ans;
    }
};

/*
Algorithm: 
O(n) solution
->Create a Deque, Qi of capacity k, that stores only useful elements of current window of k elements. An element is useful if it is in current window and is greater than all other elements on right side of it in current window

Create a deque to store k elements.
Run a loop and insert first k elements in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element , if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Now, run a loop from k to end of the array.
Print the front element of the deque.
Remove the element from the front of the queue if they are out of the current window.
Insert the next element in the deque. Before inserting the element, check if the element at the back of the queue is smaller than the current element , if it is so remove the element from the back of the deque, until all elements left in the deque are greater than the current element. Then insert the current element, at the back of the deque.
Print the maximum element of the last window.
*/
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> ans;
        deque<int> dq(k);
        
        for(int i=0;i<sz;i++){
            while(!dq.empty() && dq.front()<=i-k)   dq.pop_front();
            while(!dq.empty() && nums[i]>=nums[dq.back()])  dq.pop_back();
            
            dq.push_back(i);
            if(i>=k-1)    ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};

/*
Using multiset
O(nlogk) solution
*/
class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k == 0) return result;
        multiset<int> w;
        for (int i = 0, n = (int)nums.size(); i < n; i++) {
            if (i >= k)
                w.erase(w.find(nums[i-k]));
            w.insert(nums[i]);
            if (i >= k-1)
                result.push_back(*w.rbegin());
        }
        return result;
    }
};

/*
O(n) solution WITHOUT using deque
fastest solution
But space is also O(n) 
*/
class Solution4 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> res(sz - k + 1);      
        vector<int> left = nums;
        vector<int> right = nums;
        
        for(int i = 1; i < sz; i++) {
            if(i%k != 0)    
                left[i] = max(left[i], left[i-1]);
            
            int j = sz - 1 - i;
            
            if(j%k != 0)    
                right[j] = max(right[j], right[j+1]);
        }
        
        for(int i = 0; i < nums.size() - k + 1; i++)
            res[i] = max(left[i+k-1], right[i]);

        return res;
    }
};



/*
O(n) solution WITHOUT using deque (another solution)
fastest solution
But space is also O(n) 
*/
class Solution5 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        if(n == 0)
            return res;
        if(k == 1)
            return nums;

        int left[n]; 
        int right[n]; 

        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        //max from left in the windows of k
        for(int i = 0;i < n;i++)
        {
            if(i % k == 0)
            left[i] = nums[i];
            else
            left[i] = std::max(nums[i],left[i - 1]);
        } 

        // max from right in the windows of k
        for(int i = n - 2;i >= 0;i--)
        {
            if(i % k == 0)
            right[i] = nums[i];
            else
            right[i] = std::max(nums[i],right[i + 1]);
        } 

        //overall maximum
        for(int i = 0; i <= n - k;i++)
        {
            res.push_back(std::max(right[i],left[i + k - 1]));
        }
        return res;
    }
};


/*
O(nlogn) solution
using priority queue (max heap)
*/
class Solution6 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> w;
        
        for (int i = 0, n = (int)nums.size(); i < n; i++) {
            while (!w.empty() && w.top().second <= i-k) w.pop();
            w.push(make_pair(nums[i],i));
            if (i >= k-1)   result.push_back(w.top().first);
        }
        return result;
    }
};
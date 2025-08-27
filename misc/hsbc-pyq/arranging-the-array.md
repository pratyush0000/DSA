# Arranging the array

You are given an array of size **N**. Rearrange the given array in-place such that all the negative numbers occur before all non-negative numbers.\
(Maintain the order of all -ve and non-negative numbers as given in the original array).\
\
**Example 1:**

<pre><code><strong>Input:
</strong>N = 4
Arr[] = {-3, 3, -2, 2}
<strong>Output:
</strong>-3 -2 3 2
<strong>Explanation:
</strong>In the given array, negative numbers
are -3, -2 and non-negative numbers are 3, 2. 
</code></pre>

**Example 2:**

<pre><code><strong>Input:
</strong>N = 4
Arr[] = {-3, 1, 0, -2}
<strong>Output:
</strong>-3 -2 1 0
<strong>Explanation:
</strong>In the given array, negative numbers
are -3, -2 and non-negative numbers are 1, 0.
</code></pre>

**Your Task:**  \
You don't need to read input or print anything. Your task is to complete the function **Rearrange()** which takes the array **Arr\[]** and its size **N** as inputs and returns the array after rearranging with spaces between the elements of the array.\
\
**Expected Time Complexity:** O(Nlog(N))\
**Expected Auxiliary Space:** O(log(N))

**Constraints:**\
1 ≤ N ≤ 10<sup>5</sup>\
-10<sup>9</sup> ≤ Elements of array ≤ 10<sup>9</sup>

## Solution.

```cpp
//2 passes

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        vector<int> ans;
        for(int i=0; i<n/2; i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};
```



***


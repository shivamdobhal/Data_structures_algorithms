1]  leetcode-53
    kadanes algorithms-----is a part of dynamic programming and used to solve the problems like max. sum subarray problem.
                      -----useful when array elements are negative alongwith positive
                      -----time complexity=o(n)
                      -----in this algo we discarded the value when it comes negative
---------------------------------------------------------------code---------------------------------------------------------------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum =0;  
        int max_sum = nums[0];       
    
        for(int i = 0; i < nums.size(); ++i)
        {
            cur_sum =cur_sum + nums[i]; //running sum
            
            if(cur_sum > max_sum)
            {  
                max_sum = cur_sum;
            }
            
             if(cur_sum <= 0)  //if current sum is lessthan or equals to 0 then curt_sum will become 0
            {   
                cur_sum = 0;
            }
        }
        
        return max_sum;
    }
};
     



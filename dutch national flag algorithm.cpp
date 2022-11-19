used for sorting 0,1,2
time comlexity=o(n)
space complexity=o(1)
---------------------------------------------------------------------------------------------------------------------------
  algo based on 3 steps
  ====================
  low=0,mid=0,high=arr.size()-1;                         // put low and mid to starting index  // and high to  ending index
  
while(mid<=high)
  
step-1]if mid==0
           swap mid and low
           mid++,low++
  
  step-2]if mid==1
             mid++
    
    step-3]if mid==2
           swap mid and high
           high--
--------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low,mid,high;
            low=0;
            mid=0;
            high=nums.size()-1;
            
            while(mid<=high)
            {
                    if(nums[mid]==0)
                        {
                                swap(nums[mid],nums[low]);
                                low++,mid++;
                        }
                     
                     else  if(nums[mid]==1)
                               {
                                mid++;
                        }
                    else if(nums[mid]==2)
                        {
                                swap(nums[mid],nums[high]);
                                high--;
                        }
            }
            
    }
};  

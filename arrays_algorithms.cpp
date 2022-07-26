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
     





2]  problem -88       --------two pointer approach
                 ---------T.C=o(n)  
                 ---------S.C=0(1)
                 ---------used to merge two sorted arrays in which start filling the largest  elements from the last
                 example====  
                           nums1=1  2  3  0  0  0                  nums2=2  5  6
                                       p1       i                              p1
                                       
                                       
                               
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>  nums2, int n) {
        
        int p1=m-1;
        int p2=n-1;
        int i=nums1.size()-1;
        
        while(p2>=0)
        {
            if( p1>=0 && nums1[p1]>nums2[p2] )             //if p1 is greater
            {
                nums1[i]=nums1[p1];
                i--;
                p1--;
            }
            else                                  
            {
                nums1[i]=nums2[p2];                
                i--;
                p2--;
            }
        }
      
    }
};





3] problem -350 ]to find intersection of two array
              ---can do by sorting method or by mapping method (but  i do with sorting method)
             
                  
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> x;                                                  // new vector to store the result
        int p1=0;                                                        //pointer 1 for nums1
        int p2=0;                                                        //pointer2 for nums2
            
        sort(nums1.begin(),nums1.end());                                         // sort both vectors nums1 and nums2  
        sort(nums2.begin(),nums2.end());
            
        while(p2<=nums2.size()-1 && p1<=nums1.size()-1)
        {     
             if(nums1[p1]==nums2[p2])                                    //main pushing takes place in this part
             {
                        x.push_back(nums2[p2]);
                        p1++;
                        p2++;
             }
            
            else if(nums1[p1]<nums2[p2]) 
            {
                         p1++; 
            }
                   
             else if(nums1[p1]>nums2[p2])
             {
                     p2++;
             }                     
         
    }
        return x;
    } 
};

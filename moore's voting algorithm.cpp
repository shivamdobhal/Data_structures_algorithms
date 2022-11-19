leetcode-229        majority element 2

    moore's voting algorithm---for finding the majority element in the array
    
    
    
    
    class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         vector<int> res;  
         int num1=INT_MIN,count1=0,num2=INT_MIN,count2=0;
            int n=nums.size();
         for(int i=0;i<nums.size();i++)
         {
                 if(nums[i]==num1)count1++;
                else  if(nums[i]==num2)count2++;
                 else if(count1==0)
                 {
                         num1=nums[i];
                         count1++;
                 }
                else if(count2==0)
                 {
                         num2=nums[i];
                         count2++;
                 }
                 
                 else
                 {
                         count1--;
                         count2--;
                 }
                 
                 
                 
         }
            count1=0;
            count2=0;
            for(int it=0;it<nums.size();it++)
            {
                    if(nums[it]==num1)count1++;
                    if(nums[it]==num2)count2++;
            }       
            if(count1>n/3)
                    res.push_back(num1);
            if(count2>n/3)
                    res.push_back(num2);
            
            return res;
            
    }         
    
};

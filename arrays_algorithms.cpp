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







problem -121]   stock buy and sell problem
               --brute force  by using n square complexity
          ------------------------------------------------brute force -------------------------------------------------
     
    class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
            int x=0;
            int max=0;
            
            for(int i=0;i<prices.size()-1;i++)
            {
                    for(int j=i+1;j<prices.size();j++)
                     {
                             if(prices[i]<prices[j])
                             {
                                     x=prices[j]-prices[i];
                             }
                     
                             if(x>max)
                            {
                            max=x;
                             }
                    }
            }
            return max;
            if(max==0)
            {
                    return 0;
            }
    }
};


----------------------------------------------------------------optimized soluton-----------------------------------------------------------------------------
            TIME COMPLEXITY=o(N)   SPACE COMPLEXITY=O(1)
              ===>in brute force we try to solve this based on buying  in optimum to try to find the solution based on selling date
                   optimal solution include======
                                                          run a for loop{i}
                                                          {
                                                             finding the minimum element from starting till i
                                                                 now,find profit by subtracting min from profit[i]
                                                             find max. element till profit from max;
                                                          }
                                                           return max;
                 

        public:
            int maxProfit(vector<int>& prices) {
            int MIN=prices[0];
            int MAX=0;
            int profit;
            for(int i=0;i<prices.size();i++)
            {
                  
                             MIN=min(MIN,prices[i]);
                                     profit=prices[i]-MIN;
                             MAX=max(MAX,profit);                     
            }
            return MAX;        
    }
};






problem - 566]  matrix the reshape
                ----concept of 2D vector
     
     
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {          // r and c are the given rows and cloumn of the new resultant matrix 
    vector<vector<int>> result(r,vector<int>(c));                                        //new resultant matrix after reshaping
            int row = mat.size();                                                        //for size of row of older matrix
            int column=mat[0].size();                                                   //for size of column of older matrix
            if(row*column!=r*c)                                                         //check that size of older matrix is  equal to newly formed matrix or not
                    return mat;                                                         //then according to ques. return the original  matrix
            int x=0,y=0;                                                                //rows and column of old matrix
            for(int i=0;i<row;i++)
            {
                    for(int j=0;j<column;j++)
                    {
                            result[x][y]=mat[i][j];
                               y++;
                            if(y==c)                                          //if column fills then move to the next column 
                            {
                                    x++;                                       //increment row
                                    y=0;                                       //set column to 0     
                            }               
                    }
                    
            }
            return result;                                     //return the  new reshaped MATRIX
                               
    } 
};

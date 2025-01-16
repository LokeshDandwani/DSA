class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size(); 
       int n2 = nums2.size(); 
       if(n1%2 == 0  && n2%2==0){
        return 0; 
       }
       int xorr=0; 
       if(n1%2==0){
          for(int num: nums1){
            xorr = xorr^num; 
          }
          return xorr; 

       }
       if(n2%2==0){
           for(int num: nums2){
            xorr = xorr^num; 
          }
          return xorr;  
       }
       for(int num: nums1){
            xorr = xorr^num; 
          }
          for(int num: nums2){
            xorr = xorr^num; 
          }
          return xorr; 
        
    }
};
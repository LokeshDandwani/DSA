class Solution {
public:
   bool canShip(vector<int>& weights,int mid,  int days){
       
       int day=0; 
       int temp=0; 
       for(auto weight: weights){
           if(temp+weight > mid){
                day++; 
                temp=weight; 
           }else{
            temp+= weight; 
           }
       }
       day++; 

       return day<=days; 
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(); 
        int left =  *max_element(weights.begin(), weights.end()); 
        int right = accumulate(begin(weights), end(weights), 0); 
        int ans = 0; 
        while(left<=right){
            int mid = left+ (right-left)/2; 
              if(canShip(weights, mid, days)){
                 ans= mid; 
                 right= mid-1; 
              }else{
                left= mid+1; 
              }
        }
        return ans; 
    }
};
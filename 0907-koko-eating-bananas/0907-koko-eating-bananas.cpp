class Solution {
public:

    bool canEatBanana(vector<int>& piles, int mid, int h){

        long long count =0; 
        for(int temp: piles){
            count = count+ ceil((double)temp/(double)mid); 
        }
        return count<=h; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); 
        int left = 1;
        int right = *max_element(begin(piles), end(piles)); 
         int ans= 0; 
          while(left<=right){
              int mid= left+ (right-left)/2; 
              if(canEatBanana(piles, mid,h)){
                     ans= mid; 
                     right = mid-1;                 
              }else{
                left = mid+1; 
              }
          }
          return ans;  

    }
};
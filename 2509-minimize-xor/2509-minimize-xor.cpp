class Solution {
public:
    int minimizeXor(int num1, int num2) {
      int setBits = 0; 
      for(int i=0; i<32; i++){
         if((num2 >> i)&1){
            setBits++; 
         }
      }
        int ans=0; 
      
        for(int i=31; i>=0; i--){
         if((num1 >> i)&1 == 1 && setBits >=1){
            setBits--;
            ans |= (1<<i);  
         }
        }
        
            for(int i=0; i<32; i++){
         if(((num1 >> i)&1)==0 && setBits >= 1){
            setBits--;
            ans |= (1<<i);  
         }
        }
        
      
      

      return ans;       




    }
};
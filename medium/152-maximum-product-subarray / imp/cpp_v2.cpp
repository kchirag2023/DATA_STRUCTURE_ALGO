// Pushed: 2026-10-31 17:11:50 UTC
// Difficulty: Medium
// Runtime: 0 ms
// Memory: 17.7 MB

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // A) IF ALL ELEMENT IS positive THEN-> ALL ARRAY PRODUCT IS ANSWER
        // B)IF EVEN NO. NEGATIVE->ALL ARRAY IS ANSWER
        // C) IF ODD NO. OF NEGATIVE-> WE HAVE TO TAKE EVEN NUMBER OF NEGATIVE-> WE HAVE TO CHECK WETHER TAKE NEGATIVES FROM LEFT SIDE OR RIGHT
        // D) DURING ZER0-> IGNORE ZERO ,UPDATE MAX PREFIX PRODUCT=1, NO CHANGE TO MAX PRODUCT.
        int max_p=INT_MIN;
        int flag=0;
        int pref_p=1;
        int suff_p=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
         if(nums[i]==0)pref_p=1,flag=1;
         else{
            pref_p=pref_p*nums[i];
            if(max_p<pref_p) max_p=pref_p;

         }
         

        }
        for(int i=n-1;i>=0;i--){
         if(nums[i]==0)suff_p=1;
         else{
            suff_p=suff_p*nums[i];
            if(max_p<suff_p) max_p=suff_p;

         }
         

        }
        if(flag) return max(0,max_p);
        return max_p;


        
    }
};
// Pushed: 2026-09-26 18:05:29 UTC
// Difficulty: Medium
// Runtime: 854 ms
// Memory: 9.5 MB

class Solution {
public:
    int pal(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        int start=0;
        int max_len=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(pal(s,i,j )&& max_len<(j-i+1)){
                    start=i;
                    max_len=j-i+1;

                }
            }
        }
        return s.substr(start,max_len);
        
    }
};
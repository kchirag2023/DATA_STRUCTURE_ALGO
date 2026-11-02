// Pushed: 2026-11-02 03:41:42 UTC
// Difficulty: Medium
// Runtime: 57 ms
// Memory: 18.5 MB

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // PART 1->IS PART OF BINARY SEARCH BUT PART 2 WE HAVE TO THINK SMARTLY IS ALL ABOUT SMART PLAY

        // YOU HAVE TO START WITH THE TOPMOST RIGHT BOX, YOU CAN SEE L PART IS COMPLETELY SORTED.
        int row=0;
        int col=mat[0].size()-1;
        int n=mat.size();
        while(row<n && col>=0){
            if(mat[row][col]==target) return true;
            else if(mat[row][col]<target){
                row++;
            }
            else{
                col--;
            }

        }
        return false;
    }
};
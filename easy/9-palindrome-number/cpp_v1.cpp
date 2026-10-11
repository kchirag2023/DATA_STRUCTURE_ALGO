// Pushed: 2026-10-11 18:02:54 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 8.6 MB

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;  // negatives are not palindrome

        long long rev = 0, num = x;
        while(num) {
            rev = rev * 10 + num % 10;  // build reversed number
            num /= 10;
        }
        return rev == x;  // check if equal
    }
};
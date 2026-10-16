class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        
        // Loop backwards as long as we have digits to process
        while (i >= 0) {
            if (digits[i] < 9) {
                digits[i]++; // Incremented successfully, no carry left!
                return digits;
            }
            
            // Current digit is 9: it becomes 0, and the loop continues left (carry = 1)
            digits[i] = 0;
            i--;
        }
        
        // If the loop finished completely, it means we had an all-nines array (e.g., [9, 9])
        // It turned into, so we insert a 1 at the front to make it [1, 0, 0]
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
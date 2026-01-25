class Solution {
public:
    bool isPalindrome(string s) {
        //new variable to store the clean string
        //clean string means remove spaces, symbols etc...
        string newStr = "";
        for (char c : s) {
            if (isalnum(c)) {
                newStr += tolower(c);
            }
        }
        //left pointer
        int left = 0;
        //right pointer
        int right = newStr.size() - 1;
        while (left < right) {
            //check if left(first)..... character and right(last)..... did not match  
            if (newStr[left] != newStr[right]) {
                return false;
            }
            //if match move the left to one step forward
            left++;
            // move the right pointer to one step backward
            right--;
        }
        return true;
    }
};
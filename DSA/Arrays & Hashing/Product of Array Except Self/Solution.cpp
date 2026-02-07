class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //get size of array
        int n = nums.size();
        //initialize answer array with all 1s
        vector<int> answer(n, 1);
        //left to right iteration to calculate prefix product
        for(int i = 1; i < n; i++){
            //current answer = previous answer * previous number
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        //variable to store postfix product
        int postfix = 1;
        //right to left iteration to calculate postfix and final answer
        for(int i = n - 1; i >= 0; i--){
            //multiply current answer with postfix to get final result
            answer[i] *= postfix;
            //update postfix by multiplying with current number
            postfix *= nums[i];
        }
        //return the final answer
        return answer;
    }
};
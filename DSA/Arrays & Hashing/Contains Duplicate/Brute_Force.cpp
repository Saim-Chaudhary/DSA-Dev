class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
		//1st iteration pointing to first(current) num 
            for (int j = i + 1; j < nums.size(); j++) {
			//1st iteratin pointing to second(next) num and move to next...   
                if (nums[i] == nums[j]) {
                	//comapre the current and next.... 
                    return true;
                }
            }
        }
        return false;
    }
};
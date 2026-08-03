class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices; // val -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (indices.find(complement) != indices.end()) {
                return {indices[complement], i};
            }
            indices.insert({nums[i], i});
        }
    }
};

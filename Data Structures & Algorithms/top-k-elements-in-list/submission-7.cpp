class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int, int> count;
        for (int num: nums) {
            count[num]++;
        }
        vector<vector<int>> buckets (nums.size()+1);
        for (const auto& [num, c] : count) {
            buckets[c].push_back(num);
        }

        vector<int> ans;
        for (int i = nums.size(); i >= 0; i--) {
            for (int num: buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }
        return ans;

    }
};

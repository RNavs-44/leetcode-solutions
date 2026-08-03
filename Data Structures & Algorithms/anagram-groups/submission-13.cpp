class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> strs_map;
        for (const auto& s : strs) {
            std::string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            strs_map[sorted_s].push_back(s);
        }
        vector<vector<string>> ans;
        for (const auto& i : strs_map) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

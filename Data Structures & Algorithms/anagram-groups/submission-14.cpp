class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> strs_map;
        for (const auto& s : strs) {
            std::string key;
            vector<int> count(26, 0);
            for (char c: s) {
                count[c-'a'] ++;
            }
            for (int n: count) {
                key += ','; // delimeter distinguishes 1 11 and 11 1
                key += std::to_string(n);
            }
            strs_map[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (const auto& i : strs_map) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

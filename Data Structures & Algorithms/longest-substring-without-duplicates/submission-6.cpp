class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; int ans = 0;
        unordered_map<char, int> char_map; // char -> last seen index
        for (int r = 0; r < s.size(); r++) {
            if (char_map.find(s[r]) != char_map.end()) {
                l = max(char_map[s[r]] + 1, l);
            }
            char_map[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

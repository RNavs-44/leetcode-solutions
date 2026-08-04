class Solution {
public:
    int characterReplacement(string s, int k) {
        // find longest substring that contains k + 1 distinct characters
        int l = 0;
        int ans = 0;
        int max_cnt = 0;
        unordered_map<char, int> cnt;
        for (int r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            max_cnt = max(max_cnt, cnt[s[r]]);

            while ((r - l + 1) - max_cnt > k) {
                cnt[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

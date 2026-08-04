class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1_cnt (26, 0);
        vector<int> s2_cnt (26, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1_cnt[s1[i] - 'a']++;
            s2_cnt[s2[i] - 'a']++;
        }
        if (s1_cnt == s2_cnt) return true;
        for (int r = s1.size(); r < s2.size(); r++) {
            s2_cnt[s2[r] - 'a']++;
            s2_cnt[s2[r - s1.size()] - 'a']--;
            if (s1_cnt == s2_cnt) return true;
        }
        return false;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0;
        int need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) have++;
            
            while (have == need) {
                // update our result
                if ((r - l + 1) < resLen) {
                    res = {l, r};
                    resLen = (r - l + 1);
                }
                // pop from the left of the window
                char leftChar = s[l];
                window[leftChar]--;
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) have--;
                l++;
            }
            
        }
        // return empty string if no such substring exists
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

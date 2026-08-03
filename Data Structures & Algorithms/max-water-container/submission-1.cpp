class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0; int r = heights.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = (r - l) * min(heights[l], heights[r]);
            ans = max(area, ans);
            if (heights[l] <= heights[r]) {
                l++;
            }
            else if (heights[l] > heights[r]) {
               r--; 
            }
        }
        return ans;
    }
};

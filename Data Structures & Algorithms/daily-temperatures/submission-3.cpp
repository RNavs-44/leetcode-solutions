class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> indices; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!indices.empty() && t > indices.top().first) {
                auto pair = indices.top();
                indices.pop();
                res[pair.second] = i - pair.second;
            }
            indices.push({t, i});
        }
        return res;
    }
};

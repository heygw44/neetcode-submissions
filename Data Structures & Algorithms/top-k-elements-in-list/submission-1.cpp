class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<vector<int>> bucket(n+1);
        for (auto& [num, freq] : count) {
            bucket[freq].push_back(num);
        }
        vector<int> ans;
        for (int freq = n; freq >= 1; freq--) {
            for (int num : bucket[freq]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }

        return ans;
    }
};

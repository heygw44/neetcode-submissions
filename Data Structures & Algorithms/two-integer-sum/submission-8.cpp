class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (mp.contains(diff)) {
                return {mp[diff], i};
            } else {
                mp.insert({nums[i], i});
            }
        }
        return {};
    }
};

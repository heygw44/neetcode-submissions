class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map; // value, index
        
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];

            if (map.contains(diff)) {
                return {map[diff], i};
            } else {
                map.insert({nums[i], i});
            }
        }
        return {};
    }
};

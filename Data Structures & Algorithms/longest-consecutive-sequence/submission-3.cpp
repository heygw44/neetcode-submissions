class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (!numSet.contains(num-1)) {
                int len = 1;
                while (numSet.contains(num+len)) {
                    len++;
                }
                longest = max(longest, len);
            }
        }

        return longest;
    }
};

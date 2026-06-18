class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;

        int ans = 0;
        int maxCount = 0;

        for (int num : nums) {
            count[num]++;
            if (count[num] > maxCount) {
                ans = num;
                maxCount = count[num];
            }
        }

        return ans;
    }
};
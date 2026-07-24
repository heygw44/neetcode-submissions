class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        int leftMax = height[l], rightMax = height[r];

        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                ans += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                ans += rightMax - height[r];
            }
        }        
        return ans;
    }
};

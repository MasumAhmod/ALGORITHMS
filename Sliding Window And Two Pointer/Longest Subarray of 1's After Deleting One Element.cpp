class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, cnt = 0, mx = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                cnt++;
            }

            while (cnt > 1) {
                if (nums[l] == 0) {
                    cnt--;
                }
                l++;
            }
            mx = max(mx, r - l + 1);
            r++;
        }

        return mx - 1;
    }
};


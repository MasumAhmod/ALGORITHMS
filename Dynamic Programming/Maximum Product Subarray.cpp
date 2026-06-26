class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        int tmp = 1;
        int mx1 = INT_MIN;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                if(i == 0) {
                    mx1 = 0;
                    mx1 = max(mx1 , 0);
                } else if(nums[i - 1] == 0) {
                    mx1 = max(mx1 , 0);
                    tmp = 1;
                } else {
                    mx1 = max(mx1 , tmp);
                    tmp = 1;
                    mx1 = max(mx1 , 0);
                }
            } else {
                tmp *= nums[i];
                mx1 = max(mx1 , tmp);
                mx1 = max(mx1 , 0);
            }
        }
        mx1 = max(mx1 , 0);

        int mx = INT_MIN;

        tmp = 1;
        for(int i = n - 1; i >= 0; --i) {
            if(nums[i] == 0) {
                if(i == n - 1) {
                    mx = 0;
                    mx = max(mx , 0);
                } else if(nums[i + 1] == 0) {
                    mx = max(mx , 0);
                    tmp = 1;
                } else {
                    mx = max(mx , tmp);
                    mx = max(mx , 0);
                    tmp = 1;
                }
            } else {
                tmp *= nums[i];
                mx = max(mx , tmp);
                mx = max(mx , 0);
            }
        }
        mx = max(mx , 0);


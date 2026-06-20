class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return (max(nums[0] , nums[1]));

        vector <int> tmp1 , tmp2;
        for(int i = 0; i < n - 1; ++i) {
            tmp1.push_back(nums[i]);
        }

        for(int i = 1; i < n; ++i) {
            tmp2.push_back(nums[i]);
        }

        vector <int> dp1(n - 1) , dp2(n - 1);
        dp1[0] = tmp1[0];
        dp1[1] = max(tmp1[0] , tmp1[1]);
        for(int i = 2; i < n - 1; ++i) {
            dp1[i] = max((dp1[i - 2] + tmp1[i]) , dp1[i - 1]);
        }

        dp2[0] = tmp2[0];
        dp2[1] = max(tmp2[0] , tmp2[1]);
        for(int i = 2; i < n - 1; ++i) {
            dp2[i] = max((dp2[i - 2] + tmp2[i]) , dp2[i - 1]);
        }

        return (max(dp1[n - 2] , dp2[n - 2]));
    }
};


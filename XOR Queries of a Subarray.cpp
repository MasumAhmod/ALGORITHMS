class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> pref;
        pref.push_back(arr[0]);

        for (int i = 1; i < n; ++i) {
            pref.push_back(pref[i - 1] ^ arr[i]);
        }

        vector<int> ans;

        for (const auto& u : queries) {
            int l = u[0], r = u[1];

            if(l == 0) ans.push_back(pref[r]);
            else {
                ans.push_back(pref[r] ^ pref[l- 1]);
            }
        }

        return ans;
    }
};

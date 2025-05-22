class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        vector<int> cnt_w(26, 0);
        vector<int> cnt_p(26, 0);
        vector<int> result;

        if (k > n) return result;

        for (char c : p) {
            cnt_p[c - 'a']++;
        }

        for (int i = 0; i < k; ++i) {
            cnt_w[s[i] - 'a']++;
        }

        for (int i = 0; i < n; ++i) {
            bool matched = true;

            for (int j = 0; j < 26; ++j) {
                if (cnt_w[j] != cnt_p[j]) {
                    matched = false;
                    break;
                }
            }

            if (matched) {
                result.push_back(i);
            }

            cnt_w[s[i] - 'a']--;

            if(i + k >= n){
                break;
            }
            cnt_w[s[i + k] - 'a']++;
        }

        return result;
    }
};


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        long long tot = accumulate(cardPoints.begin(), cardPoints.end(), 0LL);

        int m = n - k;

        long long currWindowSum = accumulate(cardPoints.begin(), cardPoints.begin() + m, 0LL);

        long long maxScore = tot - currWindowSum;

        for (int i = m; i < n; ++i) {
            currWindowSum -= cardPoints[i - m];
            currWindowSum += cardPoints[i];

            maxScore = max(maxScore, tot - currWindowSum);
        }

        return maxScore;
    }
};


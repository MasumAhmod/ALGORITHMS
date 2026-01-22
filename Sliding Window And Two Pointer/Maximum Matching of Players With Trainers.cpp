class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin() , players.end());
        sort(trainers.begin() , trainers.end());

        int n = players.size() , m = trainers.size();

        int l = 0 , r = 0;
        int cnt = 0;
        while(1){
            if(players[l] <= trainers[r]){
                cnt++;

                l++;
                r++;
            } else {
                r++;
            }

            if(l >= n || r >= m){
                break;
            }
        }
        return cnt;
    }
};

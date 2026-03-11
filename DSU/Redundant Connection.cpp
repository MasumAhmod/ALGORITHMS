class Solution {
public:

    vector <int> par;

    int find(int x){
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        par.resize(n+1);

        for(int i = 1; i <= n; ++i) {
            par[i] = i;
        }

        for(auto &g : edges){

            int u = g[0];
            int v = g[1];

            int pu = find(u);
            int pv = find(v);

            if(pu == pv)
                return {u, v}; 

            par[pv] = pu;    
        }

        return {};
    }
};

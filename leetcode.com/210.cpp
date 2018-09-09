class Solution {
    vector<bool> visited;
    vector<bool> visiting;
public:
    bool dfs(int v, const vector<vector<int>>& edges, stack<int>& r) {
        if (visited[v]) {
            return true;
        }

        if (visiting[v]) {
            return false;
        }

        bool good = true;
        visiting[v] = true;

        for (int i = 0; (i < edges[v].size()) && good; i++) {
            good = dfs(edges[v][i], edges, r);
        }

        r.push(v);

        visiting[v] = false;
        visited[v] = true;

        return good;
    }

    vector<int> findOrder(int n, vector<pair<int, int>>& req) {
        vector<int> ans;
        vector<vector<int>> edges(n);
        visited.resize(n);
        visiting.resize(n);
        stack<int> r;
        for (int i = 0; i < req.size(); i++) {
            edges[req[i].second].push_back(req[i].first);
        }
        bool good = true;
        for (int i = 0; (i < n) && good; i++) {
            good = dfs(i, edges, r);
        }

        if (good) {
            for (auto it = r.begin(); it != r.end(); it++) {
                ans.push_back(*it);
            }
        }

        return ans;
    }
};

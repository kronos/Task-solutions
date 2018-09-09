class Solution {
    vector<bool> visited;
    vector<bool> visiting;
    vector<set<int> > g;

    bool dfs(int u) {
        if (visited[u]) {
            return true;
        }

        if (visiting[u]) {
            return false;
        }

        visiting[u] = true;
        bool good = true;

        for (auto it = g[u].begin(); (it != g[u].end()) && good; it++) {
            good = dfs(*it);
        }

        visiting[u] = false;
        visited[u] = true;
        return good;
    }

public:
    bool canFinish(int n, vector<pair<int, int>>& req) {
        visited.resize(n);
        visiting.resize(n);
        g.resize(n);

        for (int i = 0; i < n; i++) {
            visiting[i] = visited[i] = false;
        }

        for (int i = 0; i < req.size(); i++) {
            g[req[i].first].insert(req[i].second);
        }

        bool good = true;

        for (int i = 0; (i < n) && good; i++) {
            good = dfs(i);
        }
        return good;
    }
};

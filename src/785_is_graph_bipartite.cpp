class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> v(graph.size(), -1);
        queue<int> q;
        for (int i = 0; i < graph.size(); i ++) {
            if (v[i] != -1)     continue;
            v[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int j = 0; j < graph[node].size(); j ++) {
                    if (v[graph[node][j]] == v[node])    return false;
                    if (v[graph[node][j]] == -1) {
                        v[graph[node][j]] = (v[node] == 0)? 1:0;
                        q.push(graph[node][j]);
                    }
                }
            }
        }
        return true;
    }
};
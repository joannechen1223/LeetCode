/*
* Author: joannechen1223
* Date: 2021.01.04
* Note: https://hackmd.io/@jmmVOLEvQViVzHCqRCzKww/SJ-8g5x0w
*/


class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1)    return 0;
        vector<Node*> nodes;
        // initialize
        for (int i = 0; i < arr.size(); i ++) {
            Node* n = new Node(i, arr[i]);
            nodes.push_back(n);
        }
        
        // neighbor
        for (int i = 0; i < arr.size(); i ++) {
            if (i != 0)     nodes[i]->adj.push_back(nodes[i-1]);
            if (i != arr.size() - 1)    nodes[i]->adj.push_back(nodes[i+1]);
        }
        
        // same value
        for (int i = 0; i < arr.size(); i ++) {
            for (int j = i+1; j < arr.size(); j ++) {
                if (arr[i] == arr[j]) {
                    nodes[i]->adj.push_back(nodes[j]);
                    nodes[j]->adj.push_back(nodes[i]);
                }
            }
        }
        
        // BFS
        queue<Node*> q;
        q.push(nodes[0]);
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();
            if (current->idx == arr.size()-1)   return current->distance;
            for (int i = 0; i < current->adj.size(); i ++) {
                if (!current->adj[i]->visited) {
                    current->adj[i]->distance = current->distance + 1;
                    current->adj[i]->visited = true;
                    q.push(current->adj[i]);
                }
            }
        }
        
        return 0;
    }
};
class Solution {
    vector<int> findNodesWithinK(const vector<vector<int>>& adjList, const int k) {
        vector<int> result;
        
        for (int i = 0, length = adjList.size(); i < length; i++) {
            queue<pair<int, int>> currNodeToParentQ;
            currNodeToParentQ.emplace(make_pair(i, -1));

            int valsWithinK = 0, remainingK = k;

            while (!currNodeToParentQ.empty() && remainingK >= 0) {
                int qSize = currNodeToParentQ.size();
                for (int j = 0; j < qSize; j++) {
                    int node = currNodeToParentQ.front().first;
                    int parent = currNodeToParentQ.front().second;
                    currNodeToParentQ.pop();
                    valsWithinK++;

                    for (const int& adjElement : adjList[node]) {
                        if (adjElement == parent) continue;
                        currNodeToParentQ.emplace(make_pair(adjElement, node));
                    }
                }
                remainingK--;
            }
            result.push_back(valsWithinK);
        }
        return result;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> edges1AdjList(edges1.size() + 1);

        for (const auto& edge : edges1) {
            edges1AdjList[edge.front()].emplace_back(edge.back());
            edges1AdjList[edge.back()].emplace_back(edge.front());
        }

        vector<vector<int>> edges2AdjList(edges2.size() + 1);

        for (const auto& edge : edges2) {
            edges2AdjList[edge.front()].emplace_back(edge.back());
            edges2AdjList[edge.back()].emplace_back(edge.front());
        }

        vector<int> result = findNodesWithinK(edges1AdjList, k);
        vector<int> tree2Vec = findNodesWithinK(edges2AdjList, k - 1);

        int valToAdd = *max_element(tree2Vec.begin(), tree2Vec.end());

        for (auto& num : result) num += valToAdd;

        return result;
    }
};
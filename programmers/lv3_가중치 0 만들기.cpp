#include <string>
#include <vector>
using namespace std;
long long answer = 0;

long long dfs(int cur_node, int parent_node, vector<long long>& weights, vector<vector<int>>& map) {

    for (int i = 0; i < map[cur_node].size(); i++) {
        if (map[cur_node][i] == parent_node) continue;
        weights[cur_node] += dfs(map[cur_node][i], cur_node, weights, map);
    }

    answer += abs(weights[cur_node]);
    return weights[cur_node];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> weights(a.begin(), a.end());
    vector<vector<int>> map(a.size());
    for (int i = 0; i < a.size() - 1; i++) {
        int start = edges[i][0];
        int end = edges[i][1];
        map[start].push_back(end);
        map[end].push_back(start);
    }

    int check = 0;
    for (int weight : a) {
        check += weight;
    }
    if (check != 0) {
        return -1;
    }

    //이제부터는 0을 만들 수 있는 트리만 고려하면 된다. 
    dfs(0, -1, weights, map);


    return answer;
}
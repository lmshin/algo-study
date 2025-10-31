#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//K 이하의 비용으로 배달할 수 있는 마을 Check
//1번마을로부터 각 마을에 도달할 때의 비용을 구한다.
//다익스트라?

vector<int> distance_map;

//distance 를 기준으로 min heap 정렬을 해야한다.
struct Node {
    int city;
    int distance;
    bool operator < (const Node& other) const {
        return distance > other.distance;
    }
};

int dijkstra(vector<vector<pair<int, int>>>& graph, int k, vector<vector<int>>& road) {
    priority_queue<Node> pq;
    pq.push({ 1,0 });
    distance_map[1] = 0;
    while (!pq.empty()) {
        int curCity = pq.top().city;
        //int curDistance = pq.top().distance;
        pq.pop();

        for (int i = 0; i < graph[curCity].size(); i++) {
            int nextCity = graph[curCity][i].first;
            int nextDistance = graph[curCity][i].second;

            if (nextCity == 1) continue;
            //해당 노드까지의 거리가 k이하인 경우는 고려대상임
            int D = distance_map[curCity] + nextDistance;

            if (D < distance_map[nextCity] && D <= k) {
                //cout << "nextCity : " << nextCity << " Distance :" << nextDistance << "\n";
                //근데 이미 더 적은값으로 도달한 적이 있다면 그냥 넘어간다.
                if (distance_map[curCity] + nextDistance >= distance_map[nextCity] && distance_map[nextCity] != 0) continue;

                distance_map[nextCity] = distance_map[curCity] + nextDistance;
                pq.push({ nextCity,nextDistance });
            }
        }
    }

    int count = 0;
    for (int i = 0; i < distance_map.size(); i++) {
        if (distance_map[i] != 0 && distance_map[i] <= k) count++;
        cout << distance_map[i] << "\n";
    }

    return ++count;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    distance_map.resize(N + 1, 1e9);
    vector<vector<pair<int, int>>> graph;
    graph.resize(N + 1);

    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int weight = road[i][2];
        graph[a].push_back({ b,weight });
        graph[b].push_back({ a,weight });
    }

    //1번 node를 pq에 집어넣는다.
    answer = dijkstra(graph, K, road);

    return answer;
}
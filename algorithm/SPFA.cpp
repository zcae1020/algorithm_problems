// * INF = 최대 유량 값, DinicMaxFlow(S, E)
// 레벨은 ”소스까지의 최단거리의 간선의 개수”를 의미한다.
// BFS로 ’레벨 그래프’를 만든다. 레벨 그래프에서 포함하는 간선은
// 1. 용량이 남아있는 간선 2. 레벨의 차이가 1인 정점을 연결하는 간선
// 레벨 그래프를 생성 하고, 에드몬드 카프처럼 DFS를 돌려 유량을 흘려보내 준다.
// 시간복잡도: O(EV 2)


vector<int> SPFA(int n, int start, auto &adj)
{
    vector<int> dist(n, INF);
    queue<int> Q;
    bool inQ[MAX] = {};
    int visit[MAX] = {};
    dist[start] = 0;
    Q.push(start);
    inQ[start] = true;
    ++visit[start];
    while (!Q.empty())
    {
        int here = Q.front();
        Q.pop();
        inQ[here] = false;
        for (auto &P : adj[here])
        {
            int there = P.first, newDist = dist[here] + P.second;
            if (newDist < dist[there])
            {
                dist[there] = newDist;
                if (!inQ[there])
                {
                    Q.push(there);
                    inQ[there] = true;
                    if (++visit[there] >= n)
                        return vector<int>();
                }
            }
        }
    }
    return dist;
}
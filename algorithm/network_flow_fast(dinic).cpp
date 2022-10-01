// * INF = 최대 유량 값, DinicMaxFlow(S, E)
// 레벨은 ”소스까지의 최단거리의 간선의 개수”를 의미한다.
// BFS로 ’레벨 그래프’를 만든다. 레벨 그래프에서 포함하는 간선은
// 1. 용량이 남아있는 간선 2. 레벨의 차이가 1인 정점을 연결하는 간선
// 레벨 그래프를 생성 하고, 에드몬드 카프처럼 DFS를 돌려 유량을 흘려보내 준다.
// 시간복잡도: O(EV 2)

const int MAX, INF;
int level[MAX], work[MAX];
struct Edge
{
    int next, cap, flow = 0;
    Edge *rev;
    Edge(){};
    Edge(int _next, int _cap) : next(_next), cap(_cap){};
};
vector<Edge *> adj[MAX];
inline void makeEdge(int u, int v, int cap)
{
    Edge *uv = new Edge(v, cap), *vu = new Edge(u, 0);
    uv->rev = vu, vu->rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}
//싱크까지 도달 가능한 레벨 그래프를 생성 할 수 있는가?
bool BFSdinic(int S, int E)
{
    memset(level, -1, sizeof(level));
    level[S] = 0;
    queue<int> Q;
    Q.push(S);
    while (!Q.empty())
    {
        int here = Q.front();
        Q.pop();
        for (auto &i : adj[here])
        {
            int there = i->next;
            //레벨이 정해지지 않고, 남은 용량이 있는 간선인가?
            if (level[there] == -1 && i->cap > 0)
            {
                level[there] = level[here] + 1;
                Q.push(there);
            }
        }
    }
    return (level[E] != -1);
}
// here에서 E에 도달할 때 까지 flow 만큼 흘려보내본다.
//싱크까지 얼마나 유량을 흘릴 수 있었는지 리턴한다.
int DFSdinic(int here, int flow, int E)
{
    if (here == E)
        return flow;
    int size = adj[here].size();
    for (int &i = work[here]; i < size; ++i)
    {
        int there = adj[here][i]->next, c = adj[here][i]->cap;
        if (level[here] + 1 == level[there] && c > 0)
        {
            int nc = DFSdinic(there, min(flow, c), E);
            if (nc)
            {
                adj[here][i]->cap -= nc;
                adj[here][i]->rev->cap += nc;
                return nc;
            }
        }
    }
    return 0;
}
int DinicMaxFlow(int S, int E)
{
    memset(level, 0, sizeof(level));
    int total = 0;
    while (BFSdinic(S, E))
    {
        memset(work, 0, sizeof(work));
        while (true)
        {
            int flow = DFSdinic(S, INF, E);
            if (flow == 0)
                break;
            total += flow;
        }
    }
    return total;
}
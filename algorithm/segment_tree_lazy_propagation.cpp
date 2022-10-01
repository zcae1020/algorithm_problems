const int MAX;
struct lazySeg
{
    ll arr[MAX], seg[MAX * 4], lazy[MAX * 4];
    ll init(int node, int l, int r)
    {
        if (l == r)
            return seg[node] = arr[l];
        int mid = (l + r) / 2;
        return seg[node] = init(node * 2, l, mid) + init(node * 2 + 1, mid + 1, r);
    }
    //현 노드의 lazy 값을 해소
    void update_lazy(int node, int nodeL, int nodeR)
    {
        if (lazy[node] != 0)
        {
            seg[node] += (nodeR - nodeL + 1) * lazy[node];
            // leaf가 아니면 자식에 전파
            if (nodeL != nodeR)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    ll update(int l, int r, ll value, int node, int nodeL, int nodeR)
    {
        update_lazy(node, nodeL, nodeR);
        if (r < nodeL || nodeR < l)
            return seg[node];
        if (l <= nodeL && nodeR <= r)
        {
            seg[node] += (nodeR - nodeL + 1) * value;
            // leaf가 아니면 자식에 전파
            if (nodeL != nodeR)
            {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return seg[node];
        }
        int mid = (nodeL + nodeR) / 2;
        return seg[node] = update(l, r, value, node * 2, nodeL, mid) +
                           update(l, r, value, node * 2 + 1, mid + 1, nodeR);
    }
    ll query(int l, int r, int node, int nodeL, int nodeR)
    {
        update_lazy(node, nodeL, nodeR);
        if (r < nodeL || nodeR < l)
            return 0;
        if (l <= nodeL && nodeR <= r)
            return seg[node];
        int mid = (nodeL + nodeR) / 2;
        return query(l, r, node * 2, nodeL, mid) +
               query(l, r, node * 2 + 1, mid + 1, nodeR);
    }
};
const int MAX, INF;
int arr[MAX], seg[MAX * 4];
int init(int l, int r, int node)
{
    if (l == r)
        return seg[node] = arr[l];
    int mid = (l + r) / 2;
    return seg[node] = min(init(l, mid, node * 2),
                           init(mid + 1, r, node * 2 + 1));
}
int query(int l, int r, int node, int nodeL, int nodeR)
{
    if (r < nodeL || nodeR < l)
        return INF;
    if (l <= nodeL && nodeR <= r)
        return seg[node];
    int mid = (nodeL + nodeR) / 2;
    return min(query(l, r, node * 2, nodeL, mid), query(l, r, node * 2 + 1,
                                                        mid + 1, nodeR));
}
int update(int index, int value, int node, int nodeL, int nodeR)
{
    if (index < nodeL || nodeR < index)
        return seg[node];
    if (nodeL == nodeR)
        return seg[node] = min(seg[node], value);
    int mid = (nodeL + nodeR) / 2;
    return seg[node] = min(update(index, value, node * 2, nodeL, mid),
                           update(index, value, node * 2 + 1, mid + 1, nodeR));
}
#include <iostream>
#define pii pair<int, int>

using namespace std;

int R, C;
char map[30][30], ans;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void Input()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> map[i];
}

pii adjCorrect(pii p)
{
    pii ret = p;
    int nx, ny;
    if (map[p.first][p.second] == '-')
    {
        nx = p.first + dx[1], ny = p.second + dy[1];
        if (map[nx][ny] == '.')
            ret = {nx, ny};
        nx = p.first + dx[3], ny = p.second + dy[3];
        if (map[nx][ny] == '.')
            ret = {nx, ny};
    }
    else if (map[p.first][p.second] == 124)
    {
        nx = p.first + dx[0], ny = p.second + dy[0];
        if (map[nx][ny] == '.')
            ret = {nx, ny};
        nx = p.first + dx[2], ny = p.second + dy[2];
        if (map[nx][ny] == '.')
            ret = {nx, ny};
    }
    else if (map[p.first][p.second] == '+')
    {
        for (int i = 0; i < 4; i++)
        {
            nx = p.first + dx[i], ny = p.second + dy[i];
            if (map[nx][ny] == '.')
                ret = {nx, ny};
        }
    }
    else
    { // 1,2,3,4
        for (int i = 0; i < 2; i++)
        {
            int idx = (map[p.first][p.second] - '1' + i) % 4;
            nx = p.first + dx[idx], ny = p.second + dy[idx];
            if (map[nx][ny] == '.')
                ret = {nx, ny};
        }
    }
    return ret;
}

void getShape(pii p)
{
    bool exist[4] = {false};
    for (int i = 0; i < 4; i++)
    {
        int nx = p.first + dx[i], ny = p.second + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        if (map[nx][ny] != '.' && map[nx][ny] != 'M' && map[nx][ny] != 'Z')
            if (adjCorrect(make_pair(nx, ny)) == p)
                exist[i] = true;
    }

    if (exist[0] && exist[1] && exist[2] && exist[3])
        ans = '+';
    else if(exist[0]&&exist[2])
        ans=124;
    else if(exist[1]&&exist[3])
        ans='-';
    else if(exist[0]&&exist[1])
        ans='1';
    else if(exist[1]&&exist[2])
        ans='2';
    else if(exist[2]&&exist[3])
        ans='3';
    else if(exist[3]&&exist[0])
        ans='4';
}

void Solution()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] != '.' && map[i][j] != 'M' && map[i][j] != 'Z')
            {
                pii p = adjCorrect(make_pair(i, j));
                if (p != make_pair(i, j))
                {
                    getShape(p);
                    cout << p.first + 1 << ' ' << p.second + 1 << ' ' << ans;
                    return;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Input();
    Solution();
}
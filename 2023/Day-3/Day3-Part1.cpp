#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const int N = 1e6 + 9;
const int mod = 1e9 + 7;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<string> grid;

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool isSymbol(char c)
{
    return (c != '.') and !isDigit(c);
}

bool isValid(int x, int y)
{
    return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
}
bool vis[1000][1000];
ll sum = 0;

void solve(int tc)
{
    string s;
    while (cin >> s)
    {
        int n = s.size();
        grid.push_back(s);
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (isSymbol(grid[i][j]))
            {
                queue<pii> q;
                q.push({i, j});
                while (!q.empty())
                {
                    pii p = q.front();
                    q.pop();
                    int x = p.first;
                    int y = p.second;
                    for (int k = 0; k < 8; k++)
                    {
                        int xx = x + dx[k];
                        int yy = y + dy[k];
                        if (isValid(xx, yy) && grid[xx][yy] != '.' and isDigit(grid[xx][yy]) and !vis[xx][yy])
                        {
                            vis[xx][yy] = true;
                            q.push({xx, yy});
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        int num = 0;
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (vis[i][j])
            {
                num = 10 * num + (grid[i][j] - '0');
            }
            else
            {
                sum += num;
                num = 0;
            }
        }
        sum += num;
    }
    cout << sum << endl;
}

int32_t main()
{
    FAST;
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        solve(i);
    }
}

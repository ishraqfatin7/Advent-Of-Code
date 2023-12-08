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

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void solve(int tc)
{
    string s;
    ll sum = 0;
    while (cin >> s)
    {
        int first = 0, last = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isDigit(s[i]))
            {
                first = s[i] - '0';
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (isDigit(s[i]))
            {
                last = s[i] - '0';
                break;
            }
        }
        // cout << first * 10 + last << endl;
        sum += first * 10 + last;
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

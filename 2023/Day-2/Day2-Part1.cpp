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
    return (c >= '0' && c <= '9');
}

bool isOk(string s, int points)
{
    if (s == "red" and points <= 12)
    {
        return true;
    }
    if (s == "green" and points <= 13)
    {
        return true;
    }
    if (s == "blue" and points <= 14)
    {
        return true;
    }
    return false;
}

bool check(string s)
{
    int n = s.size();
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (isDigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        else
        {
            break;
        }
    }
    string color = "";
    for (int i = 0; i < n; i++)
    {
        if (isDigit(s[i]))
        {
            continue;
        }
        else
        {
            color += s[i];
        }
    }
    return isOk(color, num);
}

bool passSubset(string s)
{
    // cout << s << endl;
    int n = s.size();
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ',')
        {
            if (!check(temp))
            {
                return false;
            }
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    if (!check(temp))
    {
        return false;
    }
    return true;
}

void solve()
{
    string s;
    int tc = 1;
    ll ans = 0;
    while (getline(cin, s))
    {

        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int n = s.size();
        int j = 0;
        while (j < n and s[j] != ':')
            j++;
        int curr = 0;
        string subset = "";
        bool flag = true;
        j++;
        while (j < n)
        {
            if (s[j] == ';')
            {
                if (!passSubset(subset))
                {
                    flag = false;
                    break;
                }
                subset = "";
            }
            else
            {
                subset += s[j];
            }
            j++;
        }
        if (!passSubset(subset))
        {
            flag = false;
        }
        if (flag)
        {
            ans += tc;
        }
        tc++;
        s = "";
    }
    cout << ans << endl;
}

int32_t main()
{
    FAST;
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        solve();
    }
}
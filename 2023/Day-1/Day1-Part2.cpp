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
    vector<string> v = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    map<string, int> mp;
    for (int i = 0; i < 9; i++)
    {
        mp[v[i]] = i + 1;
    }
    while (cin >> s)
    {
        int n = s.size();
        // your task is to find the first digit in the string, written in either English or in digit;
        int firstDigit = -1, firstDigitIndex = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            if (isDigit(s[i]))
            {
                firstDigit = s[i] - '0';
                firstDigitIndex = i;
                break;
            }
        }
        // find the english word for the first digit
        string firstDigitWord = "";
        int firstDigitWordIndex = INT_MAX;
        for (auto x : v)
        {
            if (s.find(x) != string::npos)
            { // cout << x << endl;
                if (s.find(x) < firstDigitWordIndex)
                {
                    firstDigitWord = x;
                    firstDigitWordIndex = s.find(x);
                }
            }
        }
        // cout << firstDigitWord << " " << firstDigitWordIndex << endl;
        int firstNum = -1, lastNum = -1;
        // find what comes first, the digit or the word
        if (firstDigitWordIndex == INT_MAX)
        {
            firstNum = firstDigit;
        }
        else if (firstDigitIndex == -1)
        {
            firstNum = mp[firstDigitWord];
        }
        else
        {
            if (firstDigitWordIndex < firstDigitIndex)
            {
                firstNum = mp[firstDigitWord];
            }
            else
            {
                firstNum = firstDigit;
            }
        }
        // now do the same for the last digit
        int lastDigit = -1, lastDigitIndex = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (isDigit(s[i]))
            {
                lastDigit = s[i] - '0';
                lastDigitIndex = i;
                break;
            }
        }
        string lastDigitWord = "";
        int lastDigitWordIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (isDigit(s[i]))
            {
                continue;
            }
            string temp = "";
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (mp.find(temp) != mp.end())
                {
                    lastDigitWord = temp;
                    lastDigitWordIndex = i;
                }
            }
        }
        if (lastDigitWordIndex == -1)
        {
            lastNum = lastDigit;
        }
        else if (lastDigitIndex == -1)
        {
            lastNum = mp[lastDigitWord];
        }
        else
        {
            if (lastDigitWordIndex > lastDigitIndex)
            {
                lastNum = mp[lastDigitWord];
            }
            else
            {
                lastNum = lastDigit;
            }
        }
        // cout << firstNum << " " << lastNum << endl;
        //  now we have the first and last digit,concatenate them and add to sum
        sum += firstNum * 10 + lastNum;
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

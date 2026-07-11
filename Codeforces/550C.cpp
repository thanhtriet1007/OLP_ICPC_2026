#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

void solve()
{
    // Trie's solution here
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '0' || s[i] == '8') {
            cout << "YES\n";
            cout << s[i] << "\n";
            return;
        }
        for (int j = i + 1; j < (int)s.size(); j++) {
            for (int k = j + 1; k < (int)s.size(); k++) {
                if (stoi(string(1, s[i]) + string(1, s[j]) + string(1, s[k])) % 8 == 0) {
                    cout << "YES\n";
                    cout << stoi(string(1, s[i]) + string(1, s[j]) + string(1, s[k])) << "\n";
                    return;
                }
                if (stoi(string(1, s[j]) + string(1, s[k])) % 8 == 0) {
                    cout << "YES\n";
                    cout << stoi(string(1, s[j]) + string(1, s[k])) << "\n";
                    return;
                }
                if (stoi(string(1, s[i]) + string(1, s[k])) % 8 == 0) {
                    cout << "YES\n";
                    cout << stoi(string(1, s[i]) + string(1, s[k])) << "\n";
                    return;
                }
                if (stoi(string(1, s[i]) + string(1, s[j])) % 8 == 0) {
                    cout << "YES\n";
                    cout << stoi(string(1, s[i]) + string(1, s[j])) << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

string s;

bool checkAB(int pos) {
    return (s[pos] == 'A' && s[pos + 1] == 'B');
}

bool checkBA(int pos) { 
    return (s[pos] == 'B' && s[pos + 1] == 'A');
}

void solve() {
    //World Final when?
    bool ok1 = 1, ok2 = 1;
    cin >> s;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (checkAB(i)) {
            for (int j = i + 2; j < (int)s.size() - 1; ++j) {
                if (checkBA(j)) {
                    cout << "YES";
                    return;
                }
            }
            ok1 = 0;
        }
        if (checkBA(i)) {
            for (int j = i + 2; j < (int)s.size() - 1; ++j) {
                if (checkAB(j)) {
                    cout << "YES";
                    return;
                }
            }
            ok2 = 0;
        }
        if (!ok1 && !ok2) {
            cout << "NO";
            return;
        }
    }
    cout << "NO";
}

#define TASK "test"

signed main()
{
   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   if (fopen("input.txt", "r")) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   }
   int t = 1;
   //cin >> t;
   while (t--)
   solve();
   return 0;
}
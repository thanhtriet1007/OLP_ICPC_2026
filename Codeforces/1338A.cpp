#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF    = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n;
int a[N];

void solve() {
    //Trie's solution here
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int D = 0;
    vector<int>maxPre(n + 1, 0);
    maxPre[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        maxPre[i] = max(maxPre[i - 1], a[i]);
        D = max(D, maxPre[i - 1] - a[i]);
    }
    if (D == 0) {
        cout << 0 << endl;
        return;
    }
    else {
        cout << __lg(D) + 1 << endl;
        return;
    }
}

signed main()
{
   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   if (fopen("input.txt", "r")) {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   }
   int t = 1;
   cin >> t;
   while (t--)
   solve();
   return 0;
}
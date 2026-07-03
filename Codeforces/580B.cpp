/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, d;
pair<int, int>a[N];

void solve() {
    //World Final when?
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);
    int j = 0;
    int ans = 0;
    int currentSum = 0;
    for (int i = 1; i <= n; ++i) {
        while (j + 1 <= n && a[j + 1].first - a[i].first <= d) {
            ++j;
            currentSum += a[j].second;
        }
        ans = max(ans, currentSum);

        currentSum -= a[i].second;
    }

    cout << ans;
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
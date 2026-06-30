/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

int n, q;
int cnt[N];
int a[N];

void solve() {
    //World Final when?
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int _ = 1; _ <= q; ++_) {
        int l, r; cin >> l >> r;
        cnt[l] += 1;
        cnt[r + 1] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i - 1];
    }
    sort(a + 1, a + 1 + n);
    sort(cnt + 1, cnt + 1 + n);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += cnt[i] * a[i];
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
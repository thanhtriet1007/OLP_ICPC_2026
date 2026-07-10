#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, t;
int a[N], s[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int j = 0;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (j < n && s[j + 1] - s[i - 1] <= t) {
            j++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans << endl;
}
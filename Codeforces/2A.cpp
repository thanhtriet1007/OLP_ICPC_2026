#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF    = 1e18 + 7;
const long long MOD    = 1e9 + 7;

void solve() {
    //Trie's solution here
    int n; cin >> n;

    int ans = -INF;
    string winner;
    

    map<string, pair<int, int>> mp;
    map<int, pair<int, string>> mp2;
    map<string, bool>mark;
    for (int i = 1; i <= n; ++i) {
        string s; int k; 
        cin >> s >> k;
        mp[s].first += k;
        if (mp[s].first > mp[s].second || !mark[s]) {
            mp[s].second = mp[s].first;
            if (mp2.count(mp[s].second) == 0) {
                mp2[mp[s].second] = {i, s};
            }
        }
        //cout << s << ' ' << mp[s].second << endl;
        mark[s] = true;
    }

    for (auto it : mp) {
        if (it.second.first >= ans) {
            ans = it.second.first;
        }
    }

    int winner_index = INF;


    for (auto it : mp2) {
        if (it.first >= ans && mp[it.second.second].first == ans) {
            if (it.second.first < winner_index) {
                winner_index = it.second.first;
                winner = it.second.second;
            }
        }
    }
    
    cout << winner << "\n";
}

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
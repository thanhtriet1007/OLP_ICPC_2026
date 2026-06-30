/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int            long long

using namespace        std;

typedef pair<int, int> ii;

const int       N      = 1e6 + 7;
const long long INF     = 1e18 + 7;
const long long MOD    = 1e9 + 7;

vector<int>adj[N];
int n;

int sz[N], par[N], in[N], en[N];
int timer = 0;
vector<int>centroidList;

void preDfs(int u, int p) {
    sz[u] += 1;
    in[u] = ++timer;
    for (int &v : adj[u]) {
        if (v == p) continue;
        preDfs(v, u);
        par[v] = u;
        sz[u] += sz[v];
    }
    en[u] = timer;
}

void dfsFindCentroid(int u, int p) {
    bool isCentroid = (n - sz[u]) <= n / 2;
    for (int &v : adj[u]) {
        if (v == p) continue;
        if (sz[v] > n / 2) {
            isCentroid = false;
        }
        dfsFindCentroid(v, u);
    }
    if (isCentroid) {
        centroidList.push_back(u);
    }
}

bool isChild(int u, int p) {
    return (in[u] >= in[p] && en[u] <= en[p]);
}

void solve() {
    //World Final when?
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        par[i] = 0;
        sz[i] = 0;
        in[i] = 0;
        en[i] = 0;
    }
    centroidList.clear();

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    preDfs(1, 0);

    dfsFindCentroid(1, 0);

    //cout << centroidList.size() << endl;

    if (centroidList.size() == 1) {
        cout << par[2] << ' ' << 2 << endl;
        cout << par[2] << ' ' << 2 << endl;
        return;
    }
    else {
        int x, y; 
        x = centroidList[0];
        y = centroidList[1];
        if (par[x] == y) swap(x, y);
        for (int i = 1; i <= n; ++i) {
            if (i == x || i == y) continue;
            if (par[i] == y) {
                cout << i << ' ' << y << endl;
                cout << i << ' ' << x << endl;
                return;
            }
        }
    }

    
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
   cin >> t;
   while (t--)
   solve();
   return 0;
}

/*
Cho trước: Một cây có n đỉnh và n-1 cạnh.

Định nghĩa Trọng tâm (Centroid): Là đỉnh mà khi xóa đi, thành phần liên thông lớn nhất còn lại có số đỉnh nhỏ nhất. Một cây luôn có 1 hoặc 2 trọng tâm.

Thao tác: Chọn xóa 1 cạnh có sẵn và thêm 1 cạnh mới để đồ thị vẫn duy trì tính chất của một cây. (Được phép xóa 1 cạnh rồi thêm lại đúng cạnh đó).

Mục tiêu: Cây sau khi biến đổi phải có đúng 1 trọng tâm. Tìm và in ra thao tác xóa, thêm đó.
*/
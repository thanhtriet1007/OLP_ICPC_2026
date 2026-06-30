/* Author : Triet Do Thanh - FPT University */

#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef pair<int, int> ii;

const int N = 1e6 + 7;
const long long INF = 1e18 + 7;
const long long MOD = 1e9 + 7;

long long get_max(long long limit_A, long long limit_B, long long m)
{
   long long best = 0;

   long long pts[] = {0, limit_A, (m + 1 - limit_B) / 2, (m + 1) / 3};

   for (long long A_base : pts)
   {
      for (long long A = A_base - 2; A <= A_base + 2; A++)
      {
         if (A >= 0 && A <= limit_A)
         {
            long long B = min({m + 1 - 2 * A, limit_B, A});
            if (B >= 0)
            {
               best = max(best, A + B);
            }
         }
      }
   }
   return best;
}

void solve()
{
   // World Final when?
   int n, k, d;
   cin >> n >> d >> k;

   long long max_L = k - 1;
   long long max_R = n - k;

   long long s1 = get_max(max_L, max_R, d);
   long long s2 = get_max(max_R, max_L, d);

   cout << 1 + max(s1, s2) << "\n";
}

#define TASK "test"

signed main()
{
   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   if (fopen("input.txt", "r"))
   {
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   }
   int t = 1;
   cin >> t;
   while (t--)
      solve();
   return 0;
}

/*Problem Description:
Không gian: Một mảng 1 chiều có độ dài n. Căn cứ chính là vị trí k.

Trạng thái ban đầu: Tại vị trí k có 1 lính, các vị trí khác trống.

Quy tắc mỗi bước (lặp lại đúng m lần):

Chọn một vị trí i bất kỳ đang có lính. Lấy ra một nhóm lính từ vị trí i và cho tất cả cùng tiến sang ô liền kề (i-1 hoặc i+1). Chú ý: Nhóm lính không được đi ra ngoài đoạn [1, n].

Tự động sinh thêm 1 lính mới tại vị trí k.

Mục tiêu: Sau khi thực hiện đủ m bước (ngày), tìm cách tối đa hóa số lượng ô trong mảng có chứa ít nhất 1 lính (tức là số lượng phần tử có giá trị > 0 lớn nhất có thể).
*/
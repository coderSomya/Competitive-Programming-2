#include <bits/stdc++.h>
using namespace std;
#define loop(i, l, r) for (int i = l; i < r; i++)
#define int long long
#define pb push_back
#define vi vector<int>
#define mkp make_pair<int, int>
#define umpii unordered_map<int, int>
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define in_arr(A, n) loop(i, 0, n) cin >> A[i];
#define p_arr(A, n) loop(i, 0, n) cout << A[i]
;
#define pln_arr(A, n) loop(i, 0, n) cout << A[i] << endl
#define take_n \
    int n;     \
    cin >> n;
#define take_arr \
    int arr[n];  \
    loop(i, 0, n) cin >> arr[i];

const int mod = 1e9 + 7;
const int inf = 1e15;

vector<pair<int, int>> v;

int count_digs(int number)
{
    if (number == 0)
    {
        return 1;
    }

    // Calculate the number of digits
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }

    return count;
}

int first_dig(int number)
{
    while (number >= 10)
    {
        number /= 10;
    }

    return number;
}

bool only_one_dig(int number)
{
    if (number < 10)
    {
        return true;
    }

    // Get the first digit and check the rest
    while (number >= 10)
    {
        if (number % 10 != 0)
        {
            return false;
        }
        number /= 10;
    }
}

void solve1(int n)
{
    // n*(10^r - 1) = 9*(r) + 9*b(n-1)

    // n*10^r = 9*r+ n + 9*b(n-1)

    for(int b = 1; b <= 10000; b++)
    {
        // bs on r

        int l = 1;
        int h = 10000 - b;
        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;


            // 10^mid*n - n - 9*mid value

            int rhs = 9 * mid*n + n + 9 * b * (n - 1);


            // int lhs = n00000000000000..mid times
            int r = count_digs(rhs);
           
            if(r > mid + 1)
            {
                l = mid + 1;
            }
            else if (r < mid + 1)
            {
                h = mid- 1;
            }
            else
            {
                if (first_dig(rhs) > n)
                {
                    l = mid + 1;
                }
                else if (first_dig(rhs) < n)
                {
                    h = mid - 1;
                }
                else
                {
                    // both start with n
                    if(only_one_dig(rhs))
                    {
                        ans = mid;
                        break;
                    }
                    else
                    {
                        h = mid - 1;
                    }
                }
            }
        }

        if (ans != -1)
        {
            v.pb({ans + b, b});
        }
    }
}

void solve2(int n){
 //todo
}

void solve()
{
    int n;
    cin >> n;

    v.clear();

    if (n < 10)
    {
        solve1(n);
    }
    else
    {
        solve2(n);
    }


    cout<<v.size()<<endl;
    for(auto x: v) cout<<x.first<<" "<<x.second<<endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
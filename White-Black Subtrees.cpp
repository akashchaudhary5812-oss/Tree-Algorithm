#pragma GCC optimize("O3,unroll-loops")

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pbds tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
//typedef __int128 ell;
//typedef tree<pair<ll, ll>, null_type, less_equal<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
void print(vector<ll>& arr){for(auto it:arr){cout << it << " ";} cout << nline;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a * b) / gcd(a,b);}
ll expo(ll a, ll b, ll mod) {ll ans = 1; while(b){if(b & 1) ans *= a; ans %= mod; a *= a; a %= mod; b >>= 1;} return ans % mod;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll ceil(ll a, ll b){return (a + b - 1) / b;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void dfs(ll curr, ll parent, vector<vector<ll>>& edges, string &s, map<ll,pair<ll,ll>>& count){
     for(auto it:edges[curr]){
        if(it != parent){
          dfs(it,curr,edges,s,count);
          if(s[it - 1] == 'W'){
            if(edges[it].size() == 1 && it != 1){
                count[it] = {0,1};
                //debug(mp(curr,count[curr]))
            }
            if(count[curr].ff == 0 && count[curr].ss == 0){
                if(s[curr - 1] == 'W') count[curr] = {0,1};
                else count[curr] = {1,0};
            } 
            count[curr].ff += count[it].ff;
            count[curr].ss += count[it].ss;
          }
          else if(s[it - 1] == 'B'){
             if(edges[it].size() == 1 && it != 1){
                count[it] = {1,0};
            }
            if(count[curr].ff == 0 && count[curr].ss == 0){
                if(s[curr - 1] == 'W') count[curr] = {0,1};
                else count[curr] = {1,0};
            } 
            count[curr].ff += count[it].ff;
            count[curr].ss += count[it].ss;
          }  
        }
     }
}
void solve() {
     int tc;
     cin >> tc;
     while(tc--){
       ll n;
       cin >> n;
       vector<vector<ll>> edges(n + 1,vector<ll>());
       for(int i=2;i<=n;i++){
          ll p;
          cin >> p;
          edges[p].pb(i);
          edges[i].pb(p);
       }
       string s;
       cin >> s;
       map<ll,pair<ll,ll>> count;
       for(int i=1;i<=n;i++) count[i] = {0,0};
       dfs(1,0,edges,s,count);
       ll b = 0, w = 0;
       for(auto it:edges[1]){
          if(it != 0){
            b += count[it].ff;
            w += count[it].ss;
          }
       }
       if(s[0] == 'W') w++;
       else b++;
       count[1] = {b,w};
       ll ans = 0;
       for(auto it:count){
          pair<ll,ll> p = it.ss;
          if(p.ff == p.ss) ans++;
       }
       cout << ans << nline;
       debug(count)
     }         
}   
int main() {
 #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Debugging.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}

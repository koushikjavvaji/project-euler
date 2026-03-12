/*
*************************************************
*               Koushik's Template              *
*          Om namho Venkatesaya                 *
*************************************************
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

/************************************************
*                 Macros                        *
*************************************************/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 998244353
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long
/************************************************
*                 Typedefs                      *
*************************************************/
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/************************************************
*             Utility Functions                 *
*************************************************/
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m) { a %= m; b %= m; return (a + b) % m; }
ll mod_sub(ll a, ll b, ll m) { a %= m; b %= m; return (a - b + m) % m; }
ll mod_mul(ll a, ll b, ll m) {return (a % m * (b % m)) % m;}
ll mod_expo(ll a, ll b, ll m) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
bool revsort(ll a, ll b) { return a > b; }
vector<ll> sieve(int n) { vector<bool> is_prime(n+1, true); vector<ll> primes; for (ll i = 2; i <= n; i++) { if (is_prime[i]) { primes.push_back(i); for (ll j = i * i; j <= n; j += i) if(j<=n) is_prime[j] = false; } } return primes; }

/************************************************
*              Debugging Section                *
*************************************************/
#ifdef Koushik
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#elif !defined(ONLINE_JUDGE)
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
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

/************************************************
*               Main Function                   *
*************************************************/

string sum2Strings(string a , string b){
    int n1 = a.length() , n2 = b.length();
    int mini = min(n1 , n2);
    string v , res;
    if(mini == n1){
        int rem = n2 - n1;
        for(int i = 1 ; i <= rem ; i++){
            v += '0';
        }
        for(int i = 0 ;i < n1 ; i++){
            v += a[i];
        }
        int carry = 0;
        for(int i = n2 - 1 ; i >= 0 ; i--){
            int val1 = b[i] - '0';
            int val2 = v[i] - '0';
            int sum = val1 + val2 + carry;
            
            res += ((sum % 10) + '0');
            carry = sum / 10;
        }
        if(carry > 0){
            res += (carry + '0');
        }
        reverse(res.begin() , res.end());
    }else{
        int rem = n1 - n2;
        for(int i = 1 ; i <= rem ; i++){
            v += '0';
        }
        for(int i = 0 ;i < n2 ; i++){
            v += b[i];
        }
        int carry = 0;
        for(int i = n1 - 1 ; i >= 0 ; i--){
            int val1 = a[i] - '0';
            int val2 = v[i] - '0';
            
            int sum = val1 + val2 + carry;
            
            res += ((sum % 10) + '0');
            carry = sum / 10;
        }
        debug(res);
        if(carry > 0){
            res += (carry + '0');
        }
        reverse(res.begin() , res.end());
    }
    return res;
}
void solve(){
    
    string ans = "1";
    for(int i = 2 ; i <= 100 ; i++){
        int temp = i - 1;
        string ok = ans;
        while(temp--){
            debug(ans);
            debug(ok);
            ans = sum2Strings(ans , ok);
        }
    }
    int res = 0;
    for(int i = 0 ;i < ans.length() ; i++){
        res += (ans[i] - '0');
    }
    cout << res << nline;
}

int32_t main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

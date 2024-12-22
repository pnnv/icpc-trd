#include <bits/stdc++.h>

using namespace std;

// DEFINES
#define precision(x) cout << fixed << setprecision(x);
#define fast cin.tie(0); ios::sync_with_stdio(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
// #define nl endl
#define nl "\n"
#define sp " "
#define yes "Yes"
#define no "No"
#define int long long

// CONSTANTS
const int INF = 1e18;
const int MOD = 998244353;
// const int MOD = 1e9 + 7;

// FSTREAMS
ifstream in("input.txt");
ofstream out("output.txt");

// RANDOM
const int RMIN = 1, RMAX = 1e9;
random_device rdev;
mt19937_64 reng(rdev());
uniform_int_distribution<mt19937_64::result_type> dist(RMIN, RMAX);

// GLOBALS

// SOLUTION
void solve() {
    
}

// PREPROCESSING
void prepr() { }

// ENTRANCE
signed main() {
    precision(15);
    fast;
    prepr();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
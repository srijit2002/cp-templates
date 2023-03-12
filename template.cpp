#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <string.h>
//-------------------------------------macros-----------------------------------------------
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define color(array, value) memset(array, value, sizeof(array))
#define colorDD(array, value) fill_n(*array, sizeof(array) / sizeof(**array), value);
#define sz(x) ((ll)x.size())
#define cerr(x) cout << #x << " = " << x << endl
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define endl "\n"
#define FOR(index, lower, upper) for (ll index = lower; index < upper; index++)
#define FORD(index, upper, lower) for (ll index = upper; index > lower; index--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define containsKey(map, key) (map.find(key) != map.end())
#define umap unordered_map
#define uset unordered_set
#define CASE(x) cout << "Case " << x << ":" << endl;
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll, ll>
const ll MOD = 1e9 + 7;
const ll A_MOD = 998244353;
const ld EPS = 1e-7;
const ld PI = acos(-1.0);
const ll INF = 1e18;

/*------------------------------------Policy based data structures-------------------------------------------*/
using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*-----------custom-hash------------*/
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <class T1, class T2>
using pmap = gp_hash_table<T1, T2, custom_hash>;
template <class T>
using pset = unordered_set<T, custom_hash>;
/*----------------------Graph Moves----------------*/
const ll dx[] = {+0, +0, +1, -1, -1, +1, -1, +1}; // Kings Move L R D U
const ll dy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; // Kings Move
// const ll dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}; // Knights Move
// const ll dy[] = {-1, 1, -2, 2, -2, 2, -1, 1}; // Knights Move
/*------------------------------------------------*/

bool isBitSet(ll number, ll bit) {
    return (number & (1ll << bit)) != 0;
}

ll inverseBit(ll number, ll bit) {
    return (number ^ (1ll << bit));
}
ll setBit(ll number, ll bit) {
    return (number | (1ll << bit));
}

ll ceil_div(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

template <typename T>
T square(T v) {
    return v * v;
}
bool comp_second(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
bool comp_first_reverse(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}
bool comp_second_reverse(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

ll __lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

struct Point {
    ld x, y;
    Point() : x(0.0), y(0.0) {}
    Point(ld _x, ld _y) : x(_x), y(_y){};
};

//-------------------------------------------- fast-io----------------------------------------

void HUTH() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
}

//-----------------------------------------Operator overloads----------------------------------
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    ll n = sz(c);
    FOR(i, 0, n) {
        cout << c[i] << ((i == n - 1) ? "" : " ");
    }
    return ostream;
}
template <typename T> // cout << unordered_set<T>
ostream &operator<<(ostream &ostream, const unordered_set<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
template <typename T> // cout << ordered_set<T>
ostream &operator<<(ostream &ostream, const set<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}
istream &operator>>(istream &istream, Point &v) {
    cin >> v.x >> v.y;
    return istream;
}
//-----------------------------------------Operator overloads----------------------------------
void solve(ll);

int main() {

    HUTH();

    ll T = 1ll;
    cin >> T;
    FOR(i, 1, T + 1) {
        solve(i);
    }
}

void solve(ll TC) {
}

/*
 itne me hi thakk gaya vro?
 never compare your failure with other’s success.(which you are doing ri8 now)

 read question
 rethink your approach
 dont put --> n <-- in every for loop
 consider case = 0

 Expert before 2023
*/
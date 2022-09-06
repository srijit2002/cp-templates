#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <string.h>
//-------------------------------------macros-----------------------------------------------
#define ll long long int
#define ld long double
#define color(array, value) memset(array, value, sizeof(array))
#define cerr(x) cout << __LINE__ << " : " << #x << " = " << x << endl
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define FOR(index, lower, upper) for (ll index = lower; index < upper; index++)
#define FORD(index, upper, lower) for (ll index = upper; index > lower; index--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define containsKey(map, key) (map.find(key) != map.end())
#define umap unordered_map
#define uset unordered_set
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
//------------------------------------macros---------------------------------------------
using namespace std;
// using namespace __gnu_pbds;
// template <class T>
// using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*----------------------Graph Moves----------------*/
const ll dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const ll dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
// const ll dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
// const ll dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

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
bool comp_first(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
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
void io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    for (auto &it : c)
        cout << it << " ";
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
    io();
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
    ll T = 1ll;
    cin >> T;//comment this line for single test case
    FOR(i, 1, T + 1) {
        solve(i);
    }
}

//write your code from here
void solve(ll TC) {
    
}
#include <bits/stdc++.h>
#define ll long long int
#define pll pair<ll, ll>
const ll INF = 1e18;
using namespace std;

struct max_queue {
    deque<pll> queue;
    ll back;
    ll front;
    max_queue() : back(0), front(0) {
    }
    void add(ll val) {
        while (!queue.empty() && queue.back().second <= val) {
            queue.pop_back();
        }
        queue.push_back(make_pair(back++, val));
    }
    void remove() {
        while (!queue.empty() && queue.front().first <= front) {
            queue.pop_front();
        }
        front++;
    }
    ll get() {
        if (queue.empty())
            return -INF;
        return queue.front().second;
    }
};
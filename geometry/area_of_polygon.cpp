#include <bits/stdc++.h>
#include <iostream>

#define ll long long int
#define ld long double

using namespace std;

ll area_of_polygon(vector<pair<ll, ll>> points) {
    ll n = points.size();
    ll area = 0;
    /*
        @params
            points[i][0]=x-coordinate
            points[i][1]=y-coordinate
    */
    for (ll i = 0; i < n; i++) {
        ll x1 = points[i].first, y1 = points[i].second;
        ll x2 = points[(i + 1) % n].first, y2 = points[(i + 1) % n].second;
        ll area_of_triangle = x1 * y2 - x2 * y1;
        area += area_of_triangle;
    }
    return abs(area)/2;
}

#include <bits/stdc++.h>
#include <iostream>

#define ld long double
#define ll long long int
using namespace std;

ll get_orientation(pair<ll, ll> point1, pair<ll, ll> point2, pair<ll, ll> point3) {
    ll x1 = point1.first;
    ll y1 = point1.second;
    ll x2 = point2.first;
    ll y2 = point2.second;
    ll x3 = point3.first;
    ll y3 = point3.second;
    ll val = (x3 - x2) * (y2 - y1) - (x2 - x1) * (y3 - y2);
    /*
        @return 
            clockwise -1
            anticlockwise 1
            colinear 0

    */

    if (val > 0)
        return -1;
    else if (val < 0)
        return 1;
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

#define ld long double
#define ll long long int
using namespace std;

ld area_of_triangle(pair<ll,ll> point1,pair<ll,ll> point2,pair<ll,ll> point3){
    ll x1=point1.first;
    ll y1=point1.second;
    ll x2=point2.first;
    ll y2=point2.second;
    ll x3=point3.first;
    ll y3=point3.second;
    ld area=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
    return area/2.0;
}
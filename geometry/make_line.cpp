#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int

vector<ll> make_line(pair<ll,ll>point1,pair<ll,ll>point2){
    /*
        @params
            point1={x1,y1}
            point2={x2,y2}
    */
    ll x1=point1.first;
    ll y1=point1.second;
    ll x2=point2.first;
    ll y2=point2.second;
    ll a = y2 - y1;
    ll b = x1 - x2;
    ll c = a * x1 + b * y1;
    /*
        @returns
            The form of line is 
                ax+by=c
    */
    return vector<ll>{a,b,c};
}
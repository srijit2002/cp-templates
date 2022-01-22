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
bool lie_on_segement(pair<ll,ll>point1,pair<ll,ll>point2,pair<ll,ll>point3){
    return point3.first>=min(point1.first,point2.first)&&point3.first<=max(point1.first,point2.first)&&point3.second>=min(point1.second,point2.second)&&point3.second<=max(point1.second,point2.second);
}
bool do_line_segments_intersect(pair<ll, ll> point1, pair<ll, ll> point2, pair<ll, ll> point3, pair<ll, ll> point4) {
   ll o1=get_orientation(point1,point2,point3);
   ll o2=get_orientation(point1,point2,point4);
   ll o3=get_orientation(point3,point4,point1);
   ll o4=get_orientation(point3,point4,point2);
   if((o1!=o2)&&(o3!=o4))return true;
   if(o1==0&&lie_on_segement(point1,point2,point3)||o2==0&&lie_on_segement(point1,point2,point4))return true;
   if(o3==0&&lie_on_segement(point3,point4,point1)||o4==0&&lie_on_segement(point3,point4,point2))return true;
   return false;
}
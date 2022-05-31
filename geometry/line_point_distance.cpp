#include <iostream>
#include <bits/stdc++.h>

#define ld long double
#define ll long long int
using namespace std;

ld line_point_distance(vector<ll>line,pair<ll,ll>point){
    /*
        @params
            line[0]=a
            line[0]=b
            line[0]=c
        line in the form of 
            ax+by=c

        point.first=x-coordinate
        point.second=y-coordinate
    */
    ll a=line[0];
    ll b=line[1];
    ll c=line[2];

    ll x=point.first;
    ll y=point.second;
    /*
        formula for perpendicular distance
           ax1+by1-c/sqrt(b^2+c^2)
    */
   /*
        @returns
            perpendicular distance of point from line
   */
    ld up=abs(a*x+b*y-c)*1.0;
    ld down=sqrt(a*a*1.0+b*b*1.0);
    return fabs(up/down);
}
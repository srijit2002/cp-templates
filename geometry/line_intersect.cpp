#include <bits/stdc++.h>
#include <iostream>

#define ll long long int
#define ld long double

using namespace std;

vector<ld> get_intersection_point_of_two_lines(vector<ll> line1, vector<ll> line2) {
    /*
        @parameters 
            line1 {x1,y1,x2,y2}
            line2 {x3,y3,x4,y4}

    */
    ll x1 = line1[0];
    ll y1 = line1[1];
    ll x2 = line1[2];
    ll y2 = line1[3];

    ll x3 = line2[0];
    ll y3 = line2[1];
    ll x4 = line2[2];
    ll y4 = line2[3];

    /*    @returns
            vector[0]--> x-coordinate of intersection
            vector[1]--> y-coordinate of intersection
            vector[2]-->
                if(1)lines intersect
                else if(0) lines don't intersect
                else if(2) Two lines are the part of same line
    */

    ll a1 = y2 - y1;
    ll b1 = x1 - x2;
    ll c1 = a1 * x1 + b1 * y1;

    ll a2 = y4 - y3;
    ll b2 = x3 - x4;
    ll c2 = a2 * x3 + b2 * y3;

    ll det = a1 * b2 - a2 * b1;
    if (det == 0) { //lines are parrallel
        if (b1 != 0 && b2 != 0) {
            ld intersept1 = c1 * 1.0 / b1;
            ld intersept2 = c2 * 1.0 / b2;
            if (intersept1 == intersept2) { //they are on same line
                return vector<ld>{0, 0, 2};
            }
            return vector<ld>{0, 0, 0}; //they are parrallel
        } else if (b1 == 0 && b2 == 0) {
            if (a1 != 0 && a1 != 0) {
                ld intersept1 = c1 * 1.0 / a1;
                ld intersept2 = c2 * 1.0 / a2;
                if (intersept1 == intersept2) { //they are on same line
                    return vector<ld>{0, 0, 2};
                }
                return vector<ld>{0, 0, 0}; //they are parrallel
            }
            if (a1 == 0 && a1 == 0) {
                return vector<ld>{0, 0, 2};//they are on same line
            }

            return vector<ld>{0, 0, 0}; //they are parrallel
        }
        return vector<ld>{0, 0, 0}; //they are parrallel
    }
    ld x = (b2 * c1 - b1 * c2) * 1.0 / det;
    ld y = (a1 * c2 - a2 * c1) * 1.0 / det;
    return vector<ld>{x, y, 1};
}
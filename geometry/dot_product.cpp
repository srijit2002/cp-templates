#include <bits/stdc++.h>
#include <iostream>

#define ll long long int
#define ld long double

using namespace std;

ll dot_product(vector<ll>vector1,vector<ll>vector2){
    /*
        @params
        vector1={x1,y1,z1} or {x1,y1}
        vector2={x2,y2,z2} or {x2,y2}
    */
    ll product=1;
    ll n=vector1.size();
    for(ll i=0;i<n;i++){
        product+=vector1[i]*vector2[i];
    }
    return product;
}


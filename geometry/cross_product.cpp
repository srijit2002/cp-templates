#include <bits/stdc++.h>
#include <iostream>

#define ll long long int
#define ld long double

using namespace std;
vector<ll> cross_product(vector<ll>vector1,vector<ll>vector2){
    /*
        @params
        vector1={a1,a2,a3}
        vector2={b1,b2,b3}
    */
    vector<ll>answer(3);
    answer[0]=vector1[1] * vector2[2] - vector1[2] * vector2[1];
    answer[1]=vector1[2] * vector2[0] - vector1[0] * vector2[2];
    answer[2]=vector1[0] * vector2[1] - vector1[1] * vector2[0];
    return answer;
}
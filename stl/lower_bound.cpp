/*
    @returns 
      if(the element present then returns it )
      else the element ehcih is just greater this element
*/ 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll find_greater(ll start, ll end, ll v, vector<ll> &nums) {
    ll ans = -1;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (nums[mid] >= v) {
            ans = mid;
            end = mid - 1;
        } else
            start = mid + 1;
    }
    return nums[ans];
}
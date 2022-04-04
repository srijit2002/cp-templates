#include <bits/stdc++.h>
#include <iostream>
#define FOR(index, lower, upper) for (ll index = lower; index < upper; index++)
#define ll long long int
using namespace std;
/**
 * @brief multiplies two matrix and stores
 *  the final result into the first(i.e a) matrix
 * @param a 
 * @param b 
 * @param dimension 
 */
void multiply_matrix(vector<vector<ll>> &a, vector<vector<ll>> &b, ll dimension) {
    vector<vector<ll>> ans(dimension, vector<ll>(dimension, 0));
    FOR(i, 0, dimension) {
        FOR(j, 0, dimension) {
            FOR(k, 0, dimension) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    FOR(i, 0, dimension) {
        FOR(j, 0, dimension) {
            a[i][j] = ans[i][j];
        }
    }
}
/**
 * @brief Create a identity matrix object
 * 
 * @param dimension 
 * @return vector<vector<ll>> -->identity matrix
 */
vector<vector<ll>> create_identity_matrix(ll dimension) {
    vector<vector<ll>> ans(dimension, vector<ll>(dimension, 0));
   FOR(i, 0, dimension) {
        ans[i][i] = 1;
    }
    return ans;
}

/**
     * @brief Construct a new vector<vector<ll>>matrix exporential object
     *  matrix exporential function that calulculates
        matrix^n in O(dimesnion^3*log(n)) time complexity
     * @param matrixa 
     * @param dimension 
     * @param pow 
     */
vector<vector<ll>> matrix_exporential(vector<vector<ll>> &matrixa, ll dimension, ll pow) {
    vector<vector<ll>> res = create_identity_matrix(dimension);
    while (pow) {
        if (pow % 2 == 0) {
            multiply_matrix(matrixa, matrixa, dimension);
            pow /= 2;
        } else {
            multiply_matrix(res, matrixa, dimension);
            pow--;
        }
    }
    FOR(i, 0, pow) {
        multiply_matrix(res, matrixa, dimension);
    }
    return res;
}

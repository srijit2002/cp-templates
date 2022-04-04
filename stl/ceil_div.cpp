/**
 * @brief returns ceil value of a/b
 * like ceil_div(3/2)=ceil_div(1.5)=2
 * @param parameter-a,b two numbers
 */

#define ll long long int
ll ceil_div(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}
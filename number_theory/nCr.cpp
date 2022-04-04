/*
    This function should be used when you can store
    the result but you can not calculate it using factorial
    due to its large value
*/
ll nCr(ll n,ll r,umap<string,ll>&memo){
    if(n<r)return 0;
    if(n==r||r==0)return 1;
    string key=to_string(n)+"#"+to_string(r);
    if(containsKey(memo,key))return memo[key];
    memo[key]=nCr(n-1,r,memo)+nCr(n-1,r-1,memo);
    return memo[key]; 
}
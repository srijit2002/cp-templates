ll binExp(ll a,ll b,ll M){
    ll result =1;
    while(b>0){
        if(b&1){
            result=(result*a*1LL)%M;
        }
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return result;
}
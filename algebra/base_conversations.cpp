/*
    This does what you think it does
*/    

ll decimal_to_any_base(ll number,ll base){
    string ans="";
    while(number!=0){
        ans+=to_string(number%base);
        number/=base;
    }
    reverse(all(ans));
    return stoll(ans);
}
ll any_base_to_decimal(ll number,ll base){
    ll ans=0;
    ll pow=1;
    while(number>0){
        ans+=(number%10)*pow;
        pow*=base;
        number/=10;
    }
    return ans;
}
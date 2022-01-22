/*
    rec1 and rec2 should contain cooordinates of
    two opposite corners of the rectangles bottom-left and top-right;
*/
bool do_rectangles_overlap(vector<pair<ll,ll>>rec1,vector<pair<ll,ll>>rec2){
    if(rec1[0].first>rec2[0].first)swap(rec1,rec2);
    if(rec1[1].first<=rec2[0].first)return false;
    if(rec1[0].second>rec2[0].second)swap(rec1,rec2);
    if(rec1[1].second<=rec2[0].second)return false;
    return true;
}
vector<pair<ll,ll>> find_intersection_of_two_rectangle(vector<pair<ll,ll>>rec1,vector<pair<ll,ll>>rec2){
    vector<pair<ll,ll>>ans;
    ll xll=max(rec1[0].first,rec2[0].first);
    ll yll=max(rec1[0].second,rec2[0].second);
    ll xul=min(rec1[1].first,rec2[1].first);
    ll yul=min(rec1[1].second,rec2[1].second);
    pair<ll,ll>p1={xll,yll};
    pair<ll,ll>p2={xul,yul};
    ans.emplace_back(p1);
    ans.emplace_back(p2);
    return ans;
}
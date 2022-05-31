/*
Don't forget to use cin.ignore() before getline
*/
vector<ll> tokenize(string s, string del = " ") {
    ll start = 0;
    ll end = s.find(del);
    vector<ll> ans;
    while (end != -1) {
        ans.emplace_back(stoll(s.substr(start, end - start)));
        start = end + del.size();
        end = s.find(del, start);
    }
    ans.emplace_back(stoll(s.substr(start, end - start)));
    return ans;
}
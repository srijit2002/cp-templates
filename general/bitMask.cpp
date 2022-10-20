ll toggleBit(ll mask, ll index) {
    return mask ^ (1ll << index);
}
ll setBit(ll mask, ll index) {
    return mask | (1ll << index);
}
ll getBit(ll mask, ll index) {
    return mask & (1ll << index);
}
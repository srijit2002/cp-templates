double root(double _val) {
    double low = 0; 
    double high = _val;
    double mid = 0; 

    for(int i=0;i<100;i++){
            mid = low + (high - low) / 2; // finding mid value
            if (mid*mid > _val) {
                high = mid;
            } else {
                low = mid;
            }    
    }   
    return mid;
}
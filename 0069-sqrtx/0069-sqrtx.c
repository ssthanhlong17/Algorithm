int mySqrt(int x) {
    long left = 0;
    long right = x;
    int ans;
    while(left <= right)
    {
        long mid = left + (right - left)/2;
        if(mid * mid == x ) return mid;

        else if( mid * mid < x){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return ans; 
}
bool isPerfectSquare(int num) {
    long left = 0;
    long right = num;
    while(left <= right){
        long mid = left + (right - left)/2;
        long result = mid * mid;
        if(result == num) return true;
        if(result > num) right = mid - 1;
        else left = mid + 1;    
    }
    return false;
}

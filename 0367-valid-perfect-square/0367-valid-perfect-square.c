bool isPerfectSquare(int num) {
    int left = 0;
    int right = num;
    while(left <= right){
        int mid = left + (right - left)/2;
        long result = mid * mid;
        if(result == num) return true;
        if(result > num) right = mid - 1 ;
        else left = mid + 1;    
    }
    return false;
}

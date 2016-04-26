/*
    This problem requires BigInteger class in Java. However, I only use c++ so I can't solve this problem. But I can describe the idea here and provide a code which passes the problem in interviewBit.com
*/

/*  =============== Solution Description ===================
In maximum range SUM problem, the dynamic structure is dp(i) = max(dp(i-1)+A[i], A[i]). Namely, the maximum value ending at A[i] is either itself, or itself + the maximum value ending at A[i-1]. In this problem, however, the situation is a bit different. We can't simply modify the '+' to be '*'. The reason is that we have negative values in our input. For example, [1, -2, -3], we will need the product -2 which is made by multiply 1 & -2. This -2 is clearly a maximum product ending at -2 but we still have to use it.
At this moment, the sub-optimal structure seems not to hold. However, notice that, when A[i] is a negative value, if we multiply A[i] by the minimum product ending at A[i-1], we may still get a maximum product. Up to now, the sub-optimal structure seems to re-emerge.
So, the in this problem, we keep two vector variables, maximum & minimum.
    maximum[i] = max( max(maximum[i-1]*A[i], minimum[i-1]*A[i]),   A[i]);
    minimum[i] = min( min(maximum[i-1]*A[i], minimum[i-1]*A[i]),   A[i]);
    result = max(maximum[i], result);
*/

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size(), result = A[0];
    vector<int> maximum(n, 0);  maximum[0] = A[0];
    vector<int> minimum(n, 0);  minimum[0] = A[0];
    for(int i = 1; i < n; ++i){
        maximum[i] = max(max(maximum[i-1]*A[i], minimum[i-1]*A[i]), A[i]);
        minimum[i] = min(min(minimum[i-1]*A[i], maximum[i-1]*A[i]), A[i]);
        result = max(maximum[i], result);
    }
    return result;
}

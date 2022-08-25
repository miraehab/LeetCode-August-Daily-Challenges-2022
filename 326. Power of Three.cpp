class Solution {
public:
    double log3(int n){
        return (log10(n) / log10(3));
    }
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        return (floor(log3(n)) == ceil(log3(n)));
    }
};
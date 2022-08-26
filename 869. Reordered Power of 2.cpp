class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> powers2(30, vector<int>(10, 0));
        int pow = 1;
        for(int i = 0; i < 30; ++i){
            int tmp = pow;
            while(tmp != 0){
                int digit = tmp%10;
                powers2[i][digit]++;
                tmp/=10;
            }
            pow*=2;
        }
        
        int tmp_n = n;
        vector<int> freq_n(10, 0);
        while(tmp_n != 0){
            int digit = tmp_n%10;
            freq_n[digit]++;
            tmp_n /= 10;
        }
        
        for(int i = 0; i < 30; ++i){
            bool flag = true;
            for(int j = 0; j < 10; ++j){
                if(freq_n[j] != powers2[i][j]){ 
                    flag = false; 
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};
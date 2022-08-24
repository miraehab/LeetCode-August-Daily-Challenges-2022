class Solution {
public:
    int romanToInt(string s) {
        map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = 0;
        for(int i = 0; i < s.length(); i+=2){
            if(values[s[i+1]] > values[s[i]]){
                ans += (values[s[i+1]]-values[s[i]]);
            }else{
                ans += values[s[i]];
                --i;
            }
        }
        return ans;
    }
};
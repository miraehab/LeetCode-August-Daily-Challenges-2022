class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> codes;

        for(string word : words) {
            string code = "";
            for(char ch : word)
                code += morse_code[ch - 'a'];
            codes.insert(code);
        }

        return codes.size();
    }
};
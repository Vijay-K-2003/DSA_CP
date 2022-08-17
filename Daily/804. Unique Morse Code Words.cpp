class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        string alphabets[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(string w : words) {
            string morse = "";
            for(int i = 0 ; i < w.size() ; i++) {
                morse += alphabets[w[i] - 'a'];
            }
            s.insert(morse);
        }
        return s.size();
    }
};

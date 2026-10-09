class Solution {
public:
    int minInsertions(string s) {
        int openbracket = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') openbracket++;
            else{
                if(i + 1 < s.size() && s[i + 1] == ')') i++;
                else ans++;

                if (openbracket > 0) openbracket--;
                else ans++;
            }
        }
        return ans + openbracket * 2;
    }
};

#include <unordered_map>

class Solution {
    
public:

    int solve(string& s, unordered_map<string,int>& memo) {
        auto it = memo.find(s);
        if (it != memo.end()) return it->second;
        
        if (s.size() == 0)
            return 1;
        else{
            string temp1 = s.substr(1);
            int tmp=0;
            if (s[0]-'0' != 0)
                tmp += solve(temp1, memo);
                
            if (s.size() > 1){
                string temp2 = s.substr(2);
                if (s[0] - '0' == 1)
                    tmp += solve(temp2, memo);
                else if (s[0]-'0' == 2 && s[1]-'0' <= 6)
                    tmp += solve(temp2, memo);
            }
            memo[s] = tmp;
            
            return tmp;
        }
        
    }

    int numDecodings(string s) {
        unordered_map<string,int> memo; // memo[s] -> ways to decode string s
        int n = s.size();
        if (n==0) return 0;
        return solve(s, memo);
        
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int lp=0;
        int rp=s.size()-1;
        while(lp < rp){
            if(!isalnum(s[lp])){
                lp++;
                continue;
            }
            if(!isalnum(s[rp])){
                rp--;
                continue;
            }

            if(s[lp]!=s[rp])return false;
            lp++;
            rp--;
        }
        return true;
    }
};
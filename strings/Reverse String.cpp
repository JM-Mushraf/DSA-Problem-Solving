class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int lp=0;
        int rp=n-1;
        while(lp < rp){
                swap(s[lp],s[rp]);
                lp++;
                rp--;
        }
    }
};
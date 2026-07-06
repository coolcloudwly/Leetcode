class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int num=0;
        int left=0;
        for (int i=0;i<s.size();i++){
            char c=s[i];
            if(hash.find(c)!=hash.end()&&hash[c]>=left){
                left=hash[c]+1;
            }
            hash[c]=i;
            num=max(num,i-left+1);
        }
        return num;
    }
};
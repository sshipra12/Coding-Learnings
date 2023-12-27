class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i,ind=0,n=t.size();  //NOTE: when t.size()/s.size()=0 , then t.size()-1 or s.size()-1 doesn't = -1
        for(i=0;i<=n-1&&ind<=s.size()-1;i++){
            if(t[i]==s[ind])
                ind++;
        }
        // substring index (here ind) reaching s.size() means we found the whole subtring s in the string t
        if(ind==s.size())
            return true;
        else return false;
    }
};

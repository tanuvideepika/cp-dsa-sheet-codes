//https://leetcode.com/problems/longest-common-prefix/

class Solution {
    public:
    
        string commonPrefix(string s1, string s2){
            if(s1=="" || s2=="")return "";
    
            string common="";
            int n=s1.size(), m=s2.size();
            if(m>n){
                return commonPrefix(s2,s1);
            }
            
            for(int i=0;i<n;i++){
                if(s1[i]==s2[i]){
                    common+=s1[i];
                }else{
                    break;
                }
            }
    
            return common;
        }
    
        string longestCommonPrefix(vector<string>& strs) {
            string ans=strs[0];
            for(auto &x:strs){
                ans=commonPrefix(ans, x);
                //added condition for optimization
                if(ans=="")return "";
            }
            return ans;
        }
};
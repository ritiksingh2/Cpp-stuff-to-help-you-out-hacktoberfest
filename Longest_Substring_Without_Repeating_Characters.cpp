class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string distinctStr="";
        int maxLength=0;
        for(int i=0; i<s.length(); i++){
            size_t found = distinctStr.find(s[i]); 

            if(found!=string::npos){
                int indexofThisChar=distinctStr.find(s[i]);
                if(maxLength<(distinctStr.length())){
                    maxLength=distinctStr.length();
                }
                distinctStr.erase(distinctStr.begin(), distinctStr.begin()+indexofThisChar+1);
                distinctStr+=s[i];

                // cout<<distinctStr<<endl;
            }
            else{
                distinctStr+=s[i];
            }
        }

        if(distinctStr.length()>maxLength){
            maxLength=distinctStr.length();
        }
        
        return maxLength;
    }
};

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int i;
        // LEETCODE Problem : Check if the Sentence Is Pangram (i.e check if string contains all 26 alphabets)
      
        vector<bool> alphabets(26,false);   //array of sizwe 26 to store presence of alphabets(0 to 25 denoting a to z)
      
        //we create 26 size array to check which alphabets are present in string
        //we iterate over the given string and use each char in string 
        //as index for alphabets array by subtracting 97 (starting ASCII of lowercase) to ith char (example 'a'-97 = 0)
      
        for(i=0;i<sentence.size();i++){
            alphabets[sentence[i]-97]=true;;  //example 'a'-97 = 0 and will mark 0th index of alphabets array true
                                              //denoting char 'a' is present , 'b-97' = 1 and so on 
        }
        for(i=0;i<26;i++){
            if(alphabets[i]==false)
                return false;
        }
        return true;
    }
};

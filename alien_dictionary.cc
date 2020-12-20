class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> ord(26, 0);
        
        // Get true numbered order of alphabets
        for (int i = 0; i < order.size(); i++)
            ord[order.at(i) - 'a'] = i;
        

        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words.at(i);
            string word2 = words.at(i + 1);
            
            for (int j = 0; j < std::min(word1.size(), word2.size()); j++) {
                
                char c1 = word1.at(j);
                char c2 = word2.at(j);
                
                if (c1 != c2) {
                    if (ord.at(c1 - 'a') > ord.at(c2 - 'a'))
                        return false;
                    
                    // continue searching (continue outer for loop)
                    goto cont;
                }   
            }
            
            // If there was no difference then check if the first word
            // is bigger than the second word
            if (word1.size() > word2.size())
                return false;
            
            // placeholder label to continue outer loop from a nested loop
            cont:;
        }
        
        return true;
    }
};

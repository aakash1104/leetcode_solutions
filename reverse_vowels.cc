class Solution {
public:
    string reverseVowels(string s) {
        string t = s;
        int i = 0, j = s.size() - 1;
        
        while (i < j) {
            if (isvowel(t[i]) && isvowel(t[j]))
                std::swap(t[i++], t[j--]);
            
            else if (isvowel(t[i]) && !isvowel(t[j]))
                j--;
            
            else if (!isvowel(t[i]) && isvowel(t[j]))
                i++;
            
            else {
                i++;
                j--;
            }
        }
        return t;
    }
private:
    bool isvowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        
        return false;
    }
};

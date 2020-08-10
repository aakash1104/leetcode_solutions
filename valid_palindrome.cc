class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;
        
        while (front < back) {
            if (std::isalnum(s[front]) && std::isalnum(s[back])) {
                if (tolower(s[front]) != tolower(s[back]))
                    return false;
                else {
                    front++;
                    back--;
                }
            } 
            else if (std::isalnum(s[front]) && !std::isalnum(s[back]))
                back--;
            else if (!std::isalnum(s[front]) && std::isalnum(s[back]))
                front++;
            else {
                front++;
                back--;
            }
        }
        
        return true;
    }
};

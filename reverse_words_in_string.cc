class Solution {
public:
    string reverseWords(string s) {
        std::deque<string> dq;
        std::string build;
        std::string t;
        
        if (s.empty())
            return "";
        
        for (int i = 0; i< s.size(); i++) {
            if (isspace(s[i]) && !build.empty()) {
                dq.push_front(build);
                build.clear();    
            }
            
            else if (isalnum(s[i]) || ispunct(s[i]))
                build += s[i];
        }
        
        
        if (!build.empty()) {
            dq.push_front(build);
            build.clear();
        }
        
        if (dq.empty())
            return "";
        
        for (int i = 0; i < dq.size() - 1; i++) {
            t.append(dq.at(i));
            t += ' ';
        }
        
        t.append(dq.at(dq.size() - 1));
        
        return t;
    }
};

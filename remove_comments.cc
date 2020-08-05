class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> s;
        string build;
        bool block_comment = false;

        for (auto line : source) {
            for (int i = 0; i < line.size(); i++) {
                string next_two = line.substr(i, 2);

                if (!block_comment) {
                    if (next_two == "//") 
                        break;
                    else if (next_two == "/*") {
                        block_comment = true;
                        i++;
                    }
                    else
                        build.push_back(line[i]);
                } else if (next_two == "*/") {
                    block_comment = false;
                    i++;
                }
            }

            if (!block_comment && !build.empty()) {
                s.push_back(build);
                build.clear();
            }
        }

        return s;
    }
};

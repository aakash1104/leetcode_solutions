class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        std::multimap<string, string> map;
        std::vector<string> letter;
        std::vector<string> digit;
        std::vector<string> dup;
        std::vector<string> output;

        for (auto l : logs) {
            auto pos = l.find(" ");
            if (l.at((pos + 1)) < 'a') {
                digit.push_back(l);
            } else {
                string first(l.begin() + pos + 1, l.end());
                string second(l.begin(), l.begin() + pos);
                letter.push_back(first);
                map.emplace(first, second);
            }
        }

        sort(letter.begin(), letter.end());

        for (auto iter = letter.begin(); iter != letter.end(); iter++) {
            // Traverse through each of the letter logs
            auto l = *iter;
            if (map.count(l) > 1) {
                // Have multiple keys with same string
                auto range = map.equal_range(l);
                for (auto it = range.first; it != range.second; it++) {
                    string d = it->second + " " + it->first;
                    dup.push_back(d);
                    map.erase(it);
                }
                sort(dup.begin(), dup.end());
                output.insert(output.end(), dup.begin(), dup.end());
                dup.clear();
                letter.erase(iter);
            } else {
                auto l_log = map.find(l);
                string let = l_log->second + " " + l_log->first;
                output.push_back(let);
            }
        }
        output.insert(output.end(), digit.begin(), digit.end());
        return output;
    }
};

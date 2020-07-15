class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> ht;
        unordered_set<string> banned_ht;
        string word;
        string most_common;
        int max_freq = 0;

        // use a ht for banned words for little optimization
        for (auto w : banned)
            if (banned_ht.find(w) == banned_ht.end())
                banned_ht.emplace(w);

        for (auto c : paragraph) {
            if (isalpha(c))
                // build word
                word += std::tolower(c);

            else if (isspace(c) || ispunct(c)) {
                if (word.empty()) continue;

                if (banned_ht.find(word) != banned_ht.end()) {
                    // Found a word that's banned, invalidate and move on
                    word.clear();
                    continue;
                }
                if (ht.find(word) == ht.end())
                    ht.emplace(word, 1);
                else
                    ht.find(word)->second++;
                word.clear();
            }
        }

        // Proceed to add the last word processed if it isn't banned
        if (!word.empty() && (banned_ht.find(word) == banned_ht.end())) {
            if (ht.find(word) == ht.end())
                    ht.emplace(word, 1);
            else
                ht.find(word)->second++;
        }

        most_common = ht.begin()->first;
        max_freq = ht.begin()->second;

        for (auto w : ht) {
            if (w.second > max_freq) {
                max_freq = w.second;
                most_common = w.first;
            }
        }

        return most_common;

    }
};

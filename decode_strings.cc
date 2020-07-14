class Solution {
public:
    string decodeString(string s) {
        string internal = "";
        int num = 0;

        std::stack<int> rep;
        std::stack<string> build;

        for (auto c : s) {
            if (isdigit(c))
                num = (num * 10) + (c - '0');

            else if (isalpha(c))
                internal += c;

            else if (c == '[') {
                if (!internal.empty()) {
                    build.push(internal);
                    internal.clear();
                } else {
                    build.push("");
                }
                rep.push(num);
                num = 0;
            }

            else if (c == ']') {
                string t;

                for (int i = 0; i < rep.top(); i++)
                    t.append(internal);

                internal = build.top();
                rep.pop();
                build.pop();
                internal.append(t);
            }
        }

        return internal;
    }
};

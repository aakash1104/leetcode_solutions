class Solution {
public:
    string fractionAddition(string expression) {
        std::istringstream in(expression);
        int A = 0, B = 1;
        int a, b;
        char slash;

        while (in >> a >> slash >> b) {
            A = A * b + a * B;
            B *= b;

            int g = std::abs(std::gcd(A, B));

            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
};

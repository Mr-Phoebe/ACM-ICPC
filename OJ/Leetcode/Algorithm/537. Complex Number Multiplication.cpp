class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1, b1, a2, b2;
        sscanf(a.c_str(), "%d+%di", &a1, &a2);
        sscanf(b.c_str(), "%d+%di", &b1, &b2);
        int a3 = a1*b1-a2*b2;
        int a4 = a1*b2+a2*b1;
        return to_string(a3)+"+"+to_string(a4)+"i";
    }
};

class Solution {
public:

    string encode(vector<string>& strs) {
        // len#str
        std::stringstream ss;
        for (std::string& s: strs) {
            ss << s.size() << '#' << s;
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        std::vector<std::string> res;
        size_t n = 0;
        int len = 0;
        while ((n = s.find_first_of('#')) != s.npos) {
            // n = s.find_first_of('#');
            // std::cout << n << " " << s << "\n";
            len = std::stoi(s.substr(0, n));
            res.push_back(s.substr(n+1, len));
            s = s.substr(n + 1 + len);
            // std::cout << s << "\n";
        }
        return res;
    }
};

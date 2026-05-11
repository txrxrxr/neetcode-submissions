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
        size_t n = 0;   // pos of #
        size_t pos = 0; // starting point to search for next encoded string
        while ((n = s.find_first_of('#', pos)) != s.npos) {
            // n = s.find_first_of('#');
            // std::cout << n << " " << s << "\n";
            int len = std::stoi(s.substr(pos, n - pos));
            // std::cout << len << "\n";
            res.push_back(s.substr(n + 1, len));
            pos = n + len + 1;
            // std::cout << pos << "\n";
        }
        return res;
    }
};

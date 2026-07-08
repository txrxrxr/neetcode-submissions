#include <print>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> hs;
        int d = n;
        int sum = 0;
        while (d > 0) {
            hs.insert(d);
            
            while (d > 0) {
                sum += (d % 10) * (d % 10);
                d /= 10;
                // std::println("{}", d);
            }

            // std::println("{}", sum);

            if (sum == 1) {
                return true;
            }

            if (hs.count(sum) > 0)
                break;

            d = sum;
            sum = 0;
        }
        return false;
    }
};

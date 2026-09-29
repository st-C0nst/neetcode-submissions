#include <string>

class Solution {
public:
    string encode(vector<string>& strs) {
        std::string encoded_str{};
        for (const auto& str : strs) {
            encoded_str += std::to_string(str.length()) +
            delimiter_ + str;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded_strs{};
        
        for (int i = 0; i < s.size();) {
            const auto delimiter_pos = s.find(delimiter_, i);        
            std::size_t curr_size{};
            std::from_chars(
               s.data() + i,
               s.data() + delimiter_pos,
               curr_size
            );
            i = delimiter_pos + 1;
            decoded_strs.emplace_back(s.substr(i, curr_size));
            i += curr_size;
        }
        return decoded_strs;
    }
private:
    const char delimiter_ = '\\';
};

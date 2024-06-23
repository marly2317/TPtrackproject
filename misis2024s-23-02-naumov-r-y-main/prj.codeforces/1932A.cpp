#include <iostream>

int main() {
    int n_testcases(0);
    std::cin >> n_testcases;
    for (int i(0); i < n_testcases; ++i) {
        int string_len(0);
        std::cin >> string_len;
        std::string i_string("");
        std::cin >> i_string;
        int i_ans(0);
        int valid_len = i_string.find("**");
        valid_len = (valid_len == std::string::npos) ? string_len : valid_len;
        for (int j(0);
            j < valid_len;
            ++j, i_ans += (i_string[j] == '@')
            );
        std::cout << i_ans << '\n';
    }
    return 0;
}
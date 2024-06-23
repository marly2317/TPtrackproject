#include <iostream>

int main() {
    int n_testcases(0);
    std::cin >> n_testcases;
    for (int i_testcase(0); i_testcase < n_testcases; ++i_testcase) {
        int string_len(0);
        std::cin >> string_len;
        std::string input_str("");
        std::cin >> input_str;
        int ans(0);
        std::size_t pos = input_str.find("pie");
        while (pos != std::string::npos) {
            ++ans;
            pos = input_str.find("pie", pos + 1);
        }
        pos = input_str.find("map");
        while (pos != std::string::npos) {
            ++ans;
            pos = input_str.find("map", pos + 1);
        }
        pos = input_str.find("mapie");
        while (pos != std::string::npos) {
            ans -= 1;
            pos = input_str.find("mapie", pos + 1);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
#include <iostream>


bool is_correct() {
    int n_els(0);
    std::cin >> n_els;
    int n1(0);
    int n2(0);
    int n3(0);
    std::cin >> n2;
    std::cin >> n3;
    int amount = n2 + n3;
    for (int i_n(2); i_n < n_els; ++i_n) {
        n1 = n2;
        n2 = n3;
        std::cin >> n3;
        amount += n3;
        if (n1 == 0) {
            continue;
        }
        if (n1 * 2 <= n2 && n1 <= n3) {
            n2 -= n1 * 2;
            n3 -= n1;
            amount -= n1 * 4;
        }
        // std::cout << n1 << " ";
        // std::cout << amount << " ";
    }
    // std::cout << '\n';
    return !(bool(amount));
}


int main() {
    // std::cout << (is_correct() ? "YES\n" : "NO\n");
    int n_testcases(0);
    std::cin >> n_testcases;
    for (int i_testcase(0); i_testcase < n_testcases; ++i_testcase) {

        // std::cout << '\n';
        std::cout << (is_correct() ? "YES\n" : "NO\n");
    }
    return 0;
}
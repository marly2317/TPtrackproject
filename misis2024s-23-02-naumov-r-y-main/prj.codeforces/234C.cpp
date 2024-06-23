#include<fstream>
#include<vector>

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int n_nums(0);
    cin >> n_nums;
    std::vector<int> prefix_sum_minus = { 0 };
    std::vector<int> prefix_sum_zero = { 0 };
    for (auto i_num(0); i_num < n_nums; ++i_num) {
        int num(0);
        cin >> num;
        prefix_sum_minus.push_back(prefix_sum_minus[i_num]);
        prefix_sum_zero.push_back(prefix_sum_zero[i_num]);
        if (num < 0) {
            ++prefix_sum_minus[i_num + 1];
        }
        if (num == 0) {
            ++prefix_sum_zero[i_num + 1];
        }
    }
    long long n_min_changes(1e11);
    for (auto i_num(0); i_num < n_nums - 1; ++i_num) {
        int n_right_minus_numbers = prefix_sum_minus[n_nums] - prefix_sum_minus[i_num + 1];
        int n_left_plus_numbers = i_num + 1 - prefix_sum_minus[i_num + 1];
        int new_min = n_left_plus_numbers + n_right_minus_numbers + (prefix_sum_zero[n_nums] - prefix_sum_zero[i_num + 1]);
        //cout << n_left_plus_numbers << " " << n_right_minus_numbers << " " << prefix_sum_zero[n_nums] - prefix_sum_zero[i_num + 1] << std::endl;
        if (n_min_changes > new_min) {
            n_min_changes = new_min;
        }
    }
    cout << n_min_changes;
    return 0;
}
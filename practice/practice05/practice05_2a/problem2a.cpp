#include <iostream>
#include <vector>
#include <numeric>


using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4};
// Sum of all numbers
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum: " << sum << endl;

// Product of all numbers
    int product = accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>());
    cout << "Product: " << product << endl;

    return 0;
}

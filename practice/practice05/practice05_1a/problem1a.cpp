#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vectorNumbers;
    int howMany,inputNumber;

    cout << "Enter how many numbers you want: " ;
    cin >> howMany;

    cout << "Enter "<< howMany << " integers: ";
    for (int i = 0; i < howMany; ++i) {
        cin >> inputNumber;
        vectorNumbers.push_back(inputNumber);
    }

//print the numbers
    cout << "Numbers in order: ";
    for (auto it = vectorNumbers.begin(); it != vectorNumbers.end(); ++it) {
        cout << *it << ", ";
    }

// sum for even numbers
    int sum = 0;
    for (auto it =vectorNumbers.begin(); it != vectorNumbers.end(); ++it) {
        if (*it % 2 == 0) {
            sum += *it;
        }
    }

    cout << "Sum of even numbers: " << sum << endl;
    return 0;
}

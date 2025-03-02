#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vectorNumbers;
    int howMany,inputNumber;

    cout << "Enter how many numbers you want: " ;
    cin >> howMany;
// need to add a number counter for users
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
    cout << "\nNumbers in reverse order: ";
    for (auto it = vectorNumbers.rbegin(); it != vectorNumbers.rend(); ++it) {
        cout << *it << ", ";
    }
    return 0;
}

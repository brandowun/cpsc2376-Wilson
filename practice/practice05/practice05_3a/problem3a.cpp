#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> numbers;
    string userInput;

    //Stops the user
    cout << "Enter numbers (type '0' then hit enter to stop): ";
    // userInputs
    while (true) {
        cin >> userInput;
        if (userInput == "0") break;
        numbers.push_back(stoi(userInput));
    }


    if (numbers.empty()) {
        cout << "You didn't enter any numbers!" << endl;
        return 0;
    }

    //squaring the items
    cout << "Squared values: ";
    for_each(numbers.begin(), numbers.end(), [](int num)
    {cout << (num * num) << " ";}
    );
    cout << endl;

    int squareSum = accumulate(numbers.begin(), numbers.end(), 0, [](int total, int num)
    {return total + (num * num);}
    );


    cout << "Sum of squared values: " << squareSum << endl;

    return 0;
}

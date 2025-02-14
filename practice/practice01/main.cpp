#include <iostream>
#include <vector>


void printVector(const std::vector<int>& vec);
void doubleTheVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int multiple);

int main() {
    std::vector<int> numbers;
    int playerChoice = 0;
    char choice;
    int number;
    
    do {
        // The choices
        std::cout << " \n" << "\n";
        printVector(numbers); //See the vector the whole time
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum\n";
        std::cout << "5. Print multiples of a number\n";
        std::cout << "6. Stop\n";
        std::cout << "Enter your choice: ";
        std::cin >> playerChoice;

        // case functions
        switch (playerChoice) {
            case 1: {


                std::cout << "What number do you want to add?: ";
                std::cin >> number;
//Added the fact you can continue having choices and you can't enter letters as an option.
//I have never used cin.fail()) before & its to verify a letter isn't added to the first number so chatgpt helped here.
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "That's not a valid number. Please try again.\n";
                }
                else {
                    numbers.push_back(number);
                    std::cout << "Add another number? Enter Y:";
                    std::cin >> choice;

                    //While loop to add as many numbers as you want.
                    while (choice == 'Y' || choice == 'y') {
                        std::cout << "What's the next number?";
                        std::cin >> number;
                        numbers.push_back(number);
                        std::cout << "Add another number? Enter Y:";
                        std::cin >> choice;
                    }
                    break;
                }
            }

            case 2:
                std::cout << "Printed ";printVector(numbers);
                break;

            case 3:
                std::cout << "Vector has been doubled.\n";
                std::cout << "Old "; printVector(numbers);
                doubleTheVector(numbers);
                std::cout << "New "; printVector(numbers);
                break;

            case 4: {
                int sum = calculateSum(numbers);
                std::cout << "Sum of the vector is: " << sum << "\n";
                break;
            }

            case 5: {
                int multiple;
                std::cout << "Enter a number to find its multiples: ";
                std::cin >> multiple;
                printMultiples(numbers, multiple);
                break;
            }
            case 6:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (playerChoice != 6);

    return 0;
}

// Print Vector elements & always visble Vector
void printVector(const std::vector<int>& vec) {
    std::cout << "Vector elements: ";
    for (const int& num : vec) {
        std::cout << num << ", ";
    }
    std::cout << "\n";
}

//double the vector
void doubleTheVector(std::vector<int>& vec) {
    for (int& num : vec) {
        num *= 2;
    }
}

// Sum of the vector
int calculateSum(const std::vector<int>& vec) {
    int sum = 0;
    for (int num:vec) {
        sum += num;
    }
    return sum;

}

// Print Multiples
void printMultiples(const std::vector<int>& vec, int multiple) {
    std::cout << "Multiples of" << multiple << ": ";
    for (const int& num:vec) {
        if (num % multiple == 0) {
            std::cout << num << ", ";
        }
    }
}
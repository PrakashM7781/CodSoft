#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
T getRandomNumber(T min, T max) {
    return min + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX) / (max - min));
}

template <typename T>
void playNumberGuessingGame(T secretNumber) {
    T guess;
    int attempts = 0;

    while (true) {
        std::cout << "Guess a number: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << std::endl;
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int minRange = 1;
    int maxRange = 100;
    int secretNumber = getRandomNumber(minRange, maxRange);

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between " << minRange << " and " << maxRange << ". Try to guess it!" << std::endl;

    playNumberGuessingGame(secretNumber);

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int generateRandomNumber() {
    return rand() % 100 + 1;  // Generate random number between 1 and 100
}

// Process Guess and provide appropriate feedback to the user
bool processGuess(int guess, int target) {
    if (guess < target) {
        cout << "Too low!" << endl;
        return false;
    } else if (guess > target) {
        cout << "Too high!" << endl;
        return false;
    }
    cout << "Congratulations! You guessed correctly!" << endl;
    return true;
}

// Handle Game Functionality like prompting user for guess and keeping track of the guesses
bool playGame(vector<int>& guessHistory, int& totalGuesses) {
    int target = generateRandomNumber();    // represents the number for the user to guess
    string input;
    int guess, guessCount = 0;

    while (true) {
        cout << "Enter your guess (or type 'quit' to exit): ";
        cin >> input;   // User input stored in the variable
        if (input == "quit") return false;  // Exit out of the game if the user enters 'quit'
        
        try { guess = stoi(input); }    // Ensure that the input is valid (int)
        catch (exception&) { cout << "Invalid input! Try again." << endl; continue; }

        guessCount++; totalGuesses++; guessHistory.push_back(guess); // Track the user guesses
        if (processGuess(guess, target)) {
            cout << "You took " << guessCount << " guesses in this game." << endl;
            return true;
        }
    }
}

// Display the report of game history involving user guesses, total guesses and average guesses per round
void displayStats(const vector<int>& guessHistory, int totalGuesses, int gamesPlayed) {
    cout << "Your guesses: ";
    for (int guess : guessHistory) cout << guess << " ";
    cout << "\nTotal guesses so far: " << totalGuesses << endl;
    cout << "Average guesses per game: " << (double)totalGuesses / gamesPlayed << endl;
}

// Main function to handle program functionality
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator to ensure different time for each program run
    vector<int> guessHistory;
    int totalGuesses = 0, gamesPlayed = 0;
    string playAgain;

    do {
        if (!playGame(guessHistory, totalGuesses)) break;
        gamesPlayed++;
        displayStats(guessHistory, totalGuesses, gamesPlayed);
        cout << "Do you want to play again? (yes/no): "; 
        cin >> playAgain; // Next input stored in new variable 
        guessHistory.clear(); // Clear guess history for the current game after displaying report
    } while (playAgain == "yes");

    cout << "Thanks for playing!" << endl;
    return 0;
}

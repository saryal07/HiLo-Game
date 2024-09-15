# Welcome to HiLo game!
- The game will pick a random number between 1 and 100 inclusive and prompt the user for their guess.
- The game will then tell the user if their guess was too high, too low, or correct
  - If the guess was too low, the game will say the guess was too low and prompt the user for another guess
  - If the guess was too high, the game will say the guess was too high and prompt the user for another guess
  - If the guess was correct, the game will say the user guessed correctly and ask the user if they want to play again
- The user is allowed to quit at any time by typing “quit” at the prompt
- If the user quits, the game ends immediately without prompting the user for more guesses or asking if they want to play again
- During each game, the game will keep track of user guesses and report a history of all guesses when the user guesses correctly or when the user decides to quit
- The game also keeps track of the total guesses the user takes and report the total guesses when the user guesses correctly or decides to quit
- If the user has played multiple games, this game will also report the average guesses it took the user to get the correct guess for all the games the user has played so far.

# Running the code
The program was ran using WSL in Windows. Use the following commands in Terminal:
  - "g++ hilo.cpp" to compile the code
  - "./a.out" to start the game

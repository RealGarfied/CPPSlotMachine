#include<iostream>

using namespace std;

int main()
{    
    int bet; // Stores the bet amount
    int wins = 0; // Stores how many wins you have
    int tokens = 100; // Stores the token amount and holds the initial amount of tokens you get
    int pot; // Temp variable which holds how many tokens you won

    int tokenJackpot = 200; // Change this to how many tokens should be the jackpot for spinning [5][5][5]
    int jackpot = 69; // Change this to how much the jackpot multiplier should be for spinning [7][7][7] on the slot machine.

    int allOnes = 4; // Change this to how much the multiplier is if the user spins [1][1][1]
    int allTwos = 8; // Change this to how much the multiplier is if the user spins [2][2][2]
    int allThrees = 12; // Change this to how much the multiplier is if the user spins [3][3][3]

    int chosenOption; // Used in menu to store what the most recent chosen option was selected
    string subtract = "null"; // Used in free play mode to ask the user if they want subtracting enabled/disabled

    do {

        cout << "-------{ WELCOME - MAIN MENU }-------" << endl;
        cout << "" << endl;
        cout << "[1] REGULAR PLAY" << endl;
        cout << "[2] FREE PLAY" << endl;
        cout << "[3] EXIT GAME" << endl;
        cout << "" << endl;
        cout << "Please type an option to continue:" << endl;
        cin >> chosenOption;
        cout << "" << endl;

        if (chosenOption == 1)
        {
            cout << "--------{  TOKENS: " << tokens << "  }--------" << endl; // Shows your balance when you start the game
            do {
                cout << "What would you like to bet?" << endl;
                cin >> bet;

                if (bet != 0) // Checks if the user wants to quit, and if it isn't 0 (which quits the game), it continues to play the game
                {
                    tokens = tokens - bet; // Subtracts bet from balance

                    cout << "--------{   BET: " << bet << "   }--------" << endl; // Shows how much you bet
                    cout << "--------{ JACKPOT: " << jackpot << " }--------" << endl; // Shows the jackpot amount
                    cout << "--------{  TOKENS: " << tokens << " }--------" << endl; // Shows your balance

                    if (wins > 0)
                    {
                        cout << "--------{   WINS: " << wins << "   }--------" << endl; // Shows your wins if you have at least one win
                    }

                    srand (time(NULL));

                    cout << "" << endl;

                    int number1 = rand() % 10 + 1; // Using rand() we get a number from 1-10 for the first number variable. This is the number that displays on the slot machine
                    int number2 = rand() % 10 + 1; // Using rand() we get a number from 1-10 for the second number variable. This is the number that displays on the slot machine
                    int number3 = rand() % 10 + 1; // Using rand() we get a number from 1-10 for the third number variable. This is the number that displays on the slot machine

                    cout << number1 << "   " << number2 << "   " << number3 << endl; // Display the slot machine's values (from the variables above)

                    cout << "" << endl;

                    if (number1 == 1 && number2 == 1 && number3 == 1)
                    {
                        cout << "You won " << allOnes << "x your tokens!" << endl; // Tell user their multiplier
                        pot = bet * allOnes; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }   

                    if (number1 == 2 && number2 == 2 && number3 == 2)
                    {
                        cout << "You won " << allTwos << "x your tokens!" << endl; // Tell user their multiplier
                        pot = bet * allTwos; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }

                    if (number1 == 3 && number2 == 3 && number3 == 3)
                    {
                        cout << "You won " << allThrees << "x your tokens!" << endl; // Tell user their multiplier
                        pot = bet * allThrees; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }

                    if (number1 == 7 && number2 == 7 && number3 == 7)
                    {
                        cout << "You won the JACKPOT! Your multiplier is " << jackpot << "x your bet!" << endl; // Tell user their multiplier
                        pot = bet * jackpot; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }

                    if (number1 == 5 && number2 == 5 && number3 == 5)
                    {
                        cout << "You won the TOKEN JACKPOT! You won " << tokenJackpot << " tokens!" << endl; // Tells user their token winnings
                        tokens = tokens + tokenJackpot; // Add the amount you won to your balance
                    }
                }
                if (bet == 0)
                {
                    return 0;
                }
            } while (tokens >= 1); // Repeat until balance is 0 less than or equal to 0 or the bet is less than or equal to 0
        }

        // END OPTION ONE
        // BEGIN OPTION TWO

        if (chosenOption == 2)
        {
            cout << "--------{  TOKENS: " << tokens << "  }--------" << endl; // Shows your balance when you start the game
            do {

                cout << "" << endl;

                cout << "What would you like to bet?" << endl;
                cin >> bet;

                cout << "" << endl;

                if (subtract == "null")
                {
                    cout << "Would you like to disable subtracting bet from your balance (If you bet 100 tokens, 0 will be taken from your balnace)" << endl;
                    cin >> subtract;
                }

                if (bet != 0) // Checks if the user wants to quit, and if it isn't 0 (which quits the game), it continues to play the game
                {

                    if (subtract == "no" || subtract == "n" || subtract == "No" || subtract == "NO" || subtract == "N" || subtract == "X" || subtract == "false" || subtract == "FALSE")
                    {
                        tokens = tokens - bet; // Subtracts bet from balance
                    }
                    
                    cout << "--------{   BET: " << bet << "   }--------" << endl; // Shows how much you bet
                    cout << "--------{ JACKPOT: " << jackpot << " }--------" << endl; // Shows the jackpot amount
                    cout << "--------{  TOKENS: " << tokens << " }--------" << endl; // Shows your balance
                    cout << "--------{ FREE PLAY }--------" << endl;

                    if (wins > 0)
                    {
                        cout << "--------{   WINS: " << wins << "   }--------" << endl; // Shows your wins if you have at least one win
                    }

                    srand (time(NULL));

                    cout << "" << endl;

                    int number1 = rand() % 10 + 1; // Using rand() we get a number from 1-10 for the first number variable. This is the number that displays on the slot machine
                    int number2 = rand() % 10 + 1; // Using rand() we get a number from 1-10 for the second number variable. This is the number that displays on the slot machine
                    int number3 = rand() % 10 + 1; // Using rand() we get a number from 1-10 for the third number variable. This is the number that displays on the slot machine

                    cout << number1 << "   " << number2 << "   " << number3 << endl; // Display the slot machine's values (from the variables above)

                    cout << "" << endl;

                    if (number1 == 1 && number2 == 1 && number3 == 1)
                    {
                        cout << "You won " << allOnes << "x your tokens!" << endl; // Tell user their multiplier
                        pot = bet * allOnes; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }   

                    if (number1 == 2 && number2 == 2 && number3 == 2)
                    {
                        cout << "You won " << allTwos << "x your tokens!" << endl; // Tell user their multiplier
                        pot = bet * allTwos; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }

                    if (number1 == 3 && number2 == 3 && number3 == 3)
                    {
                        cout << "You won " << allThrees << "x your tokens!" << endl; // Tell user their multiplier
                        pot = bet * allThrees; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }

                    if (number1 == 7 && number2 == 7 && number3 == 7)
                    {
                        cout << "You won the JACKPOT! Your multiplier is " << jackpot << "x your bet!" << endl; // Tell user their multiplier
                        pot = bet * jackpot; // Calculates your winnings
                        tokens = tokens + pot; // Add the amount you won to your balance
                        wins = wins + 1; // Add one win to your current total
                    }

                    if (number1 == 5 && number2 == 5 && number3 == 5)
                    {
                        cout << "You won the TOKEN JACKPOT! You won " << tokenJackpot << " tokens!" << endl; // Tells user their token winnings
                        tokens = tokens + tokenJackpot; // Add the amount you won to your balance
                    }
                }
                if (bet == 0)
                {
                    return 1;
                }
            } while (tokens >= 1); // Repeat until balance is 0 less than or equal to 0 or the bet is less than or equal to 0
        }
    } while (chosenOption != 3);
}
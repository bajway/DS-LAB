/*Assume you are developing a program to simulate a game where players take turns to guess
a number between 1 and 100. The program generates a random number between 1 and 100 at the start
of the game, and the player who guesses the correct number wins the game. If a player guesses
incorrectly, the program tells them whether their guess was too high or too low, and the turn passes
to the next player. Solve it using Direct Recursion?*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void guessNum(int rNum, int player){
    int guess;
    cout << "Player " << player << ", enter Your Guess (1-100): ";
    cin >> guess;
    if(guess>=1 && guess<=100){
    if(guess==rNum){
        cout << "Player " << player << " guessed the number" << endl;
        return;
    }
    else if(guess>rNum){
        cout << "Your Guess is too High" << endl;
        player = (player == 1) ? 2 : 1; //comprehended if statement
        guessNum(rNum, player);
    }
    else{
        cout << "Your Guess is too Low" << endl;
        player = (player == 1) ? 2 : 1; 
        guessNum(rNum, player);
    }
}
}

int main(){
    srand(time(0));
    int num = rand() % 100 + 1;
    guessNum(num, 1);
    return 0;
}

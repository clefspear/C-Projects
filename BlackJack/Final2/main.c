//
//  main.c
//  Final2
//
//  Created by Peter Azmy on 4/26/18.
//  Copyright © 2018 Peter Azmy. All rights reserved.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

struct Deck
{
    enum Suit {Spades, Clubs, Diamonds, Hearts} suit;
    int value;
    char * const name;
}
Cards [52] =
{
    {Spades, 2, "2"}, {Spades, 3, "3"}, {Spades, 4, "4"}, {Spades, 5, "5"}, {Spades, 6, "6"}, {Spades, 7, "7"}, {Spades, 8, "8"}, {Spades, 9, "9"}, {Spades, 10, "10"}, {Spades, 10, "Jack"}, {Spades, 10, "Queen"}, {Spades, 10, "King"}, {Spades, 11, "Ace"},
    
    {Clubs, 2, "2"}, {Clubs, 3, "3"}, {Clubs, 4, "4"}, {Clubs, 5, "5"}, {Clubs, 6, "6"}, {Clubs, 7, "7"}, {Clubs, 8, "8"}, {Clubs, 9, "9"}, {Clubs, 10, "10"}, {Clubs, 10, "Jack"}, {Clubs, 10, "Queen"}, {Clubs, 10, "King"}, {Clubs, 11, "Ace"},
    
     {Diamonds, 2, "2"}, {Diamonds, 3, "3"}, {Diamonds, 4, "4"}, {Diamonds, 5, "5"}, {Diamonds, 6, "6"}, {Diamonds, 7, "7"}, {Diamonds, 8, "8"}, {Diamonds, 9, "9"}, {Diamonds, 10, "10"}, {Diamonds, 10, "Jack"}, {Diamonds, 10, "Queen"}, {Diamonds, 10, "King"}, {Diamonds, 11, "Ace"},
    
    {Hearts, 2, "2"}, {Hearts, 3, "3"}, {Hearts, 4, "4"}, {Hearts, 5, "5"}, {Hearts, 6, "6"}, {Hearts, 7, "7"}, {Hearts, 8, "8"}, {Hearts, 9, "9"}, {Hearts, 10, "10"}, {Hearts, 10, "Jack"}, {Hearts, 10, "Queen"}, {Hearts, 10, "King"}, {Hearts, 11, "Ace"}
    
};
void Profit(float Money, float bet, int Lose)
{
    if (Lose == 1)
{
    Money -= bet;
    
}
    else if (Lose == 0)
    {
        Money *= Money;
        
    }
    
}
void FundsChecker(float Money, float bet)
{
    if (Money == 0.0)
    {
        printf("I am sorry you have run out of money :( \n\n Please Play Again!\n\n");
    }
    if (Money < bet)
    {
        printf("I am sorry you do not have enough funds for a bet that large\n\n");
    }
    else
    {
        Money -= bet;
        printf("You are betting $%.2f, you have $%.2f left in the bank\n\n", bet, Money);
    }
}
void Blackjack(float Money, int r3, int bet, int total)
{
    int r;
    int r2;
    r = rand() % 52;
    r2 = rand() % 52;
struct Deck x = Cards[r];
struct Deck y = Cards[r2];
    total = x.value + y.value;
    printf("Your Cards Right Now are a %s and a %s\n\nYour total is %d\n\n", x.name, y.name, total);
}
void hit(float Money, int bet, int *total)
{
    int r3;
    r3 = rand()%52;
    struct Deck z = Cards[r3];
    printf("\nYour new card is %s\n", z.name);
    total += z.value;
    printf("You beat the house congrats!\n\n");
    
}
int main()
{
    float Money = 100;
    float bet;
    char x;
    int r3 = 0;
    int total = 0;
    char w;
    srand(time(NULL));
    printf("Welcome to BlackJack! \n\nDo you want to play? \n\nType Y for yes or N for no\n\n");
    x = getchar();
    if (x == 'Y')
    {
        printf("\nYou have $%.2f in the bank right now, if you lose your money, Game Over!\n\n", Money);
    }
    else if (x == 'y')
    {
         printf("\nYou have $%.2f in the bank right now, if you lose your money, Game Over!\n\n", Money);
    }
    else
    {
        printf("\nHope You had Fun!\n\n");
        return 0;
    }
    printf("How much would you like to bet against the house?\n\n$ ");
    scanf("%f", &bet);
    FundsChecker(Money, bet);
    Blackjack(Money, r3, bet, total);
    printf("\nHit?\n\nY or N?\n");
    scanf("%s", &w);
    if(w == 'y')
    {
        hit(Money,bet,total);
    }
    
}

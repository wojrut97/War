#include <iostream>
#include <stack>
#include "card.h"
#include "deck.h"
#include <cstdlib>

#define STEP_BY_STEP
using namespace std;

enum result {take, lose, war};

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system ("clear");
#endif
}

void showTable(Deck enemy_deck, Deck my_deck,
               Card enemy_card, Card my_card){
        clear_screen();
        cout << "Number of enemy cards: " << enemy_deck.numberOfCards() << endl;
        cout << enemy_deck;
        cout << enemy_card;
        cout << endl;
        cout << my_card;
        cout << my_deck;
        cout << "Number of Your cards: " << my_deck.numberOfCards() << endl;
        cout << endl;
    }

result compareCards(Card card1, Card card2){
    if ( card1 > card2 ){
        cout << "You take" << endl;
        return take;
    }
    else if ( card1 == card2 ){
        cout << "War!" << endl;
        return war;
    }
    else{
        cout << "You lose" << endl;
        return lose;
    }
}

int main(){
    srand(time(NULL));
    std::deque<Card> side;
    Deck my_deck, enemy_deck;
    Card my_card, enemy_card;
    int counter = 0;

    while( my_deck.cardsLeft() && enemy_deck.cardsLeft() ){
        my_card = my_deck.getTopCard();
        enemy_card = enemy_deck.getTopCard();
        showTable(enemy_deck, my_deck, enemy_card, my_card);
        switch( compareCards(my_card, enemy_card) ){
            case take:
                my_deck.addCard(my_card);
                my_deck.addCard(enemy_card);
                my_deck.addSide(side);
                break;
            case war:
                side.push_back(my_card);
                side.push_back(enemy_card);
                if ( my_deck.cardsLeft() && enemy_deck.cardsLeft() ){
                    side.push_back(enemy_deck.getTopCard());
                    side.push_back(my_deck.getTopCard());
                }
                break;
            case lose:
                enemy_deck.addCard(enemy_card);
                enemy_deck.addCard(my_card);
                enemy_deck.addSide(side);
        }
        #ifdef STEP_BY_STEP
            getchar();
        #endif
        counter++;
    }

    showTable(enemy_deck, my_deck, enemy_card, my_card);
    if ( my_deck.cardsLeft() ){
        cout << "You won the game!" << endl;
    }
    else{
        cout << "You lost the game." << endl;
    }
    cout << "It took " << counter << " rounds." << endl;
    return 0;
}
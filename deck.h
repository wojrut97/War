#include "card.h"
#include <deque>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

#ifndef __DECK_H__
#define __DECK_H__

class Deck{
    public:
        Deck();
        Card getTopCard();
        int cardsLeft();
        void shuffle();
        int numberOfCards();
        void addCard(Card card);
        void addSide(std::deque<Card>& side);
        friend std::ostream& operator<<(std::ostream& os, Deck& deck);
    private:
        std::deque<Card> cards = {};
};

#endif
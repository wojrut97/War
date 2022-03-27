#include "deck.h"

#ifndef __DECK_CPP__
#define __DECK_CPP__

Deck::Deck(){
    for (int suit = Card::hearts ; suit <= Card::spades ; suit++){
        for (int rank = Card::two ; rank <= Card::ace ; rank++){
            Card card((Card::rank_t)rank, (Card::suit_t)suit);
            this->cards.push_back(card);
        }
    }
    this->shuffle();
}

Card Deck::getTopCard(){
    Card top_card = this->cards[0];
    this->cards.pop_front();
    return top_card;
}

int Deck::numberOfCards(){
    return this->cards.size();
}

void Deck::addCard(Card card){
    this->cards.push_back(card);
}

int Deck::cardsLeft(){
    return this->cards.size();
}

void Deck::addSide(std::deque<Card>& side){
    for (Card card: side){
        this->addCard(card);
    }
    side.clear();
}

void Deck::shuffle(){
    std::random_shuffle(this->cards.begin(), this->cards.end());
}

std::ostream& operator<<(std::ostream& os, Deck& deck){
    if (deck.numberOfCards() == 0){
        os << "         " << std::endl;
        os << "         " << std::endl;
        os << "         " << std::endl;
        os << "         " << std::endl;
        os << "         " << std::endl;
        os << "         " << std::endl;
        os << "         " << std::endl;
    }
    else if (deck.numberOfCards() > 0 && deck.numberOfCards() < 5){
        os << "┌───────┐" << std::endl;
        os << "│╲ ╲ ╲ ╲│" << std::endl;
        os << "│╲ ╲ ╲ ╲│" << std::endl;
        os << "│╲ ╲ ╲ ╲│" << std::endl;
        os << "│╲ ╲ ╲ ╲│" << std::endl;
        os << "│╲ ╲ ╲ ╲│" << std::endl;
        os << "└───────┘" << std::endl;
    }
    else{
        os << "╓───────┐" << std::endl;
        os << "║╲ ╲ ╲ ╲│" << std::endl;
        os << "║╲ ╲ ╲ ╲│" << std::endl;
        os << "║╲ ╲ ╲ ╲│" << std::endl;
        os << "║╲ ╲ ╲ ╲│" << std::endl;
        os << "║╲ ╲ ╲ ╲│" << std::endl;
        os << "╚═══════╛" << std::endl;
    }

    return os;
}

#endif
#include "card.h"
#ifndef __CARD_CPP__
#define __CARD_CPP__

Card::Card(rank_t rank, suit_t suit) 
    : rank(rank), suit(suit) {}

Card::Card() 
    : rank(Card::two), suit(Card::hearts) {}

string Card::get_suit(){
    switch(this->suit){
        case hearts:
            return "♥";
        case diamonds:
            return "♠";
        case spades:
            return "♦";
        case clubs:
            return "♣";
        default:
            return "?";
    }
}

string Card::get_rank(){
    switch(this->rank){
        case ace:
            return "A";
        case king:
            return "K";
        case queen:
            return "Q";
        case jack:
            return "J";
        case ten:
            return "\b10";
        default:
            return string(1, (char)(this->rank + 48));
    }
}

std::ostream& operator<<(std::ostream& os, Card& card)
{
    os << "┌───────┐" << std::endl;
    os << "│ "<< card.get_rank() << card.get_suit() << "    │" << std::endl;
    os << "│       │" << std::endl;
    os << "│       │" << std::endl;
    os << "│       │" << std::endl;
    os << "│    " << card.get_rank() << card.get_suit() <<" │" << std::endl;
    os << "└───────┘" << std::endl;
    return os;
}

bool operator>(Card& card1, Card& card2){
    return card1.rank > card2.rank;
}
bool operator==(Card& card1, Card& card2){
    return card1.rank == card2.rank;
}

#endif
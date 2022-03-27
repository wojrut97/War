#include <iostream>
#include <string>

#ifndef __CARD_H__
#define __CARD_H__

using std::string;

class Card{
    public:
        enum rank_t {two = 2, three, four, five, six, seven, height, nine, ten, jack, queen, king, ace};
        enum suit_t {hearts, diamonds, clubs, spades};
        Card(rank_t rank, suit_t suit);
        Card();
        string get_suit();
        string get_rank();
        friend std::ostream& operator<<(std::ostream& os, Card& card);
        friend bool operator>(Card& card1, Card& card2);
        friend bool operator==(Card& card1, Card& card2);

    private:
        int rank;
        suit_t suit; 
};

#endif
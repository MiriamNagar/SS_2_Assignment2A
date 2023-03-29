// I received help for specific things via whatsapp(in the group chat)

#include "doctest.h"
#include <stdexcept>
#include <iostream>
using namespace std;


#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

//3
TEST_CASE("Incorrect values for player constructor") {
    CHECK_NOTHROW(Player p1("Alice"));
}

//3
TEST_CASE("Incorrect values for game constructor") {
    Player p1("Alice");
    Player p2("Bob");
    Player p3("Miriam");
    CHECK_THROWS(Game(p1, p1));
    CHECK_NOTHROW(Game(p1, p2));
    CHECK_THROWS(Game(p1, p3));
}

//4
TEST_CASE("number of cards in bound") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for (int i=0;i<5;i++) {
        game.playTurn();
    }
    CHECK_GE(p1.stacksize(), 0);
    CHECK_GE(p2.stacksize(), 0);
    CHECK_LT(p1.stacksize(), 26);
    CHECK_LT(p2.stacksize(), 26);
}

//2
TEST_CASE("after game 0 cars left for both players") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p1.stacksize() == 0);
}

//4
TEST_CASE("number of cards won max 26") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_GE(p1.cardesTaken(), 0);
    CHECK_GE(p2.cardesTaken(), 0);
    CHECK_LE(p1.cardesTaken(), 26);
    CHECK_LE(p2.cardesTaken(), 26);
}

//2
TEST_CASE("correct size of cards") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    for (int i=0;i<5;i++) {
        game.playTurn();
    }
    CHECK_LE(p1.stacksize(), 21);
    CHECK_GE(p1.stacksize(), 0);
}

//2
TEST_CASE("players initialised with 26 cards at the beggining") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
}

//1
TEST_CASE("addition of cards equal to 52") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    for (int i=0;i<5;i++) {
        game.playTurn();
    }
    CHECK(p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken() == 52);
}

//1
TEST_CASE("both players has same amount of cards left") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    for (int i=0;i<6;i++) {
        game.playTurn();
    }
    int size = p2.stacksize();
    CHECK(p1.stacksize() == size);
}

//1
TEST_CASE("game really finished and there is a winner! or a tie..") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
}

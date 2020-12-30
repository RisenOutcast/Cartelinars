#pragma once

struct beast { //Pelaajan data ja beastin data erikseen, jotta tulevaisuudessa voi olla useampi beast yhdella pelaajalla.
    std::string name;
    int xp;
    int level;
    int health;
    int attack;
    int defence;
};

struct player { //Pelaajan data ja beastin data erikseen, jotta tulevaisuudessa voi olla useampi beast yhdella pelaajalla.
    std::string name;
    int gold;
};

beast newEnemy(); //data.cpp
player newPlayer(std::string userName); //data.cpp

void shop(beast& playerBeast, player& currentPlayer); //data.cpp
void moves(); //data.cpp
void stats(beast& playerBeast, player& currentPlayer); //data.cpp

void move1(beast& beast_attacker, beast& beast_defender); //game.cpp
void move2(beast& beast_attacker, beast& beast_defender); //game.cpp
void move3(beast& beast_attacker, beast& beast_defender); //game.cpp
void move4(beast& beast_attacker, beast& beast_defender); //game.cpp
void add_experience(beast& playerBeast, player& currentPlayer, int xp_amount, int gold_amount); //game.cpp
int battle(beast& playerBeast, beast& enemyBeast, player& currentPlayer); //game.cpp
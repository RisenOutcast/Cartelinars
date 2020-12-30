#include <iostream>
#include <Windows.h>
#include <math.h>
#include "header.h"

void move1(beast& beast_attacker, beast& beast_defender) { //Claw   -Heikompi isku, mutta laskee vihollisen defence pisteita.
    int EnemyDefenceDec = beast_defender.defence * 0.05; //Laske 5% beastin defence arvosta
    beast_defender.defence -= EnemyDefenceDec; //vahenna se beastin defencesta
    int damage = beast_attacker.attack * beast_attacker.attack / (beast_attacker.attack + beast_defender.defence); //Laske vahinko
    beast_defender.health -= damage; //Vahenna se vihollisen elamapisteista
    std::cout << beast_attacker.name << " uses Claw! " << beast_defender.name << " defence fell!\n" << beast_attacker.name << " deals " << damage << " damage! " << beast_defender.name << " has " << beast_defender.health << " hp left!\n\n";
    return;
}

void move2(beast& beast_attacker, beast& beast_defender) { //Headbutt   -Heikompi isku, mutta antaa samalla vahan elamapisteita takaisin
    int healAmount = beast_attacker.health * 0.05; //Laske 5% beastin elamapisteista
    beast_attacker.health += healAmount; //Lisaa laskettu 5% beastin elamapisteisiin
    int damage = beast_attacker.attack * beast_attacker.attack / (beast_attacker.attack + beast_defender.defence); //Laske vahinko
    beast_defender.health -= damage; //Vahenna se vihollisen elamapisteista
    std::cout << beast_attacker.name << " uses Headbutt! " << beast_attacker.name << " deals " << damage << " damage! \n" << beast_defender.name << " has " << beast_defender.health << " hp left!\n\n";
    return;
}

void move3(beast& beast_attacker, beast& beast_defender) { //Strike -Voimakkaampi isku, mutta tekee vahinkoa myos itselle.
    int selfharm = beast_attacker.defence * 0.1; //Laske 10% beastin hyokkausvoimasta 
    beast_attacker.health -= selfharm;  //Vahenna laskettu maara omista elamapisteista
    int damage = beast_attacker.attack * 1.7; //Vahinko on 170% omista attack power pisteista
    beast_defender.health -= damage; //Vahenna se vihollisen elamapisteista
    std::cout << beast_attacker.name << " uses Strike! " << beast_defender.name << " defence fell!\n" << beast_attacker.name << " deals " << damage << " damage! " << beast_defender.name << " has " << beast_defender.health << " hp left!\n\n";
    return;
}

void move4(beast& beast_attacker, beast& beast_defender) { //Crit  -Arpa isku, jos saat "critin" on isku 150% voimakkaampi tai jos et, on se vain 50% suuruinen.

    int damage = beast_attacker.attack * beast_attacker.attack / (beast_attacker.attack + beast_defender.defence);//Laske vahinko
    int numero = std::rand() % 6 + 1; //Satunnainen numero valilta 1 - 6
    numero == 3 ? damage = damage * 2.5 : damage = damage * 0.5; // Jos arvottu numero oli 3 isku on 250% jos ei 50%
    beast_defender.health -= damage; //Vahenna vahinko vihollisen elamapisteista
    numero == 3 ?
        std::cout << beast_attacker.name << " uses Crit! " << beast_attacker.name << " deals " << damage << " damage! " << "\nCRITICAL Strike! " << beast_defender.name << " has " << beast_defender.health << " hp left!\n\n" :
        std::cout << beast_attacker.name << " uses Crit! " << beast_attacker.name << " deals " << damage << " damage! " << "\nIt didn't go as planned. " << beast_defender.name << " has " << beast_defender.health << " hp left!\n\n";
    return;
}

void add_experience(beast& playerBeast, player& currentPlayer, int xp_amount, int gold_amount) {
    playerBeast.xp += xp_amount;
    currentPlayer.gold += gold_amount;
    std::string choice;
    int level_end = (1 + sqrt(1 + 8 * playerBeast.xp / 50)) / 2; //Laske mikä leveli experiencesta tulee.

    if (playerBeast.level < level_end) { //Vertaa laskettua leveliä beastin leveliin
        playerBeast.attack += 10;
        playerBeast.defence += 10;
        playerBeast.health += 20;
        playerBeast.level = level_end;
        std::cout << "Your " << playerBeast.name << " has grown to level " << level_end << "! \n";
        std::cout << "Attack increased to " << playerBeast.attack << "! Defence increased to " << playerBeast.defence << "! Health increased to " << playerBeast.health << "! \n";

        std::cout << "Enter 1 to continue.\n";
        while (choice.size() != 1 || 1) { //Tarkista kayttajan antama data.
            std::cin >> choice;
            if (choice != "1") {
                std::cout << "Invalid answer! Enter 1 to continue!\n";
            }
            else {
                break;
            }
        }
    }

    std::cout << "You got " << gold_amount << " gold!\n";

    std::cout << level_end;
    return;
}

int battle(beast& playerBeast, beast& enemyBeast, player& currentPlayer) {
    int round = 0;

    beast player = playerBeast; //Ota beasteista kopiot, jotta alkuperaiset tiedot eivat muutu.
    beast enemy = enemyBeast;

    int player_currenthealth = playerBeast.health; //Ota talteen pelaajan max elamapisteet, jotta niitä voidaan vahentaa
    int enemy_currenthealth = enemy.health; //Ota talteen vihollisen max elamapisteet, jotta niitä voidaan vahentaa

    int playerInput = 0; //Pelaajan tekema valinta.

    int winner = 0; //Kaytetaan kun matsi on ohi.


    while (1) {
        system("CLS");
        round += 1;
        std::cout << "                                          Round " << round << "\n";
        std::cout << "============================================================================================\n";
        std::cout << "                          " << player.name << " (" << player.health << "/" << playerBeast.health << ")" << " | " << enemyBeast.name << " (" << enemy.health << "/" << enemyBeast.health << ")" << "\n";
        std::cout << "--------------------------------------------------------------------------------------------\n";

        //Pelaajan vuoro
        std::cout << "What will you do?\n          1. Claw          2. Headbutt          3. Strike          4. Crit\n";
        std::cin >> playerInput;

        if (playerInput == 1)         move1(player, enemy);
        else if (playerInput == 2)    move2(player, enemy);
        else if (playerInput == 3)    move3(player, enemy);
        else if (playerInput == 4)    move4(player, enemy);
        else    std::cout << "Invalid answer! " << player.name << " didn't know what to do and did nothing! \n"; //Tarkoituksella beast sekaantuu, jos kayttaja ei osaa antaa oikeaa komentoa.

        if (enemy.health < 1) { //Jos vihollinen kuoli, paata peli
            winner = 1;
            break;
        }

        Sleep(4500); //Annetaan pelaajalle aikaa lukea tapahtumat.
        //Vihollisen vuoro
        int numero = std::rand() % 4 + 1; //Satunnainen numero valilta 1 - 4, joka maarittaa mita iskua vihollinen kayttaa.
        if (numero == 1)         move1(enemy, player);
        else if (numero == 2)    move2(enemy, player);
        else if (numero == 3)    move3(enemy, player);
        else if (numero == 4)    move4(enemy, player);

        Sleep(4500);

        if (player.health < 1) { //Jos pelaaja kuoli, paata peli
            break;
        }
    }

    if (winner == 1) {
        std::cout << "You have won " << currentPlayer.name << "! \n";
        Sleep(3500);
        add_experience(playerBeast, currentPlayer, 50, 10); //Pelaajan palkinto 50xp ja 10g
    }
    else {
        std::cout << "You have lost " << currentPlayer.name << "... \n";
        Sleep(3500);
        add_experience(playerBeast, currentPlayer, 20, 0); //Pelaajan palkinto 20xp ja 0g
    }

    return 0;
}
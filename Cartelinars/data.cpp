#include <iostream>
#include "header.h"

beast newEnemy() {
    struct beast playerBeast;

    int HealthChoices[15] = { 360, 400, 480, 500, 380, 470, 420, 410, 370, 490, 350, 450, 430, 440, 460 }; //Arvoja mista arpoa
    int AttackChoices[8] = { 50, 55, 60, 65, 70, 75, 80, 85 }; //Arvoja mista arpoa
    int DefenceChoices[8] = { 50, 55, 60, 65, 70, 75, 80, 85 }; //Arvoja mista arpoa

    playerBeast.name = "Beast"; //Tamankin voisi periaatteessa arpoa
    playerBeast.xp = 0; //Ei ole merkitysta, joten 0
    playerBeast.level = 0; //Ei ole merkitysta, joten 0
    playerBeast.health = HealthChoices[std::rand() % 14 + 0]; //Satunnainen elamapisteidenmaara ennalta maaritetyista vaihtoehdoista
    playerBeast.attack = AttackChoices[std::rand() % 7 + 0]; //Satunnainen attack pisteiden maara ennalta maaritetyista vaihtoehdoista
    playerBeast.defence = DefenceChoices[std::rand() % 7 + 0]; //Satunnainen defence pisteiden maara ennalta maaritetyista vaihtoehdoista

    return playerBeast;
}

player newPlayer(std::string userName) { //Uuden pelaajan luonti
    struct player currentPlayer;
    currentPlayer.name = userName;
    currentPlayer.gold = 0;

    return currentPlayer;
}

void shop(beast& playerBeast, player& currentPlayer) {
    std::string choice;
    int oldStat = 0;
    int active = 1; //Kun aktiivinen niin voi tehdä useamman oston.


    system("CLS"); //Tyhjaa ruutu
    std::cout << "--------------------------------------------------------------------------------------------\n";
    std::cout << "|                                          SHOP                                            |\n";
    std::cout << "--------------------------------------------------------------------------------------------\n";
    std::cout << "|     1. Attack Potion      |       2. Defence Potion      |        3. Health Potion       |\n";
    std::cout << "|      Slight increase      |        Slight increase       |         Slight increase       |\n";
    std::cout << "|            50g            |              50g             |               50g             |\n";
    std::cout << "--------------------------------------------------------------------------------------------\n\n";
    std::cout << "\n--------------------------------------------------------------------------------------------\n";
    std::cout << "|                                      4. Back to Menu                                     |";
    std::cout << "\n--------------------------------------------------------------------------------------------\n\n";

    while (active == 1) {
        std::cout << "You currently hold " << currentPlayer.gold << " in your wallet.\n";
        std::cin >> choice;
        if (choice == "4") {
            active = 0;
            return;
        }
        if (currentPlayer.gold > 49) {
            if (choice == "1")
            {
                oldStat = playerBeast.attack; //Ota talteen vanha arvo, jotta se voidaan esittaa pelaajalle.
                playerBeast.attack += 50;
                std::cout << playerBeast.name << " attack power has now icreased from " << oldStat << " to " << playerBeast.attack << "\n";
                currentPlayer.gold -= 50;
            }
            if (choice == "2")
            {
                oldStat = playerBeast.defence; //Ota talteen vanha arvo, jotta se voidaan esittaa pelaajalle.
                playerBeast.defence += 50;
                std::cout << playerBeast.name << " defence has now icreased from " << oldStat << " to " << playerBeast.defence << "\n";
                currentPlayer.gold -= 50;
            }
            if (choice == "3")
            {
                oldStat = playerBeast.health; //Ota talteen vanha arvo, jotta se voidaan esittaa pelaajalle.
                playerBeast.health += 50;
                std::cout << playerBeast.name << " health has now icreased from " << oldStat << " to " << playerBeast.health << "\n";
                currentPlayer.gold -= 50;
            }
        }
        else {
            std::cout << currentPlayer.name << ", you do not have enough gold.\n";
        }
    }
}

void moves() { //Tietoa liikkeista.
    int choice;
    int oldStat = 0;
    int active = 1; //Kun aktiivinen niin voi tehdä useamman oston.


    system("CLS"); //Tyhjaa ruutu
    std::cout << "======================================================================================================================\n";
    std::cout << "|                                                     Move List                                                      |\n";
    std::cout << "======================================================================================================================\n";
    std::cout << "|                                                       Claw                                                         |\n";
    std::cout << "|        Beast's claws are like strong swords, striking with them they can even lower enemy´s defence slightly!      |\n";
    std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|                                                     Headbutt                                                       |\n";
    std::cout << "|                       Beast headbutts the enemy so hard that it gets some health points back!                      |\n";
    std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|                                                      Strike                                                        |\n";
    std::cout << "|        Beast goes berserk and deals massive damage, but without realising it, it tooks some recoil damage!         |\n";
    std::cout << "----------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|                                                       Crit                                                         |\n";
    std::cout << "|             Theres a chance this move makes massive amounts of damge or it deals little to nothing!                |\n";
    std::cout << "======================================================================================================================\n";
    std::cout << "|                                                 1. Back to Menu                                                    |\n";
    std::cout << "======================================================================================================================\n\n";
    std::cin >> choice;
    while (1) //Tarkista kayttajan antama data
    {
        if (std::cin.fail())
        {
            std::cout << "Invalid answer, enter 1.\n";
        }
        else
        {
            break;
        }
    }
    if (choice == 1)         return;
}

void stats(beast& playerBeast, player& currentPlayer) { //Hahmon ja pelaajan tilastot.
    int choice;
    int active = 1; //Kun aktiivinen niin statit päivittyvät, kun tulet takaisin toisesta esim. shopista.
    while (active == 1) {
        system("CLS");
        std::cout << "--------------------------------------------------------------------------------------------\n";
        std::cout << "|                                          STATS                                           |\n";
        std::cout << "--------------------------------------------------------------------------------------------\n\n";

        std::cout << "                         Nhhm  N               " << "|    NAME    :   " << playerBeast.name << "\n";
        std::cout << "                      Nyo++ +//ooyN            " << "| EXPERIENCE :   " << playerBeast.xp << "\n";
        std::cout << "                         mys++///:oyN          " << "|    LEVEL   :   " << playerBeast.level << "\n";
        std::cout << "                         ho////:::/:--y        " << "|   HEALTH   :   " << playerBeast.health << "\n";
        std::cout << "                         y//o+/:::+s+/+h       " << "|   ATTACK   :   " << playerBeast.attack << "\n";
        std::cout << "                       / d / :::++:::://shh    " << "|   DEFENCE  :   " << playerBeast.defence << "\n";
        std::cout << "                  /soo + :::::::::::: / d      " << "|\n";
        std::cout << "              so / --:://:::/:::::::-d         " << "|\n";
        std::cout << "            Nho//::++o++//::::/:::--           " << "|\n";
        std::cout << "         Ny+///::/+++o+//::::::-:/:-/          " << "|\n";
        std::cout << "      ms / :: :///::/oo+/:------:----+-h       " << "|\n";
        std::cout << "   Ns//+///:+/:yo:::///:+//:::::+ym            " << "|\n";
        std::cout << "                s:::::.///////N                " << "|\n";
        std::cout << "                  d::::/smmy://+               " << "|\n";
        std::cout << "                  yossm    Nhhhm               " << "|\n";
        std::cout << "\n--------------------------------------------------------------------------------------------\n";

        std::cout << "|      1. Move Information      |         2. Shop         |        3. Back to menu         |";
        std::cout << "\n--------------------------------------------------------------------------------------------\n\n";
        std::cin >> choice;

        while (1) //Tarkista kayttajan antama data
        {
            if (std::cin.fail())
            {
                std::cout << "Invalid answer, enter 1,2 or 3.\n";
            }
            else
            {
                break;
            }
        }
        if (choice == 1)         moves();
        else if (choice == 2)    shop(playerBeast, currentPlayer);
        else if (choice == 3)    return;
    }
}
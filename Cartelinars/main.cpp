#include <iostream>
#include <Windows.h>
#include <math.h>
#include "header.h"

void letter_by_letter(std::string message) { //Esitt‰‰ tekstin ruudulle kirjain kerrallaan. RPG-efekti.
    int x = 0;
    while (message[x] != '\0')
    {
        std::cout << message[x];
        Sleep(75);
        x++;
    };
    return;
}

int menu(player& currentPlayer, beast& playerBeast)
{
    int choice;

    int gameActive = 1; //Kun 1 peli pysyy k‰ynniss‰, kun 0 peli sulkeutuu.

    while (gameActive == 1) {
        system("CLS");

        std::string h = " 88888888   88888888    88888888     888      888888888 88        88  8888888      888888888    888888888    888888888 \n888   888  888   888   888   888 88888888888 888    88 888       888  888888888   888    888   888    888   888    888\n888   88   888   888   888   888    88888888 888    88 888       8888 888   888   888    888   888    888   888    88\n888   888 8888888888     88   8  8888888   888       888 888   888   888    888  88888888888   888\n888      88888888888 888888888       888   88888888    888       8888 888   888 888888888888 8888888888   888888888888\n888   88   888   888 88888888888     888     888    88 888       888  888   888   888    888 888888888888          888\n888   888  888   888   888   888     888     888    88 8888    8 888  888   888   888    888   888    888    88    888\n88888888   888   88    888   888    888888   888888888 888888888 88    88   88    888    88    888    888  8888888888\n                          888    888                          8                                       888    888              \n";
        std::cout << h; //Logo pelille
        std::cout << "\n\n                       Simple game by:  M.J.Metsola //RisenOutcast//";
        std::cout << "\n\n\n                                1. Start\n                                2. Stats\n                                3. Exit\n\n";
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
        if (choice == 1) {
            beast enemyBeast = newEnemy(); //Luo satunnaisesti generoitu vihollinen
            battle(playerBeast, enemyBeast, currentPlayer); //aloita taistelu
        }
        else if (choice == 2)    stats(playerBeast, currentPlayer);
        else if (choice == 3)    gameActive = 0;
    }
    return 0;
}

beast newCompanion(std::string playerName) {
    int HealthChoices[15] = { 360, 400, 480, 500, 380, 470, 420, 410, 370, 490, 350, 450, 430, 440, 460 };
    int AttackChoices[8] = { 50, 55, 60, 65, 70, 75, 80, 85 };
    int DefenceChoices[8] = { 50, 55, 60, 65, 70, 75, 80, 85 };

    std::string beastName = "Cartel";
    std::string choice;
    system("CLS");

    Sleep(40);
    letter_by_letter("...\n");
    Sleep(40);
    letter_by_letter("It's hatching?\n");
    letter_by_letter(playerName + ", look! It's your very own Cartelian! What should we call it?\n");
    std::cin >> beastName;

    letter_by_letter(beastName + " is an excellent name! Now go out and win some battles!\n");
    std::cout << "Enter 1 to continue.\n";
    while (choice.size() != 1 || 1) {
        std::cin >> choice;
        if (choice != "1") {
            std::cout << "Invalid answer! Enter 1 to continue!\n";
        }
        else {
            break;
        }
    }


    struct beast playerBeast;
    playerBeast.name = beastName;
    playerBeast.xp = 0;
    playerBeast.level = 0;
    playerBeast.health = HealthChoices[std::rand() % 14 + 0]; //Satunnainen elamapisteidenmaara ennalta maaritetyista vaihtoehdoista
    playerBeast.attack = AttackChoices[std::rand() % 7 + 0];//Satunnainen attack pisteiden maara ennalta maaritetyista vaihtoehdoista
    playerBeast.defence = DefenceChoices[std::rand() % 7 + 0];//Satunnainen defence pisteiden maara ennalta maaritetyista vaihtoehdoista

    return playerBeast;
}

int main() {
    std::string choice;
    std::string valid_choices("yYnN");

    letter_by_letter("Welcome to the world of Cartepodare!\nDo you want to hear the introduction? [Y]/[N]\n"); //Let's start by getting you a bird.\n
    std::cin >> choice;
    while (choice.size() != 1 || valid_choices.find(choice) == std::string::npos)
    {
        std::cout << "Invalid answer, enter Y or N.\n";
        std::cin >> choice;
    }
    if (choice == "Y") {
        system("CLS");
        letter_by_letter("Cartepodare, also known as Cartelinars, are a small species with immense fighting ability.These little things live to fight and have a strong connection to humans. Using humans to guide them in battle, we use them for entertainment and competition!\nGo get your own Cartelinar and win some prizes!\n");
        std::cout << "Enter 1 to continue.\n";
        while (choice.size() != 1 || 1) {
            std::cin >> choice;
            if (choice != "1") {
                std::cout << "Invalid answer! Enter 1 to continue!\n";
            }
            else {
                break;
            }
        }
    }

    system("CLS");

    letter_by_letter("What is your name?\n\n");
    std::cin >> choice;

    player Player = newPlayer(choice); //Luo pelaajan data

    beast Beast = newCompanion(choice); //Luo beastin data

    menu(Player, Beast);
}

// COMP 2450 — Warden of the Foundations (Midterm 1)
// battle/Battle.cpp — YOU build the body.

#include "Battle.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "../hero/Bag.h"
#include "../hero/BagException.h"
#include "../hero/Item.h"
#include "../bestiary/Search.h"
#include "../hero/Sort.h"


namespace dungeon {

namespace {



constexpr int kPlayerStartHP   = 30;
constexpr int kWardenStartHP   = 50;
constexpr int kPlayerAttackDmg = 6;   // damage per Attack action
constexpr int kWardenAttackDmg = 4;   // warden's retaliation damage

enum class MenuAction {Attack, Useitem, Inspect, Flee};

struct MenuSelection {
    int  number;
    std::string label;
    MenuAction action;

};


void printMenu(const Bag<MenuSelection>& menu, int adventureHP, int bossHP) {
    std::cout <<"\n Your turn --  your HP " << adventureHP << "  Warden HP " << bossHP << "\n";
    for (std::size_t i = 0; i < menu.size(); ++i) {
    std::cout << "  " << menu[i].number << ". " << menu[i].label << "\n";
    }
    std::cout << " > ";
    

}  

MenuAction readMenuChoice(const Bag<MenuSelection>& menu) {
    std::string line;
    if (!std::getline(std::cin, line)) {
        return MenuAction::Flee;
    }
    int n = -1;
    try {n = std::stoi(line); }
    catch (...) {
        throw BagException(
            static_cast<std::size_t>(menu.size() + 1),
            menu.size());
        
    }
    for (std::size_t i = 0; i < menu.size(); i++) {
        if (menu[i].number == n) return menu[i].action;
    }
    throw BagException(static_cast<std::size_t>(n), menu.size());
}


void useItem(Hero& hero, int& adventureHP) {
    if (hero.inventory.empty()) {
        std::cout << " Your backpack has nothing in it.\n";
        return;
    }

    sortInventory(hero, "value desc");
    std::cout << " Choose the item you want by its name:\n";
    printInventory(hero);
    std::cout << " > ";

    std::string name;
    if (!std::getline(std::cin, name) || name.empty()) {
        std::cout << " You didn't do anything from fear overwhelming you.\n";
        return;
    }

    const Item* it = findByName<Item>(hero.inventory, name);
    if (!it) {
        throw BagException(0, hero.inventory.size());
    }

    if (it->name.find("Potion") != std::string::npos) {
        adventureHP = std::min(adventureHP + 12, kPlayerStartHP);
        std::cout << " You drink a red bottle " << it->name << ". HP is now " << adventureHP << ".\n";

    }
    else {
        std::cout << " You ready " << it->name << " - but it is not something you can use right now.\n";
    }
}

BattleOutcome runWardenBattle(Hero& hero) {
    
    
       int adventureHP = kPlayerStartHP;
       int bossHP = kWardenStartHP;
       int selectionNumber;


       Bag<MenuSelection> menu;
       menu.push_back({1, "Attack",    MenuAction::Attack});
       menu.push_back({2, "Useitem", MenuAction::Useitem});
       menu.push_back({3, "Inspect", MenuAction::Inspect});
       menu.push_back({4, "Flee", MenuAction::Flee});

       hero.eventLog.push_front("Battle Warden - engaged");


       while (adventureHP > 0 && bossHP > 0) {

        
        try {
            printMenu(menu, adventureHP, bossHP);
            switch (readMenuChoice(menu)) {
                case MenuAction::Attack: {
                    bossHP -= kPlayerAttackDmg;
                    std::cout << " You swung your sword and gave " << kPlayerAttackDmg << " damage. Warden HP -> " << std::max(bossHP, 0) << ".\n";
                    hero.eventLog.push_front(
                        "you swung for " + std::to_string(kPlayerAttackDmg));
                    if (bossHP > 0) {
                        adventureHP -= kWardenAttackDmg;
                        std::cout << " The Warden strikes back for " << kWardenAttackDmg 
                        << ". Your HP -> " << std::max(adventureHP, 0) << ".\n";
                        hero.eventLog.push_front(
                            "the Warden struck for " + std::to_string(kWardenAttackDmg));
                        
                    }
                    break;
                }
                case MenuAction::Useitem: {
                    useItem(hero, adventureHP);
                    if (bossHP > 0 && adventureHP > 0) {
                        adventureHP -= kWardenAttackDmg;
                        std::cout << " While you fumbled around the Warden strikes. Your HP ->"
                        << std::max(adventureHP, 0) << ".\n";
                        hero.eventLog.push_front(
                            "The Warden attacked for " + std::to_string(kWardenAttackDmg));
                        

                    }
                    break;
                }
                case MenuAction::Inspect: {
                    std::cout << " Warden of the Floor. HP" << bossHP << " / " << kWardenStartHP
                    << ". Warden looks to be wearing heavy armor and you can't seem to spot any weaknesses.  (free action)\n";

                    break;

                }
                case MenuAction::Flee: {
                    hero.eventLog.push_front("battle warden - fled");
                    return BattleOutcome::Fled;
                }
            }
        }
        catch (const BagException& e) {
            std::cout << " " << e.what() << " - try again.\n";


        }

       }

       if (bossHP <= 0) {
        hero.eventLog.push_front("battle warden - outcome: Victory");
        return BattleOutcome::Victory;
       }
       hero.eventLog.push_front("battle warden - outcome: Defeat");
       return BattleOutcome::Defeat;

    }
  } 
} // namespace dungeon

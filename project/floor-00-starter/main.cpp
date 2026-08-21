// COMP 2450 — The Descent
// Floor 0: The Antechamber
//
// You will grow this program every week. Today it does almost nothing.
// Your only job: make it compile, make it run, and change one line.

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "\n=== THE ANTECHAMBER ===\n\n";
    cout << "A torch sputters. The air smells of iron.\n";
    cout << "What is your name, adventurer? ";

    string hero_name;
    getline(cin, hero_name);

    if (hero_name.empty()) {
        hero_name = "Nameless One";
    }

    // TODO Floor 0: replace this string with your own flavor line.
    // Anything a brave (or doomed) adventurer might mutter on descending.
    const string flavor = "You will face many challenges adventurer. Be prepared or you will perish ";

    cout << "\nWelcome, " << hero_name << ".\n";
    cout << flavor << "\n\n";
    cout << "The stair to Floor 1 awaits. Press Enter to rest.\n";

    string _;
    getline(cin, _);

    return 0;
}

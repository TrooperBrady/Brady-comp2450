# Trial III — *The Encounter* — Notes

*Warden of the Foundations · Midterm 1 · 60 %*

This file is the grader's map of your battle code. Help us find each piece. Be specific — file and line numbers are encouraged.

---

## AI declaration for Trial III

(One or two sentences. *Which* tool, *what* you asked it for, *what* you did with the result. "Did not use" is fine — but the line must be there.)

I didn't use AI to write any code in Trial 3.

---

## Two functions I wrote without AI assistance

These are the functions Friday's quiz can ask me to modify on paper. I wrote each of these by hand, with no autocomplete on the body. Pick functions you know cold — three of the four quiz questions pull from these.

1. `<void useItem(Hero& hero, int& adventureHP)>` in `<Battle.cpp>:<68>`
2. `<void printMenu(const Bag<MenuSelection>& menu, int adventureHP, int bossHP)>` in `<Battle.cpp>:<38>`

---

## Floor 0–3 ties — where to find them in my code

Help the grader find each of the four required ties.

**Floor 0 (ADT).** The available menu actions are stored in:

- Container type: `<bag>`
- Declared at: `battle/Battle.cpp:<108>`
- ADT name + one-sentence defence: (paste your comment here, or quote the comment in the code)
The reason I choose bag was cause it holds all the code for the menu to be used throughout the program

**Floor 1 (search).** `findByName<Item>` is called at: 

- `battle/Battle.cpp:<85>` (Use-item branch)

**Floor 2 (sort).** The at-display sort (`std::sort` with a comparator, or your Floor 2 `sortInventory`) is called at:

- `battle/Battle.cpp:<74>` (before displaying the items menu)
- Sort criterion: `<descending>` (e.g., descending value — the healing-power stand-in — or ascending weight)
- One-sentence reason: (why this criterion?) The reason being is that if the player was shown potions in lowest value they will have to scroll or in this case look down the bottom of the list and type the number that will give the highest health back. 

**Floor 3 (templates + exceptions).** `BattleException` (or `BagException` where a bad index is the fault) is:

- Thrown at: `battle/Battle.cpp:<87>` on `<if(!it)>`
- Caught at: `battle/Battle.cpp:<164>` (must be **inside** the battle loop, not in main)

---

## Reflection  *( ≤ 200 words )*

Which Floor's tie was hardest to wire in, and why? Was anything obvious in hindsight that wasn't obvious when you started?

(your reflection)
I was say wiring in floor 3 was the hardest to wire in. I needed to have it at the end of the try function, but also needed to write parameters for what the output should be above main in function. It is not that hard but I would say it is the most time comsuming floor tie in compared to all the other floors in the program. I would say there was not anything that wasn't obvious when writing this floor tie in. Cause it is a straight forward code to implement just time conusming to make sure you use the right parameters for the code and make sure the program will catch any errors.

---

## Tuning notes (optional)

If you changed any of the tunables (`kPlayerStartHP`, `kWardenStartHP`, `kPlayerAttackDmg`, `kWardenAttackDmg`), or added new ones (item healing amounts, etc.), list them and their values here so the grader can play through your battle without surprise.

(your notes, or "defaults")
I changed playerHP and WardenHP to adventureHP and bossHP

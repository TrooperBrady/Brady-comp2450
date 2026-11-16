1.
 selftest registry
  index: size==5, distinct weaknesses==3, count[holy]==3: OK
  knows: Lich present, Drake absent: OK
  recall: Wraith->hp==14, Drake==nullptr: OK
  hasWeakness: holy present, water absent: OK
  countWeakness: holy==3, water==0: OK
  forget: drop a shared weakness (count--), drop a last weakness (erased), absent==false: OK
  all phases OK
> knows Lich
  McCown knows 'Lich'.
> knows Drake
  McCown does not know 'Drake'.
> knows witch
  McCown does not know 'witch'.
> weaknesses
  blunt  (2 monsters)
  fire  (6 monsters)
  holy  (3 monsters)
  light  (2 monsters)
  slashing  (1 monsters)
  water  (1 monsters)
  (6 distinct weaknesses)
> lookup Lich
Lich   HP 35   ATK 6   weakness: holy
  (looked up in the Registry)
> lookup Goblin
Goblin   HP 8   ATK 2   weakness: fire
  (looked up in the Registry)
> lookup Witch
  'Witch' is not in the Hall of Names.
> weakness fire
  6 monsters fear fire.
> names
Bone Spider   HP 6   ATK 2   weakness: fire
Cave Troll   HP 28   ATK 7   weakness: fire
Cinder Bat   HP 4   ATK 1   weakness: water
Frostmaw   HP 22   ATK 6   weakness: fire
Goblin   HP 8   ATK 2   weakness: fire
Ironclaw Bear   HP 24   ATK 5   weakness: slashing
Lich   HP 35   ATK 6   weakness: holy
Marsh Lurker   HP 18   ATK 3   weakness: fire
Necrothrall   HP 16   ATK 4   weakness: light
Ratking   HP 9   ATK 2   weakness: fire
Shadow Hound   HP 12   ATK 4   weakness: light
Skeleton   HP 10   ATK 3   weakness: blunt
Stone Sentinel   HP 30   ATK 5   weakness: blunt
Wisp   HP 3   ATK 1   weakness: holy
Wraith   HP 14   ATK 4   weakness: holy
  (15 names, alphabetical ΓÇö std::map keeps them ordered)
> strike Goblin
  Struck 'Goblin' from the Hall of Names. (14 remain.)
> weakness fire
  5 monsters fear fire.
>  recall Goblin
McCown does not recognize ''. Try `help`.
> recall Goblin
Goblin   HP 8   ATK 2   weakness: fire
  (recalled from the tree)
> benchmark names

-- The Hall of Names: linear scan vs BST vs std::map (1000 iterations per cell) --
  N=    100  query=last    linear=     1.139 us  BST=   0.139 us  std::map=   0.462 us  (tree height 13)
  N=    100  query=absent  linear=     0.718 us  BST=   0.132 us  std::map=   0.410 us  (tree height 13)
  N=   1000  query=last    linear=    10.754 us  BST=   0.325 us  std::map=   0.663 us  (tree height 22)
  N=   1000  query=absent  linear=     6.336 us  BST=   0.297 us  std::map=   0.602 us  (tree height 22)
  N=  10000  query=last    linear=   108.048 us  BST=   0.396 us  std::map=   0.830 us  (tree height 30)
  N=  10000  query=absent  linear=    66.008 us  BST=   0.349 us  std::map=   0.732 us  (tree height 30)
  N= 100000  query=last    linear=  1015.805 us  BST=   0.296 us  std::map=   1.031 us  (tree height 40)
  N= 100000  query=absent  linear=   694.771 us  BST=   0.270 us  std::map=   0.943 us  (tree height 40)

std::map::find tracks the BST ΓÇö both grow with log N, both crush
the linear scan. The difference is the code: the BST was a class you
wrote across a whole floor; std::map was one declaration. And unlike
your plain BST, std::map is balanced (a red-black tree), so it NEVER
degenerates into a stick ΓÇö the library gives you the balanced tree of
Floor 9┬╜ and a key->value index on top of it, for free.

> quit
McCown notes your departure. "You leave in order."

2.

A byName_.count("Wisp") > 0
B byName_.at("Wisp").attack
C weaknesses_.count("light") > 0
D weaknessCounts_.at("holy")

The only time you would want a set instead of a map. Is when you only need to store unique values and check whether they exist

3.
map will keep everything in order even if things are inserted out of order. names will always display the monsters in order alphabetically 

Zombie will be in the same position as bone spider but trying to search for zombie will mess up the map order and can result in problems

4.
What I gained is I can just type find and it will simply look for the mosnter I was looking for instead of it recursive searching
What I would have given up in return is I have no idea how the tree will be structured

5.
Error line
Registry.h(162,12): error C2678: binary '[': no operator found which takes a left-hand operand of type 'const std::map<std::string,int,...>'

A:  The [] opereator inserts a new entry with a default value if the key does not exist.
B: I think it is because the function is a const method. The [] operator might modify the map by inserting a new entry, so it cannot be used on a constant map

6.
It is correct cause recall will be using the older BST. removing golbin from Registry will not automatically remove it from the BST. so the commands are looking at different data structures

7.
The name command will be using alphabetical order to display all the monster names in sorted order. Strike does not need alphabetical order because it only needs to find and remove a monster by its name. Since I only need to see if a name exists, I don't think spending the extra resources to keep it in order. 

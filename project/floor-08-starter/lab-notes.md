1.
=== THE HALL OF LINEAGES ===

What is your name, adventurer? Brady

Welcome, Brady.
Scrivener McCown looks up from a great branching chart that climbs the
wall like roots. "You found the Cisterns in order. Good. Order down
there was a line. Up here it branches." He taps the root of the chart.
"Every creature in the Hold hangs somewhere on this. Ask it questions."

(commands:
   search <name>                 ΓÇö look up by name in bestiary, inventory, OR event log
   list                          ΓÇö list the bestiary
   inventory                     ΓÇö list your inventory
   inspect <n>                   ΓÇö show the nth item in your inventory
   take <name>                   ΓÇö add a small item by that name to your inventory
   sort inventory by <key> [asc|desc]
                                 ΓÇö key is name, weight, or value
   undo                          ΓÇö reverse the most recent mutating command
   lint <text>                   ΓÇö check that brackets/parens/braces in <text> balance
   provoke <name>                ΓÇö enqueue an enemy action onto the line
   simulate                      ΓÇö drain the enemy line in FIFO order
   potato <name>... <k>          ΓÇö classical hot-potato survivor (FIFO elimination)
   taxonomy                      ΓÇö print McCown's classification tree as an outline
   taxonomy --dfs                ΓÇö list every entry depth-first (pre-order)
   taxonomy --bfs                ΓÇö list every entry breadth-first (level-order)
   lineage <name>                ΓÇö show the root-to-creature classification path
   log [n]                       ΓÇö show the last n events, newest first
   log --oldest [n]              ΓÇö show the first n events, oldest first
   clone hero                    ΓÇö deep-copy the hero, print both logs, let the copy die
   selftest chain                ΓÇö Chain<T> leak + deep-copy harness
   selftest iterator             ΓÇö Chain<T>::iterator harness
   selftest stack                ΓÇö Stack<T> push/pop/top/LIFO harness
   selftest queue                ΓÇö Queue<T> enqueue/dequeue/front/FIFO harness
   selftest tree                 ΓÇö Tree<T> addChild/size/height/traversal/lineage harness
   benchmark [N]                 ΓÇö race the search algorithms
   benchmark sort [N] [--sorted] [--bad-pivot]
                                 ΓÇö race the sorting algorithms
   benchmark log [N]             ΓÇö race Chain::push_front vs vector insert(begin)
   battle warden                 ΓÇö face the Warden of the Foundations
   help                          ΓÇö this screen
   quit                          ΓÇö leave the dungeon)

> selftest tree
  empty Tree<int>: empty() && size==0 && height==0: OK
  addChild: root==1 with 3 children: OK
  size()==7 over the sample tree: OK
  height()==2 (longest path 1->2->5): OK
  preOrder == {1,2,5,6,3,4,7} (depth-first): OK
  levelOrder == {1,2,3,4,5,6,7} (breadth-first): OK
  lineage(6)=={1,2,6} and lineage(404) empty: OK
  all phases OK
> taxonomy
Creatures of the Hold
    - Undead
        - Corporeal
            - Skeleton
            - Necrothrall
            - Lich
        - Incorporeal
            - Wraith
            - Wisp
    - Beasts
        - Mammals
            - Shadow Hound
            - Ironclaw Bear
            - Cinder Bat
        - Giants
            - Cave Troll
            - Frostmaw
    - Vermin
        - Bone Spider
        - Ratking
        - Marsh Lurker
    - Constructs
        - Stone Sentinel
    - Humanoids
        - Goblin
  (25 creatures and categories; height 3)
> taxonomy --bfs
  breadth-first (level-order):
    Creatures of the Hold
    Undead
    Beasts
    Vermin
    Constructs
    Humanoids
    Corporeal
    Incorporeal
    Mammals
    Giants
    Bone Spider
    Ratking
    Marsh Lurker
    Stone Sentinel
    Goblin
    Skeleton
    Necrothrall
    Lich
    Wraith
    Wisp
    Shadow Hound
    Ironclaw Bear
    Cinder Bat
    Cave Troll
    Frostmaw
> lineage Shadow Hound
  Creatures of the Hold > Beasts > Mammals > Shadow Hound
> lineage Cave Troll
  Creatures of the Hold > Beasts > Giants > Cave Troll
> lineage Goblin
  Creatures of the Hold > Humanoids > Goblin
> quit
McCown notes your departure on the chart. "You leave classified."






2. 
They all share the same recursion structure, but there are differences between the three. CountFrom counts nodes, HeightFrom measures the tree's height, and PreOrderInto records the nodes in preorder.

3. 
I think what moved the most would be constructs. In dfs, it is at the end of the branches after the program explores undead, beats, and vermin. in bfs the branch it is in is much closer and it is the 5th thing that appears

4. 
For goblins to be added to the program I added a humanoid branch. I just changed taxonomy file nothing else. Lineage command result was
 lineage Goblin
  Creatures of the Hold > Humanoids > Goblin
I would think the difference is that cpp is meant to output the results while taxnomomy holds the information and when new information is needed you can just add it to taxnonomy not cpp file.

5.
taxonomy --dfs
  depth-first (pre-order):
    Skeleton
    Necrothrall
    Lich
    Corporeal
    Wraith
    Wisp
    Incorporeal
    Undead
    Shadow Hound
    Ironclaw Bear
    Cinder Bat
    Mammals
    Cave Troll
    Frostmaw
    Giants
    Beasts
    Bone Spider
    Ratking
    Marsh Lurker
    Vermin
    Stone Sentinel
    Constructs
    Goblin
    Humanoids
    Creatures of the Hold
What changed is that everything seems to be backwards! It is called post order cause instead of it outputting everything in order. Everything is outputed backwards

6. 
lineage Goblin
Nodes visited: 25
  Creatures of the Hold > Humanoids > Goblin
It checked 25 nodes
The reason it does not give a speedup is cause we don't have a rule that tells the search what branches to avoid. So it will check every single node if it has too. A binary search tree adds an ordering rule where the search is able to skip certain branches.

7. 
I would say the big difference is that one brnach can have multiple children instead of just on continious line like before. That made coding a bit different cause I now had to code in a much different way then before. To be able to access the many different branches since it is now not a continous straight line like before. So the code I learned this week helped me understand how to connect all the nodes :D
1.
=== THE CISTERNS ===

What is your name, adventurer? Brady

Welcome, Brady.
Steward Quill sits behind a low ironwood desk in a soaked grey robe.
He does not look up. "Take your number. I will see you in order."
The line behind you stretches further than you can see.

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
   log [n]                       ΓÇö show the last n events, newest first
   log --oldest [n]              ΓÇö show the first n events, oldest first
   clone hero                    ΓÇö deep-copy the hero, print both logs, let the copy die
   selftest chain                ΓÇö Chain<T> leak + deep-copy harness
   selftest iterator             ΓÇö Chain<T>::iterator harness
   selftest stack                ΓÇö Stack<T> push/pop/top/LIFO harness
   selftest queue                ΓÇö Queue<T> enqueue/dequeue/front/FIFO harness
   benchmark [N]                 ΓÇö race the search algorithms
   benchmark sort [N] [--sorted] [--bad-pivot]
                                 ΓÇö race the sorting algorithms
   benchmark log [N]             ΓÇö race Chain::push_front vs vector insert(begin)
   battle warden                 ΓÇö face the Warden of the Foundations
   help                          ΓÇö this screen
   quit                          ΓÇö leave the dungeon)

> selftest queue
  empty Queue<int>: size==0 && empty(): OK
  enqueue(7): size==1 && front()==7: OK
  enqueue 1,2,3: size==3 && front()==1 (FIFO): OK
  after dequeue(): size==2 && front()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK
> potato A B C D E 3
  Survivor: D
> potato Grix Skrit Quill Vael Resh 2
  Survivor: Quill
> potato OnlyOne 7
  Survivor: OnlyOne
> provoke skeleton
  skeleton takes a number and joins the line.
> provoke Imp
  Imp takes a number and joins the line.
> provoke goblin
  goblin takes a number and joins the line.
> simulate
Turn 1: skeleton stirs in the dark.
Turn 2: Imp stirs in the dark.
Turn 3: goblin stirs in the dark.
All enemies have acted; the line is empty.
> simulate
No enemies in the line. Use provoke <name> first.
> quit
Quill stamps your ticket. The line shuffles forward by one.




2.

Add an Item: Stack does push_front(value) and Queue does push_back(value)
Remove and Item: Stack does pop_front and Queue does pop_front()
read the next item output: Stack does head()->data and Queue does head()->data

A stack removes items from the same end while Queue adds items at the back and removes them at the front

A Qeue needs ot add items at the back and remove them a tthe front so Chain<t> is perfect for this. It it used bag<t> it would require shifting the items when removing the front

3.

selftest queue
  empty Queue<int>: size==0 && empty(): OK
  enqueue(7): size==1 && front()==7: OK
  enqueue 1,2,3: size==3 && front()==1 (FIFO): FAIL ΓÇö front() did not return the FIRST enqueued value ΓÇö enqueue/front are on the same end (that's a stack, not a queue)
  after dequeue(): size==2 && front()==2: OK
  drain to empty: size==0 && empty(): OK
  (see FAILs above)

potato A B C D E 3
  Survivor: A

What I built is something that adds and removes items from the same end

selftest queue
  empty Queue<int>: size==0 && empty(): OK
  enqueue(7): size==1 && front()==7: OK
  enqueue 1,2,3: size==3 && front()==1 (FIFO): OK
  after dequeue(): size==2 && front()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK

4. 

start:               A B C D
rotate (A to back):  B C D A
eliminate B: C D A
rotate (C to the back): D A C
eliminate D: A C
rotate (A to the back): C A
eliminate C: A

potato A B C D 2
  Survivor: A

Yep my trace matched! :D

5. 
I would say the second time was much easier cause I already knew how the adaptor uses chain to store and manage items. With this also being my second time I could reuse the basic patterns for many things instead of starting from scratch everytime. 




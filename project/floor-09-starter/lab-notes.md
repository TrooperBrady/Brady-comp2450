1.
selftest bst
  empty BST<int>: empty() && size==0 && height==0: OK
  insert: root==5 and size==7 over the sample: OK
  contains: 7 and 2 present, 6 and 404 absent: OK
  inOrder == {2,3,4,5,7,8,9} (ascending): OK
  degenerate: sorted inserts give height==5, not balanced: OK
  deep copy: mutating the original leaves the copy unchanged: OK
  remove: leaf(2), one-child(3), two-children(5) all correct: OK
  all phases OK
> catalogue
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
  (15 creatures, alphabetical; tree height 6)
> recall Marsh Lurker
Marsh Lurker   HP 18   ATK 3   weakness: fire
  (recalled from the tree)
> recall Skeleton
Skeleton   HP 10   ATK 3   weakness: blunt
  (recalled from the tree)
> Recall Fox
McCown does not recognize 'Recall'. Try `help`.
> recall Fox
  'Fox' is not in McCown's catalogue.
> benchmark bst

-- Bestiary: linear scan vs BST lookup (1000 iterations per cell) --
  N=    100  query=last    linear=     1.099 us  BST=     0.175 us  (tree height 13)
  N=    100  query=absent  linear=     0.649 us  BST=     0.120 us  (tree height 13)
  N=   1000  query=last    linear=    10.341 us  BST=     0.314 us  (tree height 22)
  N=   1000  query=absent  linear=     6.476 us  BST=     0.290 us  (tree height 22)
  N=  10000  query=last    linear=   100.186 us  BST=     0.377 us  (tree height 30)
  N=  10000  query=absent  linear=    65.934 us  BST=     0.334 us  (tree height 30)
  N= 100000  query=last    linear=   968.207 us  BST=     0.305 us  (tree height 40)
  N= 100000  query=absent  linear=   654.809 us  BST=     0.256 us  (tree height 40)

Linear scan grows with N; BST lookup grows with log N ΓÇö the same
win binary search gave you on Floor 1, but now the structure STAYS
searchable as you insert and remove, with no re-sort step.
One catch: this tree was built from SHUFFLED data. Insert the
monsters already sorted and the BST degenerates into a stick
(height ~N), and lookup drops right back to linear ΓÇö the problem
the next floor's self-balancing tree exists to solve.

> quit
McCown notes your departure. "You leave in order."





2.

          8
        /   \
       3     10
      / \      \
     1   6      14
        / \    /
       4   7  13
8 is at the bottom of the tree so the amount of nodes I visted is going to equal the tree's height

3.
1, 3, 4, 6, 7, 8, 10, 13, 14
Since the start of the tree is 8. If we are looking for a number that is smaller than 8 it will be on the left side. If the number is bigger than 8 it will be on the right side

4.
Removed 4
          8
        /   \
       3     10
      / \      \
     1   6      14
          \    /
           7  13
Case is a Leaf

Removed 10
          8
        /   \
       3     14
      / \    /
     1   6  13
          \
           7
Case 1 child and 14 can take 10's place

Removed 8
          13
        /    \
       3      14
      / \
     1   6
          \
           7
Case 2 children and 13 takes it place so numbers of the left is less than 13 and numbers on the right is greater than 13.


5.
benchmark bst

-- Bestiary: linear scan vs BST lookup (1000 iterations per cell) --
  N=    100  query=last    linear=     1.110 us  BST=     0.140 us  (tree height 13)
  N=    100  query=absent  linear=     0.652 us  BST=     0.134 us  (tree height 13)
  N=   1000  query=last    linear=    11.302 us  BST=     0.337 us  (tree height 22)
  N=   1000  query=absent  linear=     6.612 us  BST=     0.337 us  (tree height 22)
  N=  10000  query=last    linear=   109.834 us  BST=     0.396 us  (tree height 30)
  N=  10000  query=absent  linear=    68.047 us  BST=     0.356 us  (tree height 30)
  N= 100000  query=last    linear=  1172.386 us  BST=     0.351 us  (tree height 40)
  N= 100000  query=absent  linear=   950.422 us  BST=     0.364 us  (tree height 40)

Linear scan grows with N; BST lookup grows with log N ΓÇö the same
win binary search gave you on Floor 1, but now the structure STAYS
searchable as you insert and remove, with no re-sort step.
One catch: this tree was built from SHUFFLED data. Insert the
monsters already sorted and the BST degenerates into a stick
(height ~N), and lookup drops right back to linear ΓÇö the problem
the next floor's self-balancing tree exists to solve.

If the monsters were in alphabetical order it would mean to find a monster that started with a Z. It would search through all the monsters From A to Z to reach it. This would slow down recall's speed a lot compared to the methods we were doing before

6.
The BST was a faster way for values since we can decide whether to go left or right isntead of searching through every node. This however does mkae removal hard cause we have to preserve the structure left and right. Writing the destructor was different than all the others cause I have to make sure what I wrote wont mess with nodes connected to it. This floor has taught me really well on how descructors worked and how important they are :D 



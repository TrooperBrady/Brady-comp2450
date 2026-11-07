1.




2.

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
           \
            7


          4
        /   \
       2     6
      / \   / \
     1   3 5   7

What is different is the height. Since the 2nd one is shorter it will take less nodes to visit the bottom numbers compared to the 1st one.

3.
After the rotation I think it will be
    5
   / \
  3   8

Unchanged in order means all values in the tree are visited in ascending order. This means that BST is still valid!

4.

After doing the left 1 rotation. I think the tree will look like this
    3
   /
  1
   \
    2
Sadly it is not balanced yet

A AVL tree would know the tree is not done yet and still needs rotations to make it be a proper tree. It would perform the correct amount of rotations to make it be a balanced tree.

5. 




6.
I think stopping one step short would be the right call. Since implemtning AVL valancing would add a lot of complexity and the base C++ already provies many containers for us to use. If I needed to write my own balacing system it is when the standard containers do not provide what I need, which is when I would need to write my own. If I start using a 5 pointer strucutre I didn't write what I would gain is development time. Since I didn't have to spend time building it, but what I lose is how the pointer structure works internally. Since to understand the behaviors that are outputted a lot better, we would need to udnerstand how the pointer structure works internally.



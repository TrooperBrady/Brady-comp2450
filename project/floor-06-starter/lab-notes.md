2.
The ADT describes what operations a type can perform and what they are supposed to do, not caring how they are implimented. A data structure is organized and will store how the operations will work. Stack is the ADT because it provides operations, while chain is used to just store elements.
The Stack class acts as an adpator over chain. Cause it uses chain internally while stack will be exposed to the user. This reinforces the difference between the two .

3. 
selftest stack
  empty Stack<int>: size==0 && empty(): OK
  push(7): size==1 && top()==7: OK
  push 1,2,3: size==3 && top()==3 (LIFO): OK
  after pop(): size==2 && top()==2: OK
  drain to empty: size==0 && empty(): OK
  all phases OK


  benchmark 1000
  N=   1000  query=last    linear=    10.510 us  binary=   0.237 us  recursive=   0.233 us
  N=   1000  query=absent  linear=     6.327 us  binary=   0.168 us  recursive=   0.175 us

I would say the benchmark mark should not change at all. The reason I think that is cause for chainbench.cpp does not at all 
use the stack class. so no matter what I do to stack it will not effect the benchmakr outputs.

4. 

GitHub\Brady-comp2450\project\floor-06-starter> ./build/the_descent.exe
about to call top() on an empty stack...
top() = 
It then crashed

ADT does not promise that calling top() on an empty stack will return a valid value. That is why callers should always check 
whether the stack is empty before calling top()

5. 

2: recursive=0  stack=0
13: recursive=3  stack=3
55: recursive=6  stack=6
4: recursive=-1  stack=-1
99: recursive=-1  stack=-1

The recursion version hides the search ranges in the function calls, while the stack version makes those range explict by storing them in a Stack. This will help show recursion can be replaced with a loop and a explict stack that will keep track of the work

6. 

I would say this week I spent time understanding the concepts of what we went over. I learned how the stacks act as an ADT. The work felt different from floor 4, where I worked on destructor, copy constructor, and assignment operator. I would say this week felt just right on understanding the concepts you have given us in class :D

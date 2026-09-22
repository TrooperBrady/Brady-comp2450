1. Chain<int> allocations:  1000   deallocations:     0   leaked:  1000   LEAK ΓÇö implement ~Chain() / clear()
All of them leaked

2 main.cpp(78,18): error C2280: 'dungeon::Chain<int>::Chain(const dungeo
n::Chain<int> &)': attempting to reference a deleted function 
It seems to be saying the error is in main not chain

But to answer the questions if both chains could point towards the same node then once it is deleted the program would try to do a double deletion, which would cause problems

3 My benchmark keeps lagging and won't get to the higher numbers after 10000. To answer the question though
Insert will have to move each one which will take a lot longer while push_front only changes the head pointer and is way faster

4 Keeping the bestiary in bag<monster> is a good choice. Since that is going to be where all the monsters are going to be stored. It also shows that the bag is going to only hold mosnters and nothing else. The chain container is great for the event log cause it is more built around pushing new items added to the container. Since the chain container will be used a lot it can easily be push to the front of any new action instead of a list of items like bag<monster>

2.  missing type specifier - int assumed. Note: C++ does not support default-intcpp(C4430)
'initializing': cannot convert from 'initializer list' to 'int'cpp(C2440)
dungeon::Bag<int> <unnamed>::numbers 
It blames line 47 and col 1.
The reason it does not save me is that since it is not in the program it won't run which would cause it not to compile at all.

3. It shows "no such item" while the error message does not get displayed on what went wrong. When I run inpsect 3 what should appear does appear since it is in range and the catch funcion dosen't need to do it's job. I would say no handler is worst then not having one. If I was to make the program access something out of range and it would termiante letting me know right then what lines of code to look at and make me realize I forgot to include a catch command. With the catch being empty this causes the problem to go on much longer without me realizing it.





4. A. The way a player could break the program now is typing in a number that is out of range and the program would not catch it. B. The program is now alloweed to acces memory out of range and this can cause problems for the program. C. The reason just one test saying it worked is not good enough is cause accessing memory outside of the range is undefined behavior that will be different each time. The only way the change would be valid is if what is being access is in range and has safety measures in place to make sure it won't go out of range

5. The catch stops doing it's job and that means when the player types in the command inspect 99 this will make the player see the terminated command. Cause the program died. The complier does not warn the player is cause since catch dosen't work that would catch out of range commands it dosen't make the complier shoot and message to stop the program from terminating. The smallest change is to have it catch BagException instead. When I add a new exception type I would have to add a new catch for it. This would cause the program to run mutliple catch lines and can cause the program to slow down.

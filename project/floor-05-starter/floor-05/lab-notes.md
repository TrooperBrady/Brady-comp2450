2. inventory
   1.  Rusty sword       (wt 4.0, val 5)
   2.  Healing potion    (wt 0.5, val 12)
   3.  Iron key          (wt 0.1, val 0)
   4.  Loaf of bread     (wt 0.1, val 1)
   5.  Cloak of shadows  (wt 1.5, val 80)
> inspect Rusty sword
Usage: inspect <n>
> inspect potion
Usage: inspect <n>
> log
   1.  inventory ΓÇö listed 5 items
  (newest first; chain length 2)

3. Log:
  (the chain is empty ΓÇö nothing to remember yet)

Selftest iterator:
  range-for over Chain<int>: FAIL ΓÇö begin == end (stub returns true) ΓÇö implement operator++ and operator==
  std::find(Chain<int>, 42): FAIL ΓÇö std::find returned end() ΓÇö likely operator++ stub or operator== stub
  std::distance(begin, end): FAIL ΓÇö expected 100 ΓÇö got 0 means begin == end immediately (operator== stub)
  range-for over const Chain<int>&: OK
  std::reverse(Chain<int>) ΓÇö first now == 9: FAIL ΓÇö operator-- not yet wired (Friday) ΓÇö std::reverse can't walk back
  (see FAILs above)

The end() violated the iterator cause it is supposed to represent the end not the beginning of a chain

4. C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085,10): error C2672: 'std::_Sort_unchecked': no mat
ching overloaded function found [C:\Users\musta\OneDrive\Documents\GitHub\Brady-comp2450\project\floor-05-starter\build\the_descent.vcxproj]
  (compiling source file '../main.cpp')
      C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9051,19):
      could be 'void std::_Sort_unchecked(_RanIt,_RanIt,iterator_traits<_Iter>::difference_type,_Pr)'
          C:\Program Files\Microsoft Visual Studio\18\Community\VC\Tools\MSVC\14.51.36231\include\algorithm(9085,10):
          'void std::_Sort_unchecked(_RanIt,_RanIt,iterator_traits<_Iter>::difference_type,_Pr)': expects 4 arguments - 3 provided
The RanIt line is this: std::sort<dungeon::Chain<std::string>::iterator>(const _RanIt,const _RanIt)

The standard library is asking for the iterator to support subtraction between two iterators





5.  First loop
for (const auto& s : hero.eventLog)
    std::cout << s << "\n";

    2nd loop
    for (Chain<std::string>::const_iterator it = hero.eventLog.cbegin();
     it != hero.eventLog.cend();
     ++it)
{
    std::cout << *it << "\n";
}

If I had to choose which loop is easier to maintain then it would be the auto loop. The reason being is that it is much better for containers that change type. Since C++ atuomatically determines the correct iterator type. The spelled out version won't work cause I coded what type the container is and it won't change unless I change it.



6. PrintLog and PrintLogOldest look the same but have differences that acually seperates them. The first one being at the very start of each function. PrintLog starts at the head while PrintLogOldest starts at the tail. Another one being the direction of each function. PrintLog uses next while PrintLogOldest uses prev. Another difference is how the two functions are named. This is why an abstraction will help in this case. Cause it can combine both functions into one and do both jobs at once. 
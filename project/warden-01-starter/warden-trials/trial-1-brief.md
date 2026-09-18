# Trial I — *The Foundations Brief*

*Warden of the Foundations · Midterm 1 · 15 %*

Four short answers, one from each floor above. **50–100 words per answer.** No code on this trial (except the lambdas in Q3); just clear thinking.

AI is welcome to *check* your answers; it is not welcome to *write your sentences*. These answers are short enough that an LLM voice is recognisable.

---

## 1. Floor 0 — ADT

> Your battle's "Use item" menu shows the *currently usable* items in your hero's inventory on this turn. Name the right ADT for that menu. Defend the choice against its closest neighbour (e.g., why `bag` instead of `set`, or `list` instead of `bag`).

(your answer — 50–100 words)
## I Would say bag would be the right one. Since a inventory can have many items that are duplicates so it needs a system where it shows duplicates. This system is also able to remove items so it will only show usable items during my turn. 

---

## 2. Floor 1 — search & Big-O

> Your inventory is kept sorted by healing power (in this codebase an item's `value` measures its potency, so `value` plays the healing-power role). The player types `use Healing potion`. Linear or binary search to find it by name? Justify, and give the Big-O for each.

(your answer — 50–100 words)
## I would go with Linear search. Cause a player's inventory is not going to be that big so finding items will not be too hard. Implimenting Linear code will be much smaller compared to binary search. So it would save on the file size.
---

## 3. Floor 2 — sort & comparators

> Your "Use item" menu must be displayable sorted *either* by healing power (meaning `value`) *or* by weight. Show a one-line comparator (lambda) for each. One sentence on what language feature makes one `std::sort` call serve both orders.

*Note: `Item` has no healing field — an item's `value` measures its potency, so `value` plays the healing-power role here and in your battle.*


```cpp
// by healing power — i.e. by value
auto byValue  = [](const Item& a, const Item& b) {
return a.value > b.value; 
};


// by weight
auto byWeight = [](const Item& a, const Item& b) {
return a.weight < b.weight;
};
```

(one-sentence answer — what language feature?)
Language feature should be lamdbas since that is what it tells how the hte output is going to be ordered a certain way

---

## 4. Floor 3 — templates & exceptions

> Why does `Bag<T>` live in `Bag.h` instead of `Bag.cpp`? And: when the player types `9` for a 4-option menu, where in your code should the validation **throw**, and where should it **catch**?

(your answer — 50–100 words)
# Bag T Lives in Bag.h cause it is a definition of the function where it is called from bag.cpp to be used when the function is needed. Throw function code will be outside of main and the catch function will be right after the try function. 
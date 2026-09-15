# Trial II — *The Critique*

*Warden of the Foundations · Midterm 1 · 15 %*

This trial **requires** you to use an LLM. You will paste the prompt and the reply, then critique what you got. Reading and judging AI output is part of the job now; we are practicing it on purpose.

---

## The prompt

Open Claude (or your LLM of choice) and paste **this exact prompt**:

> *Write a C++ function template that returns the largest element of a `std::vector<T>`. Handle the case where the vector is empty. Briefly explain your design choices.*

Tell us which tool you used and the date:

- **Tool:** (e.g., Claude / ChatGPT / Copilot Chat / …)
## ChatGPT
- **Date of the conversation:** YYYY-MM-DD
## 2026-09-14

---

## The LLM's reply

Paste the **full reply**, code and prose. Use a fenced code block for the code. Do not edit the reply — we want to see what you actually got.

```cpp
/* template <typename T>
T findLargest(const std::vector<T>& values)
{
    if (values.empty())
    {
        throw std::runtime_error("Vector is empty");
    }

    T largest = values[0];

    for (const T& value : values)
    {
        if (value > largest)
        {
            largest = value;
        }
    }

    return largest;
} 
```
*\ 
(paste any prose explanation here, verbatim)

---

## My critique  *( ≥ 150 words )*

Your critique must read like an engineer reviewing a colleague's pull request — specific, technical, and naming exactly what the LLM did. A vague critique ("looks fine to me, but it could be better") is *not* full credit even if the LLM's code was great.

Address each of these:

- **Compile.** Did you actually try to compile and run the code? On what types? What happened?
## Yes I complied the code and ran it and it actually worked. It sorted the vector to find the largest number.
- **Empty case.** What does the empty-vector case actually do in this code? Is the LLM's choice reasonable? Is it different from what *you* would have chosen?
## Once I got main to have a empty vector the function detected this and threw out the empty-vector case. I would say it's choise was reaonable cause it got straight to the point and I would not have done the code any differently. 
- **Requirements on `T`.** What does the code require of `T`? What happens if you instantiate it with a type that doesn't support `<` (e.g., a custom struct)?
## The reason having T in the code is good is that it will not care at all what type of vector it is. The function will figure it would when the function is called. If it is instantiate with a type that dosen't support "<" It will have a compiler error.
- **Const-correctness.** Pass by value or by reference? Return by value or by reference? Would you change either?
## It is passing it by reference and the function is returning the value. I would not change it and keep it the way it is.
- **`std::max_element`?** Did the LLM cheat by using the algorithm header, or did it write the loop? Which would *you* have shipped, and why?
## It did not cheat and actually wrote the loop out. If I had time I would write the entire loop so I can easily make adjustments to the code on certain parts, while if I used a algorithm header I could not do that. However it is a good option if I don't have a lot of time
- **One concrete improvement.** Name one specific change you would make before merging this into a real project. Not "make it better" — a concrete code change.
# One thing I would change is adding another sorting function to find the smallest number in a vector. 

(your critique — at least 150 words)

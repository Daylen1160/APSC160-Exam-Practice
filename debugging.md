# 🕵️‍♂️ Secret Debugging Handbook 🛠

Here's some insider knowledge on debugging that might not've been covered explicitly in lectures, but can be a lifesaver when you're stuck on a problem (The stuff we expected you to learn on your own).

## 💥 1. Segmentation Fault

**The Bug:** I have seen several students encounter this special error.

`Segmentation fault (core dumped)` (exit code 139)

Wow, unlike all the others I have seen, this one doesn't even tell me a line number or anything! How am I supposed to debug this? What does this even mean???

In a nutshell: Your program tried to utilize something (memory) it wasn't allowed to touch. 

Here's an analogy: You (the program) try to open someone else's door at Vanier, Mackenzie House (memory location you can't use). You don't have access, so Campus Security (the operating system) stops you and arrests you for trespassing, kicking you out (the crash).

**The Causes:**

*   **Array Out of Bounds:** Trying to access the an element we don't have in an array. Say, if we wan't the last element, we write `arr[10]` in an array of size 10 (indexes go from 0 to 9!). Recall we start counting from 0, so the last index is `size - 1`.
    ```c
    int arr[10];
    printf("%d", arr[10]); // WRONG
    printf("%d", arr[9]); // CORRECT
    ```

    **The Fix**: Make sure you are accessing an index that exists.

    
*   **NULL:** If a function returns `NULL` (like `fopen` if a file isn't found), and you still try to use it.
    ```c
    FILE *file = fopen("nonexistentfilelmao.txt", "r");

    fscanf(file, "%d", &val); // WRONG

    // CORRECT
    if (file != NULL) {
        fscanf(file, "%d", &val); 
    }
    ```

    **The Fix**: Always check if a pointer is `NULL` before using it.


*   **scanf:** Forgetting the `&` in `scanf("%d", val);` (it should be `&val`).
    ```c
    int val;
    scanf("%d", val); // WRONG
    scanf("%d", &val); // CORRECT
    ```

    **The Fix:** Always check your `scanf` statements. If you forget the `&`, with an exception for strings.

    > NOTE: I believe PrairieLearn catches this for you, so you won't see a segmentation fault. But on other IDE's you will.

## 🔄 2. Infinite While Loops 

**The Bug:** PrairieLearn takes oddly long to run your code. It then displays

`TIMEOUT! Typically this means the program took too long,
requested more inputs than provided, or an infinite loop was found.
If your program is reading data using scanf inside a loop, this
could also mean that scanf does not support the input provided
(e.g., reading an int if the input is a double).`

**The Cause:**
You likely forgot to update the variable that controls the loop condition *inside* the loop.

```c
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    // YOU FORGOT i++; HERE!
}
```

**The Fix:**
Check the condition variable that controls your loop. Make sure it's being updated to eventually end.

## 📏 3. Off-By-One Errors 

**The Bug:**
You looped one too many times, or one too few.

**The Rule of Thumb for Arrays:**
C arrays are **0-indexed**.
*   Size: `N`
*   First element: `0`
*   Last element: `N - 1`

**The Cause:**
*   ❌ `for (int i = 0; i <= size; i++)` (Segmentation fault! Accesses one past the end)
*   ❌ `for (int i = 1; i < size; i++)` (Skips the first element `arr[0]`)

**The Fix:**
*   ✅ `for (int i = 0; i < size; i++)` (Correct for arrays)
*   ✅ `for (int i = 0; i <= size-1; i++)` (Correct, but a bit verbose)

## 4. Casting ➗

**The Bug:**
In C, `integer` truncates decimal values (it always rounds down).

**The bug:**
*   `1 / 7` results in `0`.
*   `9 / 10` results in `0`.
*   `199 / 100` results in `1`.

**The Fix:**
If you want a precise decimal result, **at least one** of the numbers must be a floating-point type (`double` or `float`).

1.  **Add .0:** `1.0 / 7.0` or `1.0 / 7` or `1 / 7.0`
2.  **Explicit Casting:** `(double) count / total` or `count / (double) total` or `(double) count / (double) total`
    *   ⚠️ **Warning:** `(double)(count / total)` is WRONG. That does integer division first (getting 0), *then* casts 0 to 0.0.

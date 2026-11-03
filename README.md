# CIS-165 Lab 9

**Name:** Theo Douma  
**Section:** CIS-165-W099

## Initial Plans

* **min_max.cpp:** I will define a constant `SENTINEL` set to `-99`, an integer `currentNumber`, `smallest`, `largest`, and a boolean flag `hasData` initialized to `false`. I will read the first integer into `currentNumber` before entering a `while (currentNumber != SENTINEL)` loop. On the first iteration inside the loop (`!hasData`), I will initialize both `smallest` and `largest` to `currentNumber` and set `hasData` to `true`; on subsequent iterations, I will compare `currentNumber` against `smallest` and `largest` and update them as needed, then read the next input at the end of the loop. After the loop terminates, I will check `hasData` to either display the labeled `Smallest:` and `Largest:` values or print `"No data values were entered."` if `-99` was entered first.

## Run Instructions

1. Go to onlinegdb.com and select **C++ 17** as the language.
2. Paste the code from `min_max.cpp` into the editor.
3. Click "Run" at the top, enter a series of integers ending with `-99` when prompted, and verify the output.

## Test Table

| Program | Values used | Expected result | Actual output | Match |
| :--- | :--- | :--- | :--- | :--- |
| `min_max.cpp` (positive series) | `8, 3, 12, -99` | Smallest 3; largest 12 | Smallest: 3 \| Largest: 12 | Yes |
| `min_max.cpp` (negative series) | `-8, -3, -12, -99` | Smallest -12; largest -3 | Smallest: -12 \| Largest: -3 | Yes |
| `min_max.cpp` (single value) | `5, -99` | Smallest 5; largest 5 | Smallest: 5 \| Largest: 5 | Yes |
| `min_max.cpp` (zeros) | `0, 0, -99` | Smallest 0; largest 0 | Smallest: 0 \| Largest: 0 | Yes |
| `min_max.cpp` (empty / sentinel first) | `-99` | Clear no-data message | No data values were entered. | Yes |
| `min_max.cpp` (additional series) | `-15, 0, 42, -15, 7, -99` | Smallest -15; largest 42 | Smallest: -15 \| Largest: 42 | Yes |

*Additional Test & Final Check Notes:*
* **Additional series check:** Tested `-15, 0, 42, -15, 7, -99` to verify that the loop properly handles a mix of negative numbers, zero, positive numbers, and duplicate minimum values without letting `-99` overwrite `-15`.
* **Final source check:** No temporary code changes were needed for testing because all test cases were entered via standard input (`std::cin`). The final `min_max.cpp` file was compiled and run again before the final commit.

## Explanations

* **Tracing `8, 3, 12, -99` through the loop:** Before the loop, `currentNumber` reads `8` and `hasData` is `false`. Since `8 != -99`, the loop starts: `!hasData` is true, so `smallest` and `largest` are both initialized to `8` and `hasData` becomes `true`. At the end of the iteration, `currentNumber` reads `3`. On the second iteration, the `else` branch runs: `3 < 8` updates `smallest` to `3` while `largest` stays `8`, and `currentNumber` reads `12`. On the third iteration, `12 > 8` updates `largest` to `12` while `smallest` stays `3`, and `currentNumber` reads `-99`. The loop condition `currentNumber != SENTINEL` now evaluates to `false`, exiting the loop and printing `Smallest: 3` and `Largest: 12`.
* **Keeping `-99` out of the calculations:** The program uses a priming read before the `while` loop and places the subsequent `std::cin >> currentNumber;` at the very bottom of the loop body. As soon as `-99` is read, the loop immediately checks `while (currentNumber != SENTINEL)` and terminates before the `if/else` comparisons can evaluate `-99`.
* **Why initializing both extrema to zero is incorrect:** Although `smallest` and `largest` are declared at `0` initially, they are immediately overwritten on the first valid input when `!hasData` is true. If a program simply compared inputs against `0` without overwriting `smallest` and `largest` from the first real data point, an all-positive series (`8, 3, 12, -99`) would falsely report `0` as the smallest value, and an all-negative series (`-8, -3, -12, -99`) would falsely report `0` as the largest value.
* **Distinguishing an empty series from a series containing zero:** The boolean flag `hasData` starts as `false` and only turns `true` inside the `while (currentNumber != SENTINEL)` loop. If the user enters `-99` first, the loop never executes, `hasData` remains `false`, and the program prints `"No data values were entered."` If the user enters `0` first, `0 != -99` is true, so the loop enters, sets `hasData = true`, and initializes both `smallest` and `largest` to `0`.

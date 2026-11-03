# CIS-165 Lab 9

**Name:** Theo Douma  
**Section:** CIS-165-W099

## Initial Plans

* **min_max.cpp:** I will define a constant `SENTINEL` set to `-99` and read the first integer input before entering the loop. If the first value equals `SENTINEL`, I will display a message stating that no data values were entered. Otherwise, I will initialize both `smallest` and `largest` to that first valid integer and enter a `while` loop that continues reading integers until `SENTINEL` is entered. Inside the loop, I will compare each new integer against `smallest` and `largest`—updating them when a smaller or larger value is found—and then display the labeled minimum and maximum results after the loop ends.

## Run Instructions

1. Go to [onlinegdb.com](https://www.onlinegdb.com/) and select **C++ 17** as the language.
2. Paste the code from `min_max.cpp` into the editor.
3. Click "Run" at the top, enter a series of integers ending with `-99` when prompted, and verify the output.

## Test Table

| Program | Values used | Expected result | Actual output | Match |
| :--- | :--- | :--- | :--- | :--- |
| `min_max.cpp` (positive series) | `8, 3, 12, -99` | Smallest 3; largest 12 | Smallest value: 3 \| Largest value: 12 | Yes |
| `min_max.cpp` (negative series) | `-8, -3, -12, -99` | Smallest -12; largest -3 | Smallest value: -12 \| Largest value: -3 | Yes |
| `min_max.cpp` (single value) | `5, -99` | Smallest 5; largest 5 | Smallest value: 5 \| Largest value: 5 | Yes |
| `min_max.cpp` (zeros) | `0, 0, -99` | Smallest 0; largest 0 | Smallest value: 0 \| Largest value: 0 | Yes |
| `min_max.cpp` (empty / sentinel first) | `-99` | Clear no-data message | No data values were entered. | Yes |
| `min_max.cpp` (additional series) | `-15, 0, 42, -15, 7, -99` | Smallest -15; largest 42 | Smallest value: -15 \| Largest value: 42 | Yes |

*Additional Test & Final Check Notes:*
* **Additional series check:** Tested `-15, 0, 42, -15, 7, -99` to verify that the loop properly handles a mix of negative numbers, zero, positive numbers, and duplicate minimum values without letting `-99` overwrite `-15`.
* **Final source check:** No temporary code changes were needed for testing because all test cases were entered via standard input (`cin`). The final `min_max.cpp` file was compiled and run again before the final commit.

## Explanations

* **Tracing `8, 3, 12, -99` through the loop:** Before the loop starts, the priming read takes in `8`. Since `8 != -99`, both `smallest` and `largest` are initialized to `8`. The loop starts and reads `3`: since `3 < 8`, `smallest` updates to `3` while `largest` stays `8`. The next iteration reads `12`: since `12 > 8`, `largest` updates to `12` while `smallest` stays `3`. The next read takes in `-99`, which terminates the `while (number != SENTINEL)` condition immediately and prints `3` and `12`.
* **Keeping `-99` out of the calculations:** The program uses a priming read before the `while` loop and places the subsequent `cin >> number` at the very end of the loop body. As soon as `-99` is entered, the `while (number != SENTINEL)` condition is checked before the next iteration can run, exiting the loop before the `if` comparisons can evaluate `-99`.
* **Why initializing both extrema to zero is incorrect:** If `smallest` and `largest` are initialized to `0`, an all-positive series like `8, 3, 12, -99` will falsely report `0` as the smallest value, and an all-negative series like `-8, -3, -12, -99` will falsely report `0` as the largest value, even though `0` was never entered.
* **Distinguishing an empty series from a series containing zero:** The program checks the very first input against `SENTINEL` (`-99`) before initializing `smallest` and `largest`. If the first input is `-99`, the `if (number == SENTINEL)` branch prints the no-data message; if the first input is `0`, `0 != -99` evaluates to true, so the program enters the `else` branch and treats `0` as a valid data point.

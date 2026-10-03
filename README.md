# Tool Box - C File Manager

A simple, interactive command-line interface (CLI) tool written in C for manipulating and analyzing text files.

---

## 🛠️ Features

1. **Create and Write**: Create a new file and write text into it.
2. **Read and Display**: Display the contents of a selected file.
3. **Copy File**: Duplicate the contents of a source file into a destination file.
4. **Count Lines**: Count total lines present in a file.
5. **Find Longest Line**: Locate and display the longest line in a file.
6. **Reverse File**: Reverse the text content of a chosen file.
7. **Merge Files**: Combine two files into a third file.
8. **Count Word Occurrences**: Search for a word and display how many times it appears.
9. **Replace Word**: Replace all occurrences of a specific word with another word in a file.
0. **Exit**: Terminate the program.

---

## 📁 Project Structure

* `main.c` — Program entry point containing the main loop and menu UI.
* `library.h` — Header file declaring file operation function prototypes.
* `library.c` — Source file containing implementations for all 9 operations.

---

## 🚀 Compilation & Usage

### Prerequisites
* GCC (GNU Compiler Collection) or any standard C compiler.

### Compilation
Run the following command in your terminal to compile the project:

```bash
gcc main.c library.c -o toolbox

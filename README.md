# Multi-Function Utility Program

This program is a multi-functional tool that addresses four distinct problems: gender-neutral pronoun replacement in text, player score management, recursive fractal pattern generation, and file comparison. The program is designed to be interactive, allowing users to select which feature to use from a simple menu.

## Features
1. Gender-Neutral Pronoun Replacement
   Description:
   This feature replaces gender-specific pronouns in a given sentence or text with gender-neutral alternatives. It ensures that the language used is more inclusive.

How it works:
- The user inputs a sentence or multiple sentences.
- The program scans the text for gender-specific pronouns such as "he," "him," "his," etc.
- These pronouns are replaced with their gender-neutral counterparts like "he or she" or "his or her."

Example:
- Input:  
  `"He went to his car by himself."`
- Output:  
  `"He or she went to his or her car by himself or herself."`

Use case:  
Useful for writers, editors, or educators who want to ensure inclusivity in their language.

---

2. Player Score Management
   Description:  
   This feature allows users to manage player scores for a game or competition. It supports adding player scores, displaying the top 10 highest scores, and searching for a specific player's highest score.

How it works:
- Users can add new player names and scores, which are automatically sorted in descending order.
- The top 10 scores are stored and displayed.
- Users can also search for a player’s highest score.

Options:
1. Add Score: Allows users to add player names and their scores. If more than 10 players are entered, the list is trimmed to retain only the top 10 scores.
2. print Top 10 Scores: Displays the top 10 highest scores in the list.
3. Search Player’s Highest Score: Lets users search for a player’s highest score by name.

Example:
- Input:  
  Add player `"John"` with score `95`.  
  Add player `"Alice"` with score `105`.
- Output:  
  `"1. Alice - 105"`  
  `"2. John - 95"`

Use case:
This feature is ideal for managing leaderboards or tracking player progress in games, quizzes, or competitions.

---

3. Fractal-like Star Pattern Generation
   Description:  
   This feature generates a recursive fractal-like star pattern based on user input. The size of the fractal must be a power of 2, and the pattern is displayed with varying levels of indentation.

How it works:
- The user inputs the size of the fractal (must be a positive power of 2) and the number of initial spaces for indentation.
- The program uses recursion to generate and print a symmetrical star pattern.

Example:
- Input:  
  Size = 4, Initial spaces = 0
- Output:
  ```
  *
  * * * *
        *
  ```

Use case:
This feature is useful for educational purposes to demonstrate recursion and for generating fractal patterns for artistic or mathematical exploration.

---

4. File Comparison
   Description:
   This feature compares two text files and identifies any differences between them. The comparison can be performed either character by character or word by word.

How it works:
- The user provides two file names.
- The program reads both files and compares them either by character or by word.
- If differences are found, it reports the exact line and position where the files differ.

Options:
1. Character-by-Character Comparison: This compares the files character by character and points out the first difference.
2. Word-by-Word Comparison: This compares the files word by word and highlights where the two files deviate.

Example:
- Input:  
  File 1 contains `"Hello World"`.  
  File 2 contains `"Hello World!"`
- Output (Character Comparison):  
  `"Files are different at line 1:"`  
  `"File 1: 'd'`  
  `"File 2: '!'"`

Use case:  
Useful for developers, writers, or anyone needing to compare two versions of a document or code files to detect changes or discrepancies.

---

How to Use
1. Run the Program:  
   Compile and run the program using any C++ compiler.
   ```bash
      g++ your_program.cpp -o your_program
      ./your_program

2. Select a Feature:  
   Upon running the program, you will be presented with a menu:
   ```
   Choose one of the following:
   1) Gender-neutral Replacement in Sentences
   2) Player Score Management
   3) Fractal-like Star Pattern
   4) File Comparison
   5) Exit the program
   ```

    - Enter the corresponding number for the feature you want to use.
    - Follow the prompts to input data and receive output.

---

Example Interaction

Gender-Neutral Pronoun Replacement:
```
Enter your sentence (press Enter on an empty line to finish):
He went to his car.
He met his friend.

Output:
He or she went to his or her car.
He or she met his or her friend.
```

Player Score Management:
```
Choose one of the following:
1) Add a score
2) Print top 10 scores
3) Search a player's highest score
4) Exit
Enter player name: Alice
Enter player score: 95
Top 10 Scores:
1. Alice - 95
```

Fractal-like Star Pattern:
```
Enter the size of the fractal (must be a power of 2):
4
Enter the initial number of spaces:
0

Output:
*
* * * *
    *
```

File Comparison:
```
Enter file 1: file1.txt
Enter file 2: file2.txt
Choose file comparison type:
1) Character by character comparison
2) Word by word comparison
Output: Files are identical.
```

---

# Error Handling
- The program ensures valid input by prompting the user again if incorrect values are provided, such as entering non-power-of-2 values for the fractal size or invalid file names.
- When comparing files, the program handles cases where files have different lengths and reports this to the user.

---

## Dependencies
- **Standard C++ Libraries:** The program uses common libraries such as `<iostream>`, `<vector>`, `<regex>`, `<algorithm>`, `<cmath>`, and `<fstream>`.
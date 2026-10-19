# Escape Room: The 7-Minute Challenge

A beginner-friendly C++ console game created for a DSA project on **Binary Trees**.

## Project overview

The player has seven minutes to solve riddles and move through a virtual escape room. The game stores its puzzles in a Binary Tree and chooses the next room according to the player's answer.

## DSA concept used

Each `Node` stores:
- The room name
- The puzzle question
- The correct answer
- A hint
- A pointer to its left child
- A pointer to its right child

**Game rule:**
- Correct answer → move to the left child.
- Incorrect answer → move to the right child.
- If the selected child does not exist, that path ends.

This makes the Binary Tree part of the game's actual logic, rather than just mentioning it in the project title.

## Features

- Seven-minute time limit
- Seven puzzle nodes arranged as a Binary Tree
- Hints the player can request by typing `HINT`
- Score of 10 points for each correct answer
- Tracks puzzles answered, hints used, rooms visited, and elapsed time
- Final game summary

## Binary Tree diagram

```text
                         Room 1
                       /        \
                  Room 2        Room 3
                 /      \      /      \
             Room 4   Room 5 Room 6   Room 7
```

- Room 1 is the root node.
- Rooms 2 and 3 are its left and right children.
- Rooms 4–7 are leaf nodes.
- A correct answer follows a left pointer; a wrong answer follows a right pointer.

## Requirements

- A C++ compiler that supports C++17 (for example, g++)
- VS Code or any C++ editor (optional)

## How to compile and run

### Windows (Command Prompt or VS Code terminal)

```bash
g++ -std=c++17 escape_room_7_minute.cpp -o escape_room
escape_room.exe
```

### macOS / Linux

```bash
g++ -std=c++17 escape_room_7_minute.cpp -o escape_room
./escape_room
```

## How to play

1. Run the program.
2. Read the riddle shown in the current room.
3. Type your answer in lowercase or uppercase; both are accepted.
4. Type `HINT` if you want to see a hint, then enter your answer.
5. Follow the doors and try to score as many points as possible before time runs out.

## Sample output

```text
========================================
   ESCAPE ROOM: THE 7-MINUTE CHALLENGE
========================================
Solve the riddles and find your way out!
Correct answer: move to the LEFT child.
Wrong answer: move to the RIGHT child.
Type HINT if you need help.
You have 7 minutes. Good luck!

----------------------------------------
Room 1
Time left: 7:00
Puzzle: I have hands but cannot clap. What am I?
Your answer (or type HINT): clock
Correct! You move through the left door.

----------------------------------------
Room 2
Time left: 6:58
Puzzle: What has keys but cannot open locks?
Your answer (or type HINT): piano
Correct! You move through the left door.

----------------------------------------
Room 4
Time left: 6:55
Puzzle: I have a face and two hands, but no arms or legs. What am I?
Your answer (or type HINT): clock
Correct! You move through the left door.
There are no more rooms on this path.

========================================
             GAME SUMMARY
========================================
Puzzles answered: 3
Final score: 30 points
Hints used: 0
Rooms visited: Room 1 -> Room 2 -> Room 4
Time used: 0 minute(s) and 5 second(s)
Result: Great job! You escaped with a strong score!

Thank you for playing!
```

*Note: The times in this sample are illustrative and will vary when you run the program.*

## Important implementation note

The seven-minute limit is checked before displaying each puzzle and after the player submits an answer. Because this is a simple console program using `getline`, it cannot interrupt a player who is still typing exactly when the timer expires. The time is checked immediately after the answer is entered.

## Possible viva questions

**1. What is a Binary Tree?**  
A Binary Tree is a hierarchical data structure in which each node can have at most two children, called the left child and right child.

**2. What is the root node in this project?**  
Room 1 is the root node because it is the first node in the tree.

**3. How does the game use the tree?**  
The player's answer determines whether the program follows the left or right child pointer to the next room.

**4. What is a leaf node?**  
A leaf node has no children. Rooms 4, 5, 6, and 7 are leaf nodes in this project.

**5. Why did you use a Binary Tree?**  
A Binary Tree represents the two possible outcomes of each puzzle answer and organizes the room paths in a clear hierarchical structure.

**6. Which other programming concepts are used?**  
C++ structures, pointers, functions, strings, conditionals, loops, and the `chrono` library for elapsed-time measurement.

**7. Does the timer stop input automatically?**  
No. The program checks the elapsed time after input is submitted. A simple console `getline` cannot interrupt typing automatically.

## Project files

- `escape_room_7_minute.cpp` — complete C++ source code
- `README.md` — project description, setup instructions, tree diagram, sample output, and viva questions
- `sample_output.txt` — example of a successful game path

## Author

Add your name, class, roll number, and college details here before submission.

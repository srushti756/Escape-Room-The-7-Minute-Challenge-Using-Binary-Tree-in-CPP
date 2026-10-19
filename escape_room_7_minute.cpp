#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <cctype>
using namespace std;
using namespace chrono;

// Escape Room: The 7-Minute Challenge
// DSA concept: Binary Tree
// Correct answer -> left child; wrong answer -> right child.

struct Node {
    string roomName;
    string question;
    string answer;
    string hint;
    Node* left;
    Node* right;

    Node(string name, string q, string a, string h) {
        roomName = name;
        question = q;
        answer = a;
        hint = h;
        left = nullptr;
        right = nullptr;
    }
};

string toLowerCase(string text) {
    for (char &ch : text) {
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    }
    return text;
}

void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Create the puzzle nodes.
    Node* start = new Node(
        "Room 1",
        "I have hands but cannot clap. What am I?",
        "clock",
        "You use me to tell the time."
    );

    Node* room2 = new Node(
        "Room 2",
        "What has keys but cannot open locks?",
        "piano",
        "It is a musical instrument."
    );

    Node* room3 = new Node(
        "Room 3",
        "What gets wetter the more it dries?",
        "towel",
        "You use it after a bath."
    );

    Node* room4 = new Node(
        "Room 4",
        "I have a face and two hands, but no arms or legs. What am I?",
        "clock",
        "Look at the wall or your wrist to check the time."
    );

    Node* room5 = new Node(
        "Room 5",
        "What has one eye but cannot see?",
        "needle",
        "It is used for sewing."
    );

    Node* room6 = new Node(
        "Room 6",
        "What has many teeth but cannot bite?",
        "comb",
        "You may use it to arrange your hair."
    );

    Node* room7 = new Node(
        "Room 7",
        "What has a neck but no head?",
        "bottle",
        "You may fill it with water."
    );

    // Link the nodes to form a genuine Binary Tree.
    start->left = room2;       // Correct answer at Room 1
    start->right = room3;      // Wrong answer at Room 1
    room2->left = room4;       // Correct answer at Room 2
    room2->right = room5;      // Wrong answer at Room 2
    room3->left = room6;       // Correct answer at Room 3
    room3->right = room7;      // Wrong answer at Room 3

    const int timeLimitSeconds = 7 * 60;
    int score = 0;
    int puzzlesAnswered = 0;
    int hintsUsed = 0;
    string visitedRooms;

    auto startTime = steady_clock::now();
    Node* current = start;

    cout << "========================================\n";
    cout << "   ESCAPE ROOM: THE 7-MINUTE CHALLENGE\n";
    cout << "========================================\n";
    cout << "Solve the riddles and find your way out!\n";
    cout << "Correct answer: move to the LEFT child.\n";
    cout << "Wrong answer: move to the RIGHT child.\n";
    cout << "Type HINT if you need help.\n";
    cout << "You have 7 minutes. Good luck!\n\n";

    while (current != nullptr) {
        auto now = steady_clock::now();
        int elapsed = static_cast<int>(duration_cast<chrono::seconds>(now - startTime).count());
        int remaining = timeLimitSeconds - elapsed;

        if (remaining <= 0) {
            cout << "\nTime is up! The room is still locked.\n";
            break;
        }

        int minutes = remaining / 60;
        int seconds = remaining % 60;

        cout << "\n----------------------------------------\n";
        cout << current->roomName << "\n";
        cout << "Time left: " << minutes << ":" << setw(2) << setfill('0')
             << seconds << setfill(' ') << "\n";
        cout << "Puzzle: " << current->question << "\n";
        cout << "Your answer (or type HINT): ";

        string userAnswer;
        getline(cin, userAnswer);
        userAnswer = toLowerCase(userAnswer);

        // Check the time again after the user enters an answer.
        now = steady_clock::now();
        elapsed = static_cast<int>(duration_cast<chrono::seconds>(now - startTime).count());
        if (elapsed >= timeLimitSeconds) {
            cout << "\nTime is up! Your answer was not counted.\n";
            break;
        }

        if (userAnswer == "hint") {
            cout << "Hint: " << current->hint << "\n";
            hintsUsed++;
            cout << "Enter your answer: ";
            getline(cin, userAnswer);
            userAnswer = toLowerCase(userAnswer);

            now = steady_clock::now();
            elapsed = static_cast<int>(duration_cast<chrono::seconds>(now - startTime).count());
            if (elapsed >= timeLimitSeconds) {
                cout << "\nTime is up! Your answer was not counted.\n";
                break;
            }
        }

        puzzlesAnswered++;
        if (visitedRooms.empty()) {
            visitedRooms = current->roomName;
        } else {
            visitedRooms += " -> " + current->roomName;
        }

        if (userAnswer == current->answer) {
            cout << "Correct! You move through the left door.\n";
            score += 10;

            if (current->left != nullptr) {
                current = current->left;
            } else {
                cout << "There are no more rooms on this path.\n";
                current = nullptr;
            }
        } else {
            cout << "Not quite! The right door opens, leading to another room.\n";
            if (current->right != nullptr) {
                current = current->right;
            } else {
                cout << "This path ends here. Your escape attempt is over.\n";
                current = nullptr;
            }
        }
    }

    auto endTime = steady_clock::now();
    int totalSeconds = static_cast<int>(duration_cast<chrono::seconds>(endTime - startTime).count());
    if (totalSeconds > timeLimitSeconds) {
        totalSeconds = timeLimitSeconds;
    }

    cout << "\n========================================\n";
    cout << "             GAME SUMMARY\n";
    cout << "========================================\n";
    cout << "Puzzles answered: " << puzzlesAnswered << "\n";
    cout << "Final score: " << score << " points\n";
    cout << "Hints used: " << hintsUsed << "\n";
    cout << "Rooms visited: " << (visitedRooms.empty() ? "None" : visitedRooms) << "\n";
    cout << "Time used: " << totalSeconds / 60 << " minute(s) and "
         << totalSeconds % 60 << " second(s)\n";

    if (totalSeconds < timeLimitSeconds && score >= 20) {
        cout << "Result: Great job! You escaped with a strong score!\n";
    } else if (totalSeconds < timeLimitSeconds && score > 0) {
        cout << "Result: You made progress. Try again to improve your score!\n";
    } else {
        cout << "Result: Challenge complete. Try again and solve more puzzles!\n";
    }

    deleteTree(start);
    cout << "\nThank you for playing!\n";
    return 0;
}

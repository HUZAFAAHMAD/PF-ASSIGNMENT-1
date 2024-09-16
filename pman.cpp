#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int x = 10, y = 10; // Pac-Man's initial position
    char board[20][20]; // Game board
    int score = 0;

    // Initialize game board
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            board[i][j] = ' ';
        }
    }

    // Draw game board
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == 0 || i == 19 || j == 0 || j == 19) {
                board[i][j] = '#';
            }
        }
    }

    // Game loop
    while (true) {
        // Clear screen
        system("cls");

        // Draw game board
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }

        // Get user input
        char input = _getch();

        // Move Pac-Man
        if (input == 'w' && x > 0) {
            x--;
        } else if (input == 's' && x < 19) {
            x++;
        } else if (input == 'a' && y > 0) {
            y--;
        } else if (input == 'd' && y < 19) {
            y++;
        }

        // Check for collisions
        if (board[x][y] == '#') {
            cout << "Game Over!" << endl;
            break;
        }

        // Update score
        score++;
        cout << "Score: " << score << endl;

        // Delay
        _sleep(100);
    }

    return 0;
}

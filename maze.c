#include <stdio.h>
#include <stdlib.h>

char** maze;
int rows = 0;
int cols = 0;

int playerRow;
int playerCol;

int endRow;
int endCol;

// Read the maze file and initialize the maze
void read_file(char* mazeFileName) {
    FILE* file = fopen(mazeFileName, "r");

    char ch;
    int temp = 0;
    while (!feof(file)) {
        ch = fgetc(file);
        if (ch == '\n') {
            rows++;
            if (cols == 0) {
                cols = temp;
            }
            temp = 0;
        } else {
            temp++;
        }
    }
    fclose(file);

    maze = (char**)malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        maze[i] = (char*)malloc(sizeof(char) * cols);
    }

    file = fopen(mazeFileName, "r");
    int i = 0, j = 0;
    while (!feof(file)) {
        ch = fgetc(file);
        if (feof(file)) {
            break;
        }
        if (ch == '\n') {
            i++;
            j = 0;
        } else {
            maze[i][j] = ch;
            if (ch == 'S') {
                playerRow = i;
                playerCol = j;
            }
            if (ch == 'E') {
                endRow = i;
                endCol = j;
            }
            j++;
        }
    }
    fclose(file);
}

// Print the current state of the maze
void print_maze() {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (playerRow == i && playerCol == j) {
                printf("X"); // Mark player's position with 'X'
            } else {
                printf("%c", maze[i][j]); // Print the maze character
            }
        }
        printf("\n");
    }
}

// Start the game
void start_game() {
    char ch;
    while (1) {
        scanf(" %c", &ch); // Note the space before %c to skip whitespace
        if ((ch == 'W' || ch == 'w') && maze[playerRow - 1][playerCol] != '#') {
            playerRow--; // Move up
        } else if ((ch == 'S' || ch == 's') && maze[playerRow + 1][playerCol] != '#') {
            playerRow++; // Move down
        } else if ((ch == 'A' || ch == 'a') && maze[playerRow][playerCol - 1] != '#') {
            playerCol--; // Move left
        } else if ((ch == 'D' || ch == 'd') && maze[playerRow][playerCol + 1] != '#') {
            playerCol++; // Move right
        } else if (ch == 'Q' || ch == 'q') {
            break; // Quit game
        } else if (ch == 'M' || ch == 'm') {
            print_maze(); // Print maze
        }

        // Check if the player has reached the end
        if (playerRow == endRow && playerCol == endCol) {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    char* mazeFileName = argv[1];
    read_file(mazeFileName);
    start_game(); // Start the game
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '

// Maze structure
typedef struct {
    int rows;
    int cols;
    char** data;
} Maze;

// Create a maze with given dimensions, initialized with walls
Maze* create_maze(int rows, int cols) {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->data = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        maze->data[i] = (char*)malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            maze->data[i][j] = WALL; // Initialize all cells as walls
        }
    }
    return maze;
}

// Initialize the maze with a random starting position
void init_maze(Maze* maze) {
    int start_row = rand() % (maze->rows / 2) * 2 + 1;
    int start_col = rand() % (maze->cols / 2) * 2 + 1;
    maze->data[start_row][start_col] = PATH;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc != 3) {
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    Maze* maze = create_maze(rows, cols);
    init_maze(maze);

    // Print the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", maze->data[i][j]);
        }
        printf("\n");
    }

    return 0;
}

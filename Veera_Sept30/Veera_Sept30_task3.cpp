#include <iostream>
#include <iomanip>

const int SIZE = 12;

// Directions: 0 = right, 1 = down, 2 = left, 3 = up
int rowMove[] = {0, 1, 0, -1};
int colMove[] = {1, 0, -1, 0};

void printMaze(char maze[SIZE][SIZE]) {
    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE;j++) {
            std::cout<<maze[i][j] << ' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

// Check if position is valid
bool isValid(char maze[SIZE][SIZE], int r, int c) {
    return (r>=0 && r<SIZE && c>=0 && c<SIZE && maze[r][c] == '.');
}

//traversal
bool mazeTraverse(char maze[SIZE][SIZE], int r, int c, int dir, int startRow, int startCol) {
    maze[r][c] = 'X'; 
    printMaze(maze);

    // If exit found
    if ((r==0 || r==SIZE - 1 || c==0 || c==SIZE - 1) && !(r==startRow && c==startCol)){
        return true;
    }

    // Try all directions
    for (int i=0;i<4;i++) {
        int newDir = (dir + i + 3) % 4; 
        int nr = r + rowMove[newDir];
        int nc = c + colMove[newDir];

        if (isValid(maze, nr, nc)) {
            if (mazeTraverse(maze, nr, nc, newDir, startRow, startCol))
                return true;
        }
    }

    return false; 
}


int main() {
    char maze[SIZE][SIZE] = {
        { '#','#','#','#','#','#','#','#','#','#','#','#' },
        { '#','.','.','.','#','.','.','.','.','.','.','#' },
        { '.','.','#','.','#','.','#','#','#','#','.','#' },
        { '#','#','#','.','#','.','.','.','.','#','.','#' },
        { '#','.','.','.','.','#','#','#','.','#','.','.' },
        { '#','#','#','#','.','#','.','#','.','#','.','#' },
        { '#','.','.','#','.','#','.','#','.','#','.','#' },
        { '#','#','.','#','.','#','.','#','.','#','.','#' },
        { '#','.','.','.','.','.','.','.','.','#','.','#' },
        { '#','#','#','#','#','#','.','#','#','#','.','#' },
        { '#','.','.','.','.','.','.','#','.','.','.','#' },
        { '#','#','#','#','#','#','#','#','#','#','#','#' }
    };

    int startRow = 2, startCol = 0; 
    mazeTraverse(maze, startRow, startCol, 0, startRow, startCol);
    return 0;
}

def solve(board):
    # Find empty cell
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                # Try each number 1-9
                for n in range(1,10):
                    # Check if number is valid in cell
                    if valid(board, i, j, n):
                        # Set number and recurse
                        board[i][j] = n
                        if solve(board):
                            return True
                        else:
                            # Reset on backtrack
                            board[i][j] = 0
                return False
    return True

def valid(board, row, col, num):
    # Check row
    for i in range(9):
        if board[row][i] == num:
            return False
    # Check column
    for i in range(9):
        if board[i][col] == num:
            return False
    # Check 3x3 box
    box_x = col // 3
    box_y = row // 3
    for i in range(3):
        for j in range(3):
            if board[box_y*3 + i][box_x*3 + j] == num:
                return False
    return True

board = [
    [7,8,0,4,0,0,1,2,0],
    [6,0,0,0,7,5,0,0,9],
    [0,0,0,6,0,1,0,7,8],
    [0,0,7,0,4,0,2,6,0],
    [0,0,1,0,5,0,9,3,0],
    [9,0,4,0,6,0,0,0,5],
    [0,7,0,3,0,0,0,1,2],
    [1,2,0,0,0,7,4,0,0],
    [0,4,9,2,0,6,0,0,7]
]

solve(board)

for row in board:
    print(row)

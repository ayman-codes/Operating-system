import random

# Define the board size
BOARD_SIZE = 3

# Create the board
board = []
for i in range(BOARD_SIZE):
    row = []
    for j in range(BOARD_SIZE):
        row.append(0)
    board.append(row)

# Define the winning combination
WINNING_COMBINATION = [1, 2, 3, 4, 5, 6, 7, 8, 0]

# Define the valid moves
MOVES = {
    "left": (0, -1),
    "right": (0, 1),
    "up": (-1, 0),
    "down": (1, 0)
}

# Initialize the board with random numbers
numbers = list(range(1, BOARD_SIZE ** 2))
random.shuffle(numbers)
for i in range(BOARD_SIZE):
    for j in range(BOARD_SIZE):
        board[i][j] = numbers.pop()

# Main game loop
while True:

    # Print the board
    for i in range(BOARD_SIZE):
        for j in range(BOARD_SIZE):
            print(board[i][j], end=" ")
        print()

    # Check if the player has won
    if board == [[1, 2, 3], [4, 5, 6], [7, 8, 0]]:
        print("Congratulations! You won!")
        break

    # Get the player's move
    move = input("Enter a move (left, right, up, down): ")

    # Move the blank space
    blank_row, blank_col = None, None
    for i in range(BOARD_SIZE):
        for j in range(BOARD_SIZE):
            if board[i][j] == 0:
                blank_row, blank_col = i, j
    delta_row, delta_col = MOVES[move]
    new_row, new_col = blank_row + delta_row, blank_col + delta_col
    if new_row < 0 or new_row >= BOARD_SIZE or new_col < 0 or new_col >= BOARD_SIZE:
        print("Invalid move")
    else:
        board[blank_row][blank_col], board[new_row][new_col] = board[new_row][new_col], board[blank_row][blank_col]

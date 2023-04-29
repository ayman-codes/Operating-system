import random

def print_board(board):
    print("Current board:")
    for i, stones in enumerate(board):
        print(f"Pile {i+1}: {'*' * stones}")

def get_player_move(player, board):
    while True:
        pile = int(input(f"Player {player}, choose a pile (1-5): "))
        if pile < 1 or pile > 5 or not board[pile-1]:
            print("Invalid choice. Try again.")
            continue
        stones = int(input(f"Player {player}, choose stones to remove from pile {pile}: "))
        if stones < 1 or stones > board[pile-1]:
            print("Invalid choice. Try again.")
            continue
        return pile, stones

def get_computer_move(board):
    pile = -1
    stones = -1
    for p in range(5):
        for s in range(board[p], 0, -1):
            temp_board = board.copy()
            temp_board[p] -= s
            if nim_sum(temp_board) == 0:
                pile = p + 1
                stones = s
                break
        if pile >= 0:
            break
    if pile == -1:
        for p in range(5):
            if board[p]:
                pile = p + 1
                stones = random.randint(1, board[p])
                break
    return pile, stones

def nim_sum(board):
    return board[0] ^ board[1] ^ board[2] ^ board[3] ^ board[4]


def play_game():
    print("Welcome to NIM!")
    mode = input("Select mode (a) multiplayer mode or b) computer mode): ")
    if mode == "a":
        player1 = 1
        player2 = 2
    elif mode == "b":
        player1 = 1
        player2 = "Computer"
    else:
        print("Invalid mode selection. Exiting...")
        return
    
    board = [5, 7, 9, 11, 13]
    current_player = player1
    while True:
        print_board(board)
        pile, stones = get_player_move(current_player, board) if current_player != "Computer" else get_computer_move(board)
        board[pile-1] -= stones
        print(f"Player {current_player} removes {stones} stones from pile {pile}.")
        if all(stones == 0 for stones in board):
            print(f"Player {current_player} wins!")
            break
        current_player = player2 if current_player == player1 else player1

play_game()

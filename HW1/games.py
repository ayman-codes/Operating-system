import pygame
import random

# initialize pygame
pygame.init()

# set up the screen
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Nim Game")

# set up the game over flag
game_over = False

# set up the font
font = pygame.font.Font(None, 36)

# set up the player and computer
players = ['Player', 'Computer']
current_player = random.choice(players)

# set up the piles
piles = [random.randint(1, 10) for _ in range(3)]
pile_sizes = [50, 100, 150]
pile_colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255)]

# game loop
while not game_over:

    # handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_over = True
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if current_player == 'Player':
                pos = pygame.mouse.get_pos()
                for i, pile_pos in enumerate(pile_positions):
                    if pile_pos[0] <= pos[0] <= pile_pos[0] + pile_sizes[i] and \
                            pile_pos[1] <= pos[1] <= pile_pos[1] + pile_sizes[i]:
                        piles[i] -= random.randint(1, piles[i])
                        current_player = 'Computer'
                        break

    # check for game over
    if all(pile == 0 for pile in piles):
        game_over = True
        winner = current_player

    # draw the background
    screen.fill((0, 0, 0))

    # draw the piles
    pile_positions = [(screen_width // 2 - pile_sizes[0] // 2, screen_height // 2 - pile_sizes[0] // 2),
                      (screen_width // 2 - pile_sizes[1] // 2, screen_height // 2 - pile_sizes[1] // 2 - pile_sizes[0]),
                      (screen_width // 2 - pile_sizes[2] // 2, screen_height // 2 - pile_sizes[2] // 2 - pile_sizes[0] - pile_sizes[1])]
    for i, pile_size in enumerate(pile_sizes):
        pygame.draw.rect(screen, pile_colors[i], (pile_positions[i][0], pile_positions[i][1], pile_size, pile_size))
        pile_text = font.render(str(piles[i]), True, (255, 255, 255))
        screen.blit(pile_text, (pile_positions[i][0] + pile_size // 2 - pile_text.get_width() // 2, pile_positions[i][1] + pile_size // 2 - pile_text.get_height() // 2))

    # draw the current player
    player_text = font.render(current_player + "'s turn", True, (255, 255, 255))
    screen.blit(player_text, (10, 10))

    # update the display
    pygame.display.update()

# draw the winner
winner_text = font.render(winner + ' wins!', True, (255, 255, 255))
screen.blit(winner_text, (screen_width // 2 - winner_text.get_width() // 2, screen_height // 2 - winner_text.get_height() // 2))
pygame.display.update()

# wait for the user to close the window
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()
            





























































						game_over = True
						label = myfont.render("Player 1 wins!!", 1, RED)
						screen.blit(label, (40,10))
					draw_board(board)
					drop_piece(board, row, col, PLAYER_PIECE)
					if winning_move(board, PLAYER_PIECE):
					print_board(board)
					row = get_next_open_row(board, col)
					turn += 1
					turn = turn % 2
				break
				break
				col = int(math.floor(posx/SQUARESIZE))
				column = col
				column = col
				game_over = True
				if is_valid_location(board, col):
				label = myfont.render("Player 2 wins!!", 1, YELLOW)
				posx = event.pos[0]
				pygame.draw.circle(screen, RED, (int(c*SQUARESIZE+SQUARESIZE/2), height-int(r*SQUARESIZE+SQUARESIZE/2)), RADIUS)
				pygame.draw.circle(screen, RED, (posx, int(SQUARESIZE/2)), RADIUS)
				pygame.draw.circle(screen, YELLOW, (int(c*SQUARESIZE+SQUARESIZE/2), height-int(r*SQUARESIZE+SQUARESIZE/2)), RADIUS)
				return (None, -10000000000000)
				return (None, 0)
				return (None, 100000000000000)
				return True
				return True
				return True
				return True
				screen.blit(label, (40,10))
				value = new_score
				value = new_score
			# Ask for Player 1 Input
			#print(event.pos)
			#pygame.time.wait(500)
			alpha = max(alpha, value)
			b_copy = board.copy()
			b_copy = board.copy()
			best_col = col
			best_score = score
			beta = min(beta, value)
			draw_board(board)
			drop_piece(b_copy, row, col, AI_PIECE)
			drop_piece(b_copy, row, col, PLAYER_PIECE)
			drop_piece(board, row, col, AI_PIECE)
			elif board[r][c] == AI_PIECE: 
			elif winning_move(board, PLAYER_PIECE):
			else: # Game is over, no more valid moves
			if alpha >= beta:
			if alpha >= beta:
			if board[r][c] == piece and board[r+1][c+1] == piece and board[r+2][c+2] == piece and board[r+3][c+3] == piece:
			if board[r][c] == piece and board[r+1][c] == piece and board[r+2][c] == piece and board[r+3][c] == piece:
			if board[r][c] == piece and board[r-1][c+1] == piece and board[r-2][c+2] == piece and board[r-3][c+3] == piece:
			if board[r][c] == piece and board[r][c+1] == piece and board[r][c+2] == piece and board[r][c+3] == piece:
			if board[r][c] == PLAYER_PIECE:
			if new_score < value:
			if new_score > value:
			if turn == PLAYER:
			if turn == PLAYER:
			if winning_move(board, AI_PIECE):
			if winning_move(board, AI_PIECE):
			new_score = minimax(b_copy, depth-1, alpha, beta, False)[1]
			new_score = minimax(b_copy, depth-1, alpha, beta, True)[1]
			posx = event.pos[0]
			print_board(board)
			pygame.draw.circle(screen, BLACK, (int(c*SQUARESIZE+SQUARESIZE/2), int(r*SQUARESIZE+SQUARESIZE+SQUARESIZE/2)), RADIUS)
			pygame.draw.rect(screen, BLACK, (0,0, width, SQUARESIZE))
			pygame.draw.rect(screen, BLACK, (0,0, width, SQUARESIZE))
			pygame.draw.rect(screen, BLUE, (c*SQUARESIZE, r*SQUARESIZE+SQUARESIZE, SQUARESIZE, SQUARESIZE))
			return (None, score_position(board, AI_PIECE))
			return r
			row = get_next_open_row(board, col)
			row = get_next_open_row(board, col)
			row = get_next_open_row(board, col)
			score += evaluate_window(window, piece)
			score += evaluate_window(window, piece)
			score += evaluate_window(window, piece)
			score += evaluate_window(window, piece)
			sys.exit()
			turn += 1
			turn = turn % 2
			valid_locations.append(col)
			window = [board[r+3-i][c+i] for i in range(WINDOW_LENGTH)]
			window = [board[r+i][c+i] for i in range(WINDOW_LENGTH)]
			window = col_array[r:r+WINDOW_LENGTH]
			window = row_array[c:c+WINDOW_LENGTH]
		#col = pick_best_move(board, AI_PIECE)
		#col = random.randint(0, COLUMN_COUNT-1)
		col, minimax_score = minimax(board, 5, -math.inf, math.inf, True)
		col_array = [int(i) for i in list(board[:,c])]
		column = random.choice(valid_locations)
		column = random.choice(valid_locations)
		drop_piece(temp_board, row, col, piece)
		else: # Depth is zero
		for c in range(COLUMN_COUNT-3):
		for c in range(COLUMN_COUNT-3):
		for c in range(COLUMN_COUNT-3):
		for col in valid_locations:
		for col in valid_locations:
		for r in range(3, ROW_COUNT):
		for r in range(ROW_COUNT):
		for r in range(ROW_COUNT):
		for r in range(ROW_COUNT):		
		for r in range(ROW_COUNT-3):
		for r in range(ROW_COUNT-3):
		for r in range(ROW_COUNT-3):
		if board[r][col] == 0:
		if event.type == pygame.MOUSEBUTTONDOWN:
		if event.type == pygame.MOUSEMOTION:
		if event.type == pygame.QUIT:
		if is_terminal:
		if is_valid_location(board, col):
		if is_valid_location(board, col):
		if score > best_score:
		opp_piece = AI_PIECE
		pygame.display.update()
		pygame.time.wait(3000)
		return column, value
		return column, value
		row = get_next_open_row(board, col)
		row_array = [int(i) for i in list(board[r,:])]
		score += 100
		score += 2
		score += 5
		score -= 4
		score = score_position(temp_board, piece)
		temp_board = board.copy()
		value = -math.inf
		value = math.inf
	# # Ask for Player 2 Input
	# Check horizontal locations for win
	# Check negatively sloped diaganols
	# Check positively sloped diaganols
	# Check vertical locations for win
	## Score center column
	## Score Horizontal
	## Score posiive sloped diagonal
	## Score Vertical
	best_col = random.choice(valid_locations)
	best_score = -10000
	board = np.zeros((ROW_COUNT,COLUMN_COUNT))
	board[row][col] = piece
	center_array = [int(i) for i in list(board[:, COLUMN_COUNT//2])]
	center_count = center_array.count(piece)
	elif window.count(piece) == 2 and window.count(EMPTY) == 2:
	elif window.count(piece) == 3 and window.count(EMPTY) == 1:
	else: # Minimizing player
	for c in range(COLUMN_COUNT):
	for c in range(COLUMN_COUNT):
	for c in range(COLUMN_COUNT):
	for c in range(COLUMN_COUNT):
	for c in range(COLUMN_COUNT-3):
	for c in range(COLUMN_COUNT-3):
	for c in range(COLUMN_COUNT-3):
	for col in range(COLUMN_COUNT):
	for col in valid_locations:
	for event in pygame.event.get():
	for r in range(ROW_COUNT):
	for r in range(ROW_COUNT):
	for r in range(ROW_COUNT-3):
	for r in range(ROW_COUNT-3):
	if depth == 0 or is_terminal:
	if game_over:
	if maximizingPlayer:
	if piece == PLAYER_PIECE:
	if turn == AI and not game_over:				
	if window.count(opp_piece) == 3 and window.count(EMPTY) == 1:
	if window.count(piece) == 4:
	is_terminal = is_terminal_node(board)
	opp_piece = PLAYER_PIECE
	print(np.flip(board, 0))
	pygame.display.update()
	return best_col
	return board
	return board[ROW_COUNT-1][col] == 0
	return score
	return score
	return valid_locations
	return winning_move(board, PLAYER_PIECE) or winning_move(board, AI_PIECE) or len(get_valid_locations(board)) == 0
	score += center_count * 3
	score = 0
	score = 0
	valid_locations = []
	valid_locations = get_valid_locations(board)
	valid_locations = get_valid_locations(board)
AI = 1
AI_PIECE = 2
BLACK = (0,0,0)
BLUE = (0,0,255)
board = create_board()
COLUMN_COUNT = 7
def create_board():
def draw_board(board):
def drop_piece(board, row, col, piece):
def evaluate_window(window, piece):
def get_next_open_row(board, col):
def get_valid_locations(board):
def is_terminal_node(board):
def is_valid_location(board, col):
def minimax(board, depth, alpha, beta, maximizingPlayer):
def pick_best_move(board, piece):
def print_board(board):
def score_position(board, piece):
def winning_move(board, piece):
draw_board(board)
EMPTY = 0
game_over = False
height = (ROW_COUNT+1) * SQUARESIZE
import math
import numpy as np
import pygame
import random
import sys
myfont = pygame.font.SysFont("monospace", 75)
PLAYER = 0
PLAYER_PIECE = 1
print_board(board)
pygame.display.update()
pygame.init()
RADIUS = int(SQUARESIZE/2 - 5)
RED = (255,0,0)
ROW_COUNT = 6
screen = pygame.display.set_mode(size)
size = (width, height)
SQUARESIZE = 100
turn = random.randint(PLAYER, AI)
while not game_over:
width = COLUMN_COUNT * SQUARESIZE
WINDOW_LENGTH = 4
YELLOW = (255,255,0)
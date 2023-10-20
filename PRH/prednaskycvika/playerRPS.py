import random
from colorama import Fore
class GameOfRPS:
    def __init__(self):
        self.possible_moves = ["R", "P", "S"]

    def move(self):
        my_move = random.choice(self.possible_moves)
        return my_move

    def evaluate(self, *args):
        if args.__len__() > 2:
            raise ValueError
        if "R" in args and "P" in args:
            return "P Wins"
        if args[0] == args[1]:
            return "DRAW"
        if "P" in args and "S" in args:
            return "S Wins"
        if "R" in args and "S" in args:
            return "R Wins"

if __name__ == "__main__":
    my_game = GameOfRPS()
    for i in range(5):
        move1, move2 = my_game.move(), my_game.move()
        reslut = my_game.evaluate(move1, move2)
        print(f"Player1 played {Fore.RED + move1 + Fore.WHITE}; Player2 played \
{Fore.RED + move2 + Fore.WHITE}\n\tResult: {Fore.GREEN + reslut + Fore.WHITE}\n")
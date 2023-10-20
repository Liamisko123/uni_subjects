import random

class MyPlayer:
    '''A copycat that believes good people still exist!'''
    def __init__(self, pay_off_matrix: tuple, number_of_iterations: int=None):
        self.pay_off_matrix = pay_off_matrix
        self.number_of_iterations = number_of_iterations
        self.last_move = []
        self.counter = 0

    def move(self):
        """Returns True or False"""
        if self.last_move == []:
            return False #prefer COOPERATE 
        elif self.counter==0 and self.last_move[1]==True: #0=False - after one DEFECT
            self.counter = 1
            return False
        elif self.counter==1 and self.last_move[1]==True: #1=True - after second DEFECT - REVENGE
            self.counter = 0
            return True
        else:
            return False #prefer COOPERATE 

            

    def record_last_moves(self, my_last_move: bool=None, opponent_last_move: bool=None):
        """Records last moves of both players"""
        if(my_last_move == None or opponent_last_move == None):
            return
        self.last_move = [my_last_move, opponent_last_move]
        return


if __name__ == "__main__":
    payoff_matrix = ( ((4,4),(1,6)) , ((6,1),(2,2)), 250)
    player1 = MyPlayer(payoff_matrix)
    moves = ["", ""]
    counter = 0
    while counter < 20:
        move1 = player1.move()
        move2 = random.choice([True, False])
        print(move1, move2)
        #print(player1.last_move)
        counter += 1
        player1.record_last_moves(move1, move2)

import random

COOPERATE = 0
DEFECT = 1
ME = 1
MY_VARIABLE_CONST = 5


class MyPlayer:
    '''I chose rather entrusting player, though depends on the payoff matrices.'''
    def __init__(self, payoff_matrix, number_of_iterations=False) -> None:
        self.payoff_matrix = payoff_matrix
        self.number_of_iterations = number_of_iterations
        self.strategy = "" #strategies - CC/ECC/AAA/OD/OC
        self.moves_history = []
        self.my_decisions = []
        self.counter = 0
        self.round_counter = 0
        self.make_strategy()

    def check_extreme(self, choice1, choice2) -> bool:
        opponent1, myself1 = choice1
        opponent2, myself2 = choice2
        if self.payoff_matrix[opponent1][myself1][1] > MY_VARIABLE_CONST * self.payoff_matrix[opponent2][myself2][1]:
            return True
        return False

    def check_payoff(self) -> None: #https://www.horacemann.org/uploaded/HoraceMann/Images/News/2011-2012_News/James_Ruben_--_original.pdf
        if (self.payoff_matrix[COOPERATE][DEFECT][ME] >= self.payoff_matrix[COOPERATE][COOPERATE][ME]) >= (self.payoff_matrix[DEFECT][DEFECT][ME] >= self.payoff_matrix[DEFECT][COOPERATE][ME]):
            if self.check_extreme((COOPERATE, DEFECT), (COOPERATE, COOPERATE)): #check extreme cases for Defect/Coop
                self.strategy = "AAA"
            else:
                self.strategy = "CC"
        elif self.payoff_matrix[COOPERATE][COOPERATE][ME] >= self.payoff_matrix[COOPERATE][DEFECT][ME] + MY_VARIABLE_CONST:
            self.strategy = "ECC"
        else:
            self.strategy = "AAA"

    def check_noise(self):
        game_length = len(self.moves_history)
        if game_length % 20 != 0 or game_length == 0:
            return
        sum_of_differences = 0
        for round in range(game_length):
            if self.moves_history[round][0] != self.my_decisions[round]:
                sum_of_differences += 1
        if (sum_of_differences / game_length) >= 0.20: #if there isatleast 20% noise then take meassures
            if self.payoff_matrix[COOPERATE][COOPERATE][ME] + self.payoff_matrix[DEFECT][COOPERATE][ME] >= \
            self.payoff_matrix[COOPERATE][DEFECT][ME] + self.payoff_matrix[DEFECT][DEFECT][ME]:
                self.strategy = "OC"
            else:
                self.strategy = "OD"

    def check_move_history(self, n) -> bool:
        if(len(self.moves_history) == n):
            n_sum = 0
            for i in range(-1, -5): #check last four moves of the oponent
                if self.moves_history[i] == True:
                    n_sum += 1
            if n_sum == n:
                return True
        return False
        
    def make_strategy(self) -> None:
        self.check_payoff()
        if(self.number_of_iterations):
            if(self.number_of_iterations < 3): 
                self.strategy = "ECC"  #if there is not enough playeroom play passively
    
    def move(self) -> bool:
        print(f"My strategy: {self.strategy} : ", end="")
        self.check_noise()
        match self.strategy:
            case "CC":
                my_move = self.move_copycat()
            case "ECC":
                my_move = self.move_extra_copycat()
            case "AAA":
                my_move = self.move_almost_always_attack()
            case "OD":
                my_move = self.only_deceit()
            case "OC":
                my_move = self.only_coop()
            case _:
                my_move = False
        self.my_decisions.append(my_move)
        return my_move

    def only_deceit():
        return True
    
    def only_coop():
        return False
            
    def move_copycat(self) -> bool:
        if self.moves_history == []:
            return False #prefer COOPERATE
        elif self.counter == 1 and self.moves_history[-1][1]: #1=True - after one deceit
            self.counter = 0
            return True
        elif self.counter == 0 and self.moves_history[-1][1]: #0=False - after second deceit
            self.counter += 1
            return False
        else:
            return False
    
    def move_extra_copycat(self) -> bool:
        if self.moves_history == []:
            return False #prefer COOPERATE
        elif self.check_move_history(MY_VARIABLE_CONST): #check if True hasn't been played in the last n moves | n=3
            self.strategy = "CC"
            return True
        else:
            return False
        
    def move_almost_always_attack(self) -> bool:
        if self.moves_history == []:
            self.counter += 1
            return True #prefer Defect
        elif self.counter > 1: #1=True - after one deceit
            self.counter = 0
            return False
        else:
            self.counter += 1
            return True
 
    def record_last_moves(self, my_last_move, opponent_last_move) -> None:
        self.moves_history.append((my_last_move, opponent_last_move))

if __name__ == "__main__":
    payoff_matrix1 = ( ((4,4),(1,6)) , ((6,1),(2,2)) )
    payoff_matrix2 = ( ((2, 2),(4,6)) , ((6,4),(10,10)) )
    payoff_matrix3 = ( ((5, 5),(1,70)) , ((70,1),(2,2)) )
    player1 = MyPlayer(payoff_matrix1)
    player2 = MyPlayer(payoff_matrix3)
    moves = ["", ""]
    counter = 0
    while counter < 20:
        move1 = player1.move()
        move2 = player2.move()
        #move2 = random.choice([True, False])
        print(move1, move2)
        #print(player1.last_move)
        counter += 1
        player1.record_last_moves(move1, move2)
        player2.record_last_moves(move1, move2)
    print(player1.strategy)

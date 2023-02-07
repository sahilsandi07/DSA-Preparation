import random

Choices = ['rock' , 'paper' , 'scissors']

while True:
    print ("Make Your Choice!")
    player_opt=input("     Type rock, paper, scissors: ")
    if player_opt in Choices:
        computer_opt=random.choice(Choices)
        print(
            f"\nYou threw '{player_opt}', the computer threw '{computer_opt}'"
        )
    
    else:
        print(f"\nYou threw '{player_opt}', which is not a valid throw  :(")
    
    

    if player_opt == computer_opt:
        print(f"Both players selected {player_opt}. It's a tie!")
    elif player_opt == "rock":
        if computer_opt == "scissors":
            print("Rock smashes scissors! You win!")
        else:
            print("Paper covers rock! You lose.")
    elif player_opt == "paper":
        if computer_opt == "rock":
            print("Paper covers rock! You win!")
        else:
            print("Scissors cuts paper! You lose.")
    elif player_opt == "scissors":
        if computer_opt == "paper":
            print("Scissors cuts paper! You win!")
        else:
            print("Rock smashes scissors! You lose.")
    

    again=input("\n Wanna Play Again? (y/n)")
    if again.lower()=="n":
        break

    print()

print("\n Thanks, for playing the Game!")
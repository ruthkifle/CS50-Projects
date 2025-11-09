from cs50 import get_float

change = 0
coins = 0
while change <= 0:
    change = get_float("Change: ")


def Coin_adder(Coin):
    global change
    global coins
    while (change >= Coin):
        change = round(change - Coin, 10)
        coins += 1


Coin_adder(0.25)
Coin_adder(0.10)
Coin_adder(0.05)
Coin_adder(0.01)
print(coins)

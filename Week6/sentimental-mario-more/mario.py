height = 0
# Get the invalids out of the way

while height < 1 or height > 8:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Enter a valid height")
# Build your pyramid

for i in range(height):
    print(" " * (height - 1 - i), end="")
    print("#" * (i + 1) + "  " + "#" * (i + 1))

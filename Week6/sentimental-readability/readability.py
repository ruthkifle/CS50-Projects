from cs50 import get_string

# Get the text
text = get_string("Text: ")

# Count the letter
letter = 0
for char in text:
    if char.isalpha():
        letter += 1

# Count the word
word = 1
for char in text:
    if char == " ":
        word += 1

# Count the sentence
sentence = 0
for char in text:
    if char == "." or char == "!" or char == "?":
        sentence += 1

# Compute it
L = (letter / word) * 100
S = (sentence / word) * 100

aver = round(0.0588 * L - 0.296 * S - 15.8)

# Print the Grade
if aver < 1:
    print("Before Grade 1")
elif aver >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(aver))

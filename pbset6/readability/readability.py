from cs50 import get_string


def main():
    text = get_string("Txt: ")

    nletters = count_letters(text)
    nwords = count_words(text) + 1
    nsentences = count_sentences(text)

    l = nletters / nwords * 100
    s = nsentences / nwords * 100

    index = 0.0588 * l - 0.296 * s - 15.8


    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {int(index)}")


def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if str.isalpha(text[i]):
            letters += 1
    return letters

def count_words(text):
    words = 0
    for i in range(len(text)):
        if str.isspace(text[i]):
            words += 1
            
    return words
    
    
def count_sentences(text):
    sentences = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            sentences += 1

    return sentences




main()
import csv
import sys

def  main():

    if len(sys.argv) != 3:
        sys.exit("Usage python dna.py filename filename")

    STR = []
    dbs = []

    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        row1 = next(reader)
        for item in range(1,len(row1)):
            STR.append(row1[item])


    with open(sys.argv[1], "r") as f:
        r = csv.DictReader(f)
        for row in r:
            for i in range(len(row) - 1):
                row[STR[i]] = int(row[STR[i]])
            dbs.append(row)

    with open(sys.argv[2], "r") as txt:
        text = txt.read()


    STRc = []

    for string in STR:
        nmax = repeat(string, text)
        STRc.append(nmax)
    
    
    
    for row in dbs:
        l = list(row.values())
        l.pop(0)
        if l == (STRc):
            print(row['name'])
            sys.exit()
            
    
    print("No match")
    
    
  #  for row in dbs:
      #  for key in STR:
            
            
            




def repeat(STR, txt):
    counter = 0
    l = len(txt)
    for i in range(l):
        if txt[i : i + len(STR)] == STR:
            tmpcounter = 0
            a = i
            while(txt[a : a + len(STR)] == STR):
                tmpcounter += 1
                a += len(STR)
            if tmpcounter > counter:
                counter = tmpcounter

    return counter



if __name__ == "__main__":
    main()




    #for i in range(len(text)):
     #   if text[i:i + len(STR[0])] == STR[0]:
      #      a = i
       #     while(text[a:a + len(STR[0])] == STR[0]):
        #        print("YEP Cock")
         #       a += len(STR[0])
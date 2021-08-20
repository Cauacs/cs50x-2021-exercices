import csv

morra = []

with open("2018m.csv","r") as file:
    reader = csv.reader(file)
    print(reader[1])
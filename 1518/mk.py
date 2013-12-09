from random import *
from subprocess import call

n = 10
fout = open("input.in", "w")
fout.write(str(n)+"\n");
for cnt in range(1, n + 1):
    fout.write("Sentence " + str(randint(1, n)) + " is ")
    if randint(0, 1) == 1:
        fout.write("true.\n")
    else:
        fout.write("false.\n")
fout.write(str(0));
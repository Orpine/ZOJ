from random import *
from subprocess import call

while True:
    call(["python", "mk.py"])
    call("./1518_std")
    call("./1518")
    if call(["diff", "output.out", "output.ans"]):
        break;
import math
from mpmath import mp
import matplotlib.pyplot as plt

mp.dps = 100

def index(x, q):
    p = round(x * q)
    return -mp.log(mp.fabs(mp.mpf(p)/q-x), b=q)

def plot_index(x, qmax, ax):
    fs = [index(x, q) for q in range(2, qmax)]
    ax.scatter(range(2, qmax), fs, s=2)
    for q in range(2, qmax):
        i = q - 2
        p = round(x * q)
        if fs[i] >= 2 and math.gcd(p, q) == 1:
            ax.annotate("{}/{}".format(p, q), (q-10, fs[i]+0.05), fontsize=7)

data = [
    (mp.cbrt(2), "cube root of 2", "∛(2)", "cbrt2.png"),
    (mp.pi, "pi", "π", "pi.png"),
    (mp.cbrt(31), "cube root of 31", "∛(31)", "cbrt31.png"),
    (9801/(2206*mp.sqrt(2)), "9801/2206√2", "9801/2206√2", "9801.2206.sqrt2.png")
]

for (x, name, sym, filename) in data:
    plt.clf()
    fig = plt.figure()
    fig.suptitle("Rational approximants of {}".format(name))
    ax = fig.add_subplot()
    ax.minorticks_on()
    ax.grid(which="minor", axis="both", color="lightgray", alpha=0.5)
    ax.grid(which="major", axis="both", color="gray", alpha=0.5)
    ax.set_xlabel("q")
    ax.set_ylabel("-log_q |p/q-{}|".format(sym))
    plot_index(x, 1000, ax)
    fig.savefig("scatter."+filename, dpi=300)

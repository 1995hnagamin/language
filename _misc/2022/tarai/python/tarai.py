import timeit
import pandas as pd

def tarai(x, y, z):
    if x > y:
        return tarai(tarai(x-1, y, z), tarai(y-1, z, x), tarai(z-1, x, y))
    else:
        return y

arr = [(10, 5), (11, 5), (12, 6), (13, 6), (13, 7), (14, 7)]
for x, y in arr:
    print("\nx = %d, y = %d" % (x, y))
    result = timeit.repeat(lambda: tarai(x, y, 0), number=1, repeat=10)
    print(result)
    print(pd.DataFrame(result).describe().transpose())

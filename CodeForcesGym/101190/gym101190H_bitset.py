# TLE 32
from functools import reduce

def idx( x ): return x + 32768

def gt( bitset, bound ):
    for i in range(bound, 32768):
        bitset[idx(i)] = True
    return bitset

def lt( bitset, bound ):
    for i in range(-32768, bound + 1):
        bitset[idx(i)] = True
    return bitset

def gtxlty( bitset, x, y ):
    if x > y: return bitset
    for i in range(x, y + 1):
        bitset[idx(i)] = True
    return bitset

def main():
    text, dtext = [], []

    with open('hard.in', 'r') as fin:
        text = fin.readlines()
    fout = open('hard.out', 'w')
    text = [e.strip() for e in text]

    endflag = [i for i in range(len(text)) if text[i][-2:] != '||']
    beginfg = [0] + [_ + 1 for _ in endflag[:-1]]

    for tt in range(len(endflag)):
        bitset = [False] * 65536
        for i in range(beginfg[tt], endflag[tt] + 1):
            word = text[i].split()
            if i != endflag[tt]: word = word[:-1]
            if (len(word) == 3):
                bound = int(word[2])
                bitset = gt(bitset, bound) if word[1] == '>=' else lt(bitset, bound)
            else:
                bitset = gtxlty(bitset, int(word[2]), int(word[6]))
        cntall = reduce(lambda _, x: _ + (1 if x else 0), bitset)
        if cntall == 65536:
            print('true', file=fout)
        elif cntall == 0:
            print('false', file=fout)
        else:
            i, bound, ans =-32768, [], []
            while i <= 32767:
                if bitset[idx(i)]:
                    lbound = i
                    while (i + 1 < 32768 and bitset[idx(i + 1)]): i += 1
                    bound.append((lbound, i))
                i += 1
            for seg in bound:
                x, y = seg
                if (x == -32768):
                    ans.append('x <= ' + str(y))
                elif (y == 32767):
                    ans.append('x >= ' + str(x))
                else: ans.append('x >= ' + str(x) + ' && x <= ' + str(y))
            print(' ||\n'.join(ans), file=fout)
    fout.close()

if __name__ == '__main__':
    main()
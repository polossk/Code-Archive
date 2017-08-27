def idx( x ): return x + 32768

def main():
    text, dtext = [], []

    with open('hard.in', 'r') as fin:
        text = fin.readlines()
    fout = open('hard.out', 'w')
    text = [e.strip() for e in text]

    endflag = [i for i in range(len(text)) if text[i][-2:] != '||']
    beginfg = [0] + [_ + 1 for _ in endflag[:-1]]

    for tt in range(len(endflag)):
        segs = []
        for i in range(beginfg[tt], endflag[tt] + 1):
            word = text[i].split()
            if i != endflag[tt]: word = word[:-1]
            if (len(word) == 3):
                bound = int(word[2])
                segs.append([bound, 32767] if word[1][0] == '>' else [-32768, bound])
            else:
                x, y = int(word[2]), int(word[6])
                if x > y: continue
                segs.append([x, y])
        segs.sort(key=lambda s: (s[0], s[1]))
        if len(segs) == 0:
            print('false', file=fout)
            continue
        hoge = [segs[0]]
        for i in range(1, len(segs)):
            if segs[i][0] == segs[i - 1][0]:
                hoge[-1][1] = max(segs[i][1], segs[i - 1][1])
            else: hoge.append(segs[i])
        piyo = [hoge[0]]
        for i in range(1, len(hoge)):
            if hoge[i][0] <= piyo[-1][1] + 1:
                piyo[-1][1] = max(piyo[-1][1], hoge[i][1])
            else: piyo.append(hoge[i])
        if len(piyo) == 1 and piyo[0][0] == -32768 and piyo[0][1] == 32767:
            print('true', file=fout)
            continue
        ans = []
        for seg in piyo:
            [x, y] = seg
            if (x == -32768):
                ans.append('x <= ' + str(y))
            elif (y == 32767):
                ans.append('x >= ' + str(x))
            else: ans.append('x >= ' + str(x) + ' && x <= ' + str(y))
        print(' ||\n'.join(ans), file=fout)
    fout.close()

if __name__ == '__main__':
    main()
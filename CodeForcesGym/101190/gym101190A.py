import re, os

def abbr( s ):
    raw = [e for e in list(s.group()) if e >='A' and e <= 'Z']
    return ''.join(raw) + ' (' + s.group() + ')'

def main():
    pattern = re.compile(r'\b[A-Z][a-z]+( [A-Z][a-z]+\b)+')
    text, dtext = [], []

    with open('abbreviation.in', 'r') as fin:
        text = fin.readlines()

    for line in text:
        dtext.append(pattern.sub(abbr, line))

    with open('abbreviation.out', 'w') as fout:
        for line in dtext:
            fout.write(line)

if __name__ == '__main__':
    main()
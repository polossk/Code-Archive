import re, os

def abbr( s ):
    raw = [e for e in list(s.group()) if e >='A' and e <= 'Z']
    return ''.join(raw) + ' (' + s.group() + ')'

def main():
    pattern = re.compile(r'\b[A-Z][a-z]+( [A-Z][a-z]+\b)+')
    while True:
        try:
            print(pattern.sub(abbr, input()))
        except EOFError:
            break

if __name__ == '__main__':
    main()
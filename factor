#!/usr/bin/python3
import sys

if __name__ == "__main__":
    with open(sys.argv[1], 'r') as file:
        for line in file:
            n = int(line.strip())
            i = 2
            while i <= n / i:
                if n % i == 0:
                    print(f"{n}={i}*{n // i}")
                    break
                i += 1
            else:
                print(f"{n}={n}*1")

from random import *


NUMBERS_LINES = 1000000

with open(f'test_{NUMBERS_LINES}', 'w') as f:
    f.write(str(NUMBERS_LINES))
    for i in range(1, NUMBERS_LINES):
        f.write(f'{choice(range(1000))} {choice(range(1000))}\n')
    f.write(str(choice(range(1000))))

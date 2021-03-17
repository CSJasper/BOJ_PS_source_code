import sys


def draw_square(current_size, initial_size):
    basic_element = '''
    ***
* *
***'''
    if current_size == 3:
        print(basic_element, end="")
        return
    

square_size = int(sys.stdin.readline())


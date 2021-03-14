def is_prime(number):
    if number == 1:
        return False
    idx_func = 2
    while idx_func * idx_func <= number:
        if number % idx_func == 0:
            return False
        idx_func += 1
    return True

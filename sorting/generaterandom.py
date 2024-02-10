#Random number generator I used to test sorting algorithms with a constant, but variable random array
def GenArray(size, bound, seed):
    import random
    random.seed(seed)
    array = []
    for i in range(size):
        array.append(random.randint(0, bound))
    return array

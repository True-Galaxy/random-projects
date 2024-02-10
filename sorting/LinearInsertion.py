from time import time
import generaterandom #See other file
n = int(input("Enter number of elements: "))
b = int(input("Enter the upper bound: "))
k = int(input("And how many trials: "))


def LinearInsert(arr):
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

times = []
for i in range(k):
    array = generaterandom.GenArray(n, b, i)
    start = time()
    LinearInsert(array)
    end = time()
    times.append(end - start)
avgtime = sum(times) / k
print(f"The array took on average {round(avgtime*1000, 2)}ms to sort.")
print(f"The longest time was {round(max(times)*1000, 2)}ms.")
print(f"And the shortest time was {round(min(times)*1000, 2)}ms.")

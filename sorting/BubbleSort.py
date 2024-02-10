from time import time
import generaterandom #See other file
n = int(input("Enter number of elements: "))
b = int(input("Enter the upper bound: "))
k = int(input("And how many trials: "))


def BubbleSort(arr):
    swap = None
    while swap != 0:
        swap = 0
        for i in range(n - 1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swap += 1

times = []
swap = None
for i in range(k):
    array = generaterandom.GenArray(n, b, i)
    start = time()
    BubbleSort(array)
    end = time()
    times.append(end - start)
avgtime = sum(times) / k
print(f"The array took on average {round(avgtime*1000, 2)}ms to sort.")
print(f"The longest time was {round(max(times)*1000, 2)}ms.")
print(f"And the shortest time was {round(min(times)*1000, 2)}ms.")

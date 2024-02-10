from time import time
import generaterandom #See other file
n = int(input("Enter number of elements: "))
b = int(input("Enter the upper bound: "))
k = int(input("And how many trials: "))

def BinarySearch(arr, l, r, x):
    if r >= l:
        mid = (l + r) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return BinarySearch(arr, l, mid - 1, x)
        else:
            return BinarySearch(arr, mid + 1, r, x)
    else:
        return -1
def BinaryInsertion(arr):
    

times = []
for i in range(k):
    array = generaterandom.GenArray(n, b, i)
    start = time()
    BinaryInsertion(array)
    end = time()
    times.append(end - start)
avgtime = sum(times) / k
print(f"The array took on average {round(avgtime*1000, 2)}ms to sort.")
print(f"The longest time was {round(max(times)*1000, 2)}ms.")
print(f"And the shortest time was {round(min(times)*1000, 2)}ms.")

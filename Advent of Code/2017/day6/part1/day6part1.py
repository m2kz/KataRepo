input = [4, 1, 15, 12, 0, 9, 9, 5, 5, 8, 7, 3, 14, 5, 12, 3]
import collections
import copy

def main():
    d = collections.deque(maxlen=len(input))
    snapshots = []
    golden_tuple = []
    iter = 0
    for i in input:
        d.append(i)
    while(1):
        iter += 1
        max_value = max(d)
        max_value_index = list(d).index(max_value)
        d[max_value_index] = 0
        stop_value = max_value_index + 1 + max_value
        for x in range(max_value_index + 1, stop_value):
            lazy_index = x % len(input)
            d[lazy_index] += 1
        snapshots.append(tuple(d))
        number_of_tuples = len(snapshots)
        set_of_tuples = len(set(snapshots))
        if (number_of_tuples - set_of_tuples == 1):
            golden_tuple.append(copy.copy(d))
        if (number_of_tuples - set_of_tuples > 1):
            if golden_tuple[0] == d:
                print "blep"

main()

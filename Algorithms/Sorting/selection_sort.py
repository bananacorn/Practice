import random
n = eval(input("Enter a positive integer: "))
n_1 = 0
rand_list = []
rand_list = list(range(n))
random.shuffle(rand_list)
print (rand_list)
a = 1
b = 0
while a < n:
    minimum = rand_list[a:][0]
    index = a
    for i in range(len(rand_list[a:])):
        if rand_list[a:][i] < minimum:
            minimum = rand_list[a:][i]
            index = i + a
    if minimum < rand_list[b]:
        i = rand_list.index(minimum)
        rand_list[i], rand_list[b] = rand_list[b], rand_list [i]
        a += 1
        b += 1
    else:
        a += 1
        b += 1
print (rand_list)

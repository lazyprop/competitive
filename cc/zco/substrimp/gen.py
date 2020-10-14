import random

s = "1\n"
n = random.randint(1, 10)
k = random.randint(1, n)
s+= "{} {}\n".format(n, k)

for i in range(n):
    s += "{} ".format(random.choice(['X', 'Y', 'Z']))
s = s[:-1]
s+= "\n"

print(s)

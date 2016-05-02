import random
filename = raw_input('Enter a filename: ') or 'input.txt'
f = open(filename, "w")
max_nodes = int(input('Input how many nodes to generate: '))
max_value = int(input('Input maximum valuse of key: '))
seq = random.sample(range(0, max_value), max_nodes)

for i in range(0,max_nodes):
    line = str(seq[i]) + " " + str(random.randint(0, 20000000))+"\n"
    f.write(line)

f.close()

input = open("input.txt","r")
output = open("output.txt","w")
n = int(input.read())
cnt = n / 3
if(cnt % 2 == 0):
	output.write(str(int(2 ** (n * 2 / 3 - 1) - 1 + 2 ** (n / 3 - 1) - 1 + 1)))
else:
	output.write(str(int(2 ** (n * 2 / 3 - 1) - 1 + 1 + 2 ** (n / 3) - 1 - 1)))

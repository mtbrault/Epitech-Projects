#!/usr/bin/env python3
import sys

def readFile(name):
	try:
		content = open(name, 'r').read().splitlines()
	except:
		print("Bad file or corrupted file.")
		sys.exit(84)
	return content

def errorHandling(content):
	if len(content) != int(content[0][0], 10) + 1:
		print("Invalid nb lines")
		sys.exit(84)
	content = content[1:]
	stock = len(content[0])
	for i in content:
		if len(i) != stock:
			print("One row is lower or higher than the others")
			sys.exit(84)
	return content

def convertToIntTable(charTable):
	table = []
	for i in range(len(charTable)):
		tmp = []
		for s in range(len(charTable[i])):
			tmp.append((charTable[i][s] == '.') if 1 else 0)
		table.append(tmp)
	return table

def replaceValue(charTable, intTable):
	value = 0
	x = 0
	y = 0
	for i in range(len(intTable)):
		for s in range(len(intTable[i])):
			if intTable[i][s] > value:
				value = intTable[i][s]
				x = i
				y = s
	count = 0
	while (count < value):
		tmp = 0
		while (tmp < value):
			stringtmp = list(charTable[x + count])
			stringtmp[y + tmp] = 'X'
			charTable[x + count] = "".join(stringtmp)
			tmp += 1
		count += 1
	return charTable

def algo(charTable, intTable):
	x = len(intTable) - 2
	while x >= 0:
		y = len(intTable[x]) - 2
		while y > 0:
			if intTable[x][y] != 0:
				intTable[x][y] = 1 + min([intTable[x][y + 1], intTable[x + 1][y + 1], intTable[x + 1][y]])
			y -= 1
		x -= 1
	return replaceValue(charTable, intTable)

if __name__ == "__main__":
	if len(sys.argv) != 2:
		print("Error")
		sys.exit(84)
	fileContent = readFile(sys.argv[1])
	fileContent = errorHandling(fileContent)
	intTable = convertToIntTable(fileContent)
	fileContent = algo(fileContent, intTable)
	for i in range(len(fileContent)):
		print(fileContent[i])
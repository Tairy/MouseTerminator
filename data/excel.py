import xlwt
readFile = open("test-2.txt")
file = xlwt.Workbook()
table = file.add_sheet('left')
linenum  = 0
while 1:
    line = readFile.readline()
    if not line:
        break
    if line[1]=='o':
        linenum+=1
        splinr = line.split(',')
        leftX = splinr[0].split('(')[1]  #lefteye x
        leftY = splinr[1].split(')')[0]  #lefteye y
        table.write(linenum,0,leftX)
        table.write(linenum,1,leftY)
file.save('text-nose-2.xls')
print "finish!"

# -*- coding: UTF-8 -*-
import numpy as np
import matplotlib.pyplot as plt
i = 0
while 1:
	i += 1
	fp = open('9.txt')
	datalist = fp.readlines()
	lefteye_x = []
	lefteye_y = []
	lefteye_times = []
	righteye_x = []
	righteye_y = []
	righteye_times = []
	nose_x = []
	nose_y = []
	nose_times = []
	mouse_x = []
	mouse_y = []
	mouse_times = []
	for data in datalist:
		splitdata = data.split(',')
		splitdata = map(int, splitdata)
		if splitdata[1] == 1:
			lefteye_x.append(splitdata[2])
			lefteye_y.append(splitdata[3])
			lefteye_times.append(splitdata[0])
		elif splitdata[1] == 2:
			righteye_x.append(splitdata[2])
			righteye_y.append(splitdata[3])
			righteye_times.append(splitdata[0])
		elif splitdata[1] == 3:
			nose_x.append(splitdata[2])
			nose_y.append(splitdata[3])
			nose_times.append(splitdata[0])
		else:
			mouse_x.append(splitdata[2])
			mouse_y.append(splitdata[3])
			mouse_times.append(splitdata[0])
	plt.plot(lefteye_times, lefteye_x, 'o-')
	plt.xlabel('times')
	plt.ylabel('nose_x')
	plt.title('nose_x-time filgue')
	# plt.ylim(390,420)
	#plt.xlim(i,i+200)
	plt.show()
	plt.close()
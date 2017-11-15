#coding:utf-8
# import os
# name = raw_input("what's your name?\n");
# print ("hello, " + name);
# os.system("pause");

#encoding:utf-8
from matplotlib import pyplot as plt
import numpy as np
x=np.arange(-2*np.pi,2*np.pi,0.01);# the default interval is 1;
y=np.sin(x);
plt.plot(x,y,'r');
plt.title("y=sin(x)");
plt.xlabel("X axis");
plt.ylabel("y axis");
plt.show();

def compute_window(QM, FFT_flag):
	cwindow = [[[1, 1, 2], [1, 1, 3], [2, 2, 5], [4, 4, 9], [7, 8, 17], [13, 16, 33]],
				[[1, 1, 3], [1, 1, 5], [2, 2, 9], [4, 4, 17], [7, 8, 33], [13, 16, 33]],
				[[1, 1, 5], [1, 1, 9], [2, 2, 17], [4, 4, 33], [7, 8, 33], [13, 16, 33]]];
	
	fft_size = 64 * (2 ** FFT_flag);
	tau = cwindow[QM][FFT_flag][0];
	sync = cwindow[QM][FFT_flag][1];
	leak = cwindow[QM][FFT_flag][2];
	
	ratio = (fft_size - tau - sync - leak) * 1.0 / fft_size;
	window = [];
	for i in range(tau+sync):
		window.append(1.0);
	for i in range(tau+sync, tau+sync+leak-1):
		window.append((leak - 1 -(i - tau - sync)) * 1.0 /(leak - 1));
	for i in range(tau+sync+leak-1, fft_size-sync-leak+1):
		window.append(0);
	for i in range(fft_size-sync-leak+1, fft_size-sync):
		window.append((i-fft_size-sync-leak+1)+1) * 1.0 /(leak-1));
	for i in range(fft_size - sync, fft_size):
		window.append(1.0);

#coding:utf-8
from matplotlib import pyplot as plt
import numpy as np


theta = np.arange(0, 2*np.pi, 0.02);

r = 2*np.fabs(np.sin(2*theta)) + np.fabs(np.sin(4*theta));
plt.subplot(111, polar=True);
plt.plot(theta, r, "r");
plt.show()

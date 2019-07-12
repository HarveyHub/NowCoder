#coding:utf-8
import subprocess
retcode = subprocess.Popen("ls -alF", shell=True, stdout=subprocess.PIPE)
for line in retcode.stdout:
	print(line)

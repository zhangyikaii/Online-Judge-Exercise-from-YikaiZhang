:loop
generator.exe > data.txt   
correct.exe < data.txt > correctAns.txt  
my.exe < data.txt > myAns.txt 
fc /A correctAns.txt myAns.txt
if not errorlevel 1 goto loop
pause
:end
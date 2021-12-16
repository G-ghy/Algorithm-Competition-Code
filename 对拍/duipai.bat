@echo off
:loop
    makeData.exe > in.txt
    myCode.exe < in.txt > myCode.txt
    right.exe < in.txt > right.txt
    fc demo.txt right.txt
if not errorlevel 1 goto loop
pause
goto loop
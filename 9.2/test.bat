echo off 

echo test1
9.2.exe "notfoundtext.txt" > 1.txt 
IF NOT ERRORLEVEL 1 GOTO testFailed 
fc /b 1.txt standard/1.txt
IF ERRORLEVEL 1 GOTO testFailed 

echo test2
9.2.exe > 2.txt 
IF  NOT ERRORLEVEL 1 GOTO testFailed 
fc /b 2.txt standard/2.txt 
IF ERRORLEVEL 1 GOTO testFailed 

echo test3
9.2.exe "input.txt" > 3.txt 
IF  NOT ERRORLEVEL 0 GOTO testFailed 
fc /b 3.txt standard/3.txt 


echo OK 
pause 
exit /B 

:testFailed 
echo Testing failed 
pause 
exit /B
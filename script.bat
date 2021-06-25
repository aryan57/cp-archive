@echo off

set DIR="C:\Users\aryan\.cp-archive"
for /F "usebackq tokens=1,2 delims==" %%i in (`wmic os get LocalDateTime /VALUE 2^>NUL`) do if '.%%i.'=='.LocalDateTime.' set DATE=%%j
set DATE=%DATE:~0,4%-%DATE:~4,2%-%DATE:~6,2% %DATE:~8,2%:%DATE:~10,2%:%DATE:~12,2%

cd %DIR%
call git add .
call git commit -m "%DATE%"
call git push
@echo off
chcp 65001 > nul
echo -- сторока параметров: %*
echo -- параметр 1: %1
echo -- параметр 2: %2
echo -- параметр 3: %3
set /a result = %1 %3 %2
echo результат: %result%
pause
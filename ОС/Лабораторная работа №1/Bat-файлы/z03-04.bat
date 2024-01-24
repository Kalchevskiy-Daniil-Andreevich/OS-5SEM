@echo off
chcp 65001 > nul
echo -- cторока параметров: %*
echo -- параметр 1: %1
echo -- параметр 2: %2
echo -- параметр 3: %3
set /a sum = %1 + %2
echo -- %1 + %2 = %sum%
set /a mul = %1 * %2
echo -- %1 * %2 = %mul%
set /a dis = %3 / %2
echo -- %3 / %2 = %dis%
set /a era = %2 - %1
echo -- %2 - %1 = %era%
set /a res = (%2 - %1)*(%1 - %2)
echo -- (%2 - %1)*(%1 - %2) = %res%
pause
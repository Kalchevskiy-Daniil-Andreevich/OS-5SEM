@echo off
chcp 65001 > nul
echo -- имя этого bat-файла: %~n0
for /f "skip=5 tokens=1,2 delims= " %%a in ('dir /a-d /tc "z03-02.bat"') do (
  echo -- этот bat-файл создан: %%b
  goto nextx
)
:nextx
echo -- путь bat-файла: %~f0
pause
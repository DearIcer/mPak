@echo off

rem copyright @ https://inite.cn

set EDITOR_PATH=%1
set PROJECT_PATH=%2
set TARGET_PLATFORM=%3

rem Build command line string
set CommandLine=%EDITOR_PATH% %PROJECT_PATH% -run=cook -targetplatform=%TARGET_PLATFORM%  -unversioned -CrashForUAT -NoLogTimes -UTF8Output

rem Print the command line for debugging
echo %CommandLine%


rem Execute the command line
%CommandLine%
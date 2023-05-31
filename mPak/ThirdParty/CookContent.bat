@echo off

set EDITOR_PATH=%1        REM 设置编辑器路径
set PROJECT_PATH=%2       REM 设置项目路径
set TARGET_PLATFORM=%3    REM 设置目标平台

rem 构建命令行字符串
set CommandLine=%EDITOR_PATH% %PROJECT_PATH% -run=cook -targetplatform=%TARGET_PLATFORM%  -unversioned -CrashForUAT -NoLogTimes -UTF8Output

rem 打印命令行以进行调试
echo %CommandLine%

rem 执行命令行
%CommandLine%
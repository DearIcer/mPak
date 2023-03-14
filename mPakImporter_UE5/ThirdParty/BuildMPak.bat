::parameter list:

::ProjectName
::TargetPakFile_pie
::TargetPakFile_run
::PakSourceListFile_pie
::PakSourceListFile_run
::mPakOutput

@REM Cook Content
SET UE_EXE="UnrealEditor-Cmd.exe"
SET Project=%1
SET TargetPakFile_pie=%2
SET TargetPakFile_run=%3
SET PakSourceListFile_pie=%4
SET PakSourceListFile_run=%5
SET mPakOutput=%6

SET UnrealPak_EXE="UnrealPak.exe"
SET mPakCore="C:\tools\mPakCore.exe"

%UE_EXE% %Project% -run=Cook -TargetPlatform=Windows -unversioned -stdout -CrashForUAT -unattended -NoLogTimes -UTF8Output

%UnrealPak_EXE% %TargetPakFile_pie% %PakSourceListFile_pie%

%UnrealPak_EXE% %TargetPakFile_run% %PakSourceListFile_run%

mPakCore %TargetPakFile_pie% %TargetPakFile_run% -output=%mPakOutput%

echo "-----------------------------------------------------------------"

echo %UE_EXE% %Project% -run=Cook -TargetPlatform=Windows -unversioned -stdout -CrashForUAT -unattended -NoLogTimes -UTF8Output

echo %UnrealPak_EXE% %TargetPakFile_pie% %PakSourceListFile_pie%

echo %UnrealPak_EXE% %TargetPakFile_run% %PakSourceListFile_run%

echo mPakCore %TargetPakFile_pie% %TargetPakFile_run% -output=%mPakOutput%



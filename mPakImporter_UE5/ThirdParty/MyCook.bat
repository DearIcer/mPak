@REM Cook Content
SET UE_EXE="UnrealEditor-Cmd.exe"
SET Project=C:\Users\hotWin\Desktop\bbbb\bbbb.uproject
SET LogFile=C:\Program Files\Epic Games\UE_5.1\Engine\Programs\AutomationTool\Saved\Cook-2022.09.19-20.44.51.txt

@REM multiparameter cook Command
@REM %UE_EXE% %Project% -run=Cook -TargetPlatform=Windows -unversioned -fileopenlog -abslog="C:\Program Files\Epic Games\UE_5.1\Engine\Programs\AutomationTool\Saved\Cook-2023.03.08-14.38.54.txt" -stdout -CrashForUAT -unattended -NoLogTimes -UTF8Output
%UE_EXE% %Project% -run=Cook -TargetPlatform=Windows -unversioned -stdout -CrashForUAT -unattended -NoLogTimes -UTF8Output


@REM Create Pie Pak Command
SET UnrealPak_EXE="UnrealPak.exe"
SET TargetPakFile="C:\Users\hotWin\Desktop\bbbb\Saved\Sandboxes\pie.pak"
SET PakSourceListFile=C:\Users\hotWin\Desktop\bbbb\Content\makePak\*
%UnrealPak_EXE% %TargetPakFile% %PakSourceListFile%


@REM Create Run Pak Command of run.pak
SET UnrealPak_EXE="UnrealPak.exe"
SET TargetPakFile="C:\Users\hotWin\Desktop\bbbb\Saved\Sandboxes\run.pak"
SET PakSourceListFile=C:\Users\hotWin\Desktop\bbbb\Saved\Cooked\Windows\bbbb\Content\makePak\*
%UnrealPak_EXE% %TargetPakFile% %PakSourceListFile%



@REM Create Run Pak Command of pie.pak
SET UnrealPak_EXE="UnrealPak.exe"
SET TargetPakFile="C:\Users\hotWin\Desktop\bbbb\Saved\Sandboxes\pie.pak"
SET PakSourceListFile=C:\Users\hotWin\Desktop\bbbb\Content\makePak\*
%UnrealPak_EXE% %TargetPakFile% %PakSourceListFile%



@REM Create mPak file
SET RunPath="C:\Users\hotWin\Desktop\bbbb\Saved\Sandboxes\run.pak"
SET PiePath="C:\Users\hotWin\Desktop\bbbb\Saved\Sandboxes\pie.pak"
SET OutPath="C:\Users\hotWin\Desktop\bbbb\Saved\Sandboxes\out.mpak"
mPakCore %RunPath% %PiePath% -output=%OutPath%

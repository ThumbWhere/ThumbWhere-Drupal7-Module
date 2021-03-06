REM Set the path to home where we have the config
REM This works with msysgit BUT ONLY IF YOU DON'T USE PUTTY!
SET HOME=\home


REM PICK YOUR GIT
if exist {"C:\Program Files (x86)\Git\bin\git.exe"} (
    SET GIT_PATH="C:\Program Files (x86)\Git\bin\git.exe"
) else (
    SET GIT_PATH="C:\Program Files\Git\bin\git.exe"
)


%GIT_PATH% config --global user.name "Build Server"
%GIT_PATH% config --global user.email "build@thumbwhere.com"


REM "C:\Program Files (x86)\Git\bin\git.exe" config --global user.name "Build Server"
REM "C:\Program Files (x86)\Git\bin\git.exe" config --global user.email "build@thumbwhere.com"

SET BUILD=0
SET STREAM=dev
SET MESSAGE=dev
SET F1=--recommended
SET F2=--supported
SET F3=--default

IF NOT (%1)==("") SET MESSAGE=%1
IF NOT ("%2")==("") SET STREAM=%2
IF NOT ("%3")==("") SET BUILD=%3
IF NOT ("%4")==("") SET F1=%4
IF NOT ("%5")==("") SET F2=%5
IF NOT ("%6")==("") SET F3=%6


ECHO "STREAM = %STREAM%"

@REM Change to the release folder
PUSHD ..\..\ThumbWhere-Drupal7-Module-Releases\release-history\

@REM Make sure we have the feed (it will fail if it already exists - can be overidden by --force).
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe new thumbwhere "ThumbWhere" ThumbWhere 7.x http://drupalmodules.thumbwhere.com/release-history/ --exitcleanonerror
IF NOT ERRORLEVEL 0 GOTO ReportError

@REM Update the release
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe add ..\..\ThumbWhere-Drupal7-Module\thumbwhere thumbwhere 7.x patch %MESSAGE% %STREAM% "" %F1% %F2% %F3%
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Create Directories
IF NOT EXIST E:\checkout mkdir E:\checkout
IF NOT ERRORLEVEL 0 GOTO ReportError

IF NOT EXIST E:\checkout\%STREAM% mkdir E:\checkout\%STREAM%
IF NOT ERRORLEVEL 0 GOTO ReportError

PUSHD E:\checkout\%STREAM%\
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Checkout if we need to
IF NOT EXIST ThumbWhere-Drupal7-Module-Releases %GIT_PATH% clone git@github.com:ThumbWhere/ThumbWhere-Drupal7-Module-Releases.git --recurse-submodules
IF NOT ERRORLEVEL 0 GOTO ReportError

POPD
IF NOT ERRORLEVEL 0 GOTO ReportError

@REM Copy changes to our local copy of the repository
xcopy /ERVY . E:\checkout\%STREAM%\ThumbWhere-Drupal7-Module-Releases\release-history\
IF NOT ERRORLEVEL 0 GOTO ReportError

POPD
IF NOT ERRORLEVEL 0 GOTO ReportError

PUSHD E:\checkout\%STREAM%\ThumbWhere-Drupal7-Module-Releases
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Make sure we are up to date
%GIT_PATH% checkout master
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Make sure we are up to date
%GIT_PATH% pull
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Add the new changes
%GIT_PATH% add .
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Add the new changes
%GIT_PATH% commit -m "Automatic commit by %STREAM% build."
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Push the new changes
%GIT_PATH% push
IF NOT ERRORLEVEL 0 GOTO ReportError

POPD
IF NOT ERRORLEVEL 0 GOTO ReportError

@goto ReportOK
:ReportError
@echo Project error: A tool returned an error code from the build event
goto ReportNotOK
:ReportOK
@echo Completed package without errors
goto Done
:ReportKindOfOK
@echo Completed package with errors that we are pretending didn't happen.
goto Done
:ReportNotOK
@echo Completed package with errors.
@exit 1
:RollBack
@echo Rollback not possible for this
:Done


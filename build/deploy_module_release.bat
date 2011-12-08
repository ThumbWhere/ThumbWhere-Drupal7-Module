SET BUILD=0
SET STREAM=dev
SET MESSAGE=dev

IF NOT (%1)==("") SET MESSAGE=%1
IF NOT (%2)==("") SET STREAM=%2
IF NOT (%3)==("") SET BUILD=%3


@REM Change to the release folder
PUSHD ..\..\ThumbWhere-Drupal7-Module-Releases\release-history\

@REM Make sure we have the feed (it will fail if it already exists - can be overidden by --force).
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe new ThumbWhere ThumbWhere 7.x http://drupalmodules.thumbwhere.com/release-history/ --exitcleanonerror
IF NOT ERRORLEVEL 0 GOTO ReportError

@REM Update the release
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe add ..\..\ThumbWhere-Drupal7-Module\ThumbWhere ThumbWhere 7.x patch %MESSAGE% %STREAM% %BUILD% %4 %5 %6
IF NOT ERRORLEVEL 0 GOTO ReportError

@REM Copy changes to our local copy of the repository
xcopy /ERVY . E:\checkout\ThumbWhere-Drupal7-Module-Releases\release-history\
IF NOT ERRORLEVEL 0 GOTO ReportError

POPD

@REM Commit them

PUSHD E:\checkout\ThumbWhere-Drupal7-Module-Releases

REM Set the path to home where we have the config
SET HOME=\home

REM Make sure we are up to date
"C:\Program Files\Git\bin\git.exe" pull
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Add the new changes
"C:\Program Files\Git\bin\git.exe" add .
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Add the new changes
"C:\Program Files\Git\bin\git.exe" commit -m "Automatic commit by %STREAM% build %1."
IF NOT ERRORLEVEL 0 GOTO ReportError

REM Push the new changes
"C:\Program Files\Git\bin\git.exe" push
IF NOT ERRORLEVEL 0 GOTO ReportError

POPD

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


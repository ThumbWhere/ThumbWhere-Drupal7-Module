@REM ***NOTE*** - no \ on end of DRUPALROOT
IF ("%DRUPALROOT%")==("") SET DRUPALROOT=%USERPROFILE%\sites\acquia-drupal


@REM ***NOTE*** - no \ on end of DRUPALROOT
IF ("%THUMBWHERE_MODULEROOT%")==("") SET THUMBWHERE_MODULEROOT=E:\Inetpub\wwwroot\ThumbWhere-Drupal7-Module


PUSHD ..
IF NOT ERRORLEVEL 0 GOTO ReportError

IF NOT EXIST %DRUPALROOT%\sites\default\modules mkdir %DRUPALROOT%\sites\default\modules
IF NOT ERRORLEVEL 0 GOTO ReportError

rmdir /Q /S %DRUPALROOT%\sites\default\modules\thumbwhere
IF NOT ERRORLEVEL 0 GOTO ReportError

tools\junction.exe %DRUPALROOT%\sites\default\modules\thumbwhere %THUMBWHERE_MODULEROOT%\thumbwhere
IF NOT ERRORLEVEL 0 GOTO ReportError

POPD
IF NOT ERRORLEVEL 0 GOTO ReportError

@goto ReportOK
:ReportError
@echo Error error: A tool returned an error code from the build event
IF NOT ("%2")==("non-interactive") @CHOICE /C:SC /M "Press S to Stop and C to Continue (Not recommended)."
@if errorlevel 1 goto ReportNotOK
@if errorlevel 2 goto ReportKindOfOK
goto Done
:ReportOK
@echo Completed package without errors
goto Done
:ReportKindOfOK
@echo Completed package with errors that we are pretending didn't happen.
goto Done
:ReportNotOK
@echo Completed package with errors.
POPD
@exit 1
:RollBack
@echo Rollback not possible for this
:Done


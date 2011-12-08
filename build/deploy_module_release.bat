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

@REM Update the release
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe add ..\..\ThumbWhere-Drupal7-Module\ThumbWhere ThumbWhere 7.x patch %MESSAGE% %STREAM% %BUILD% %4 %5 %6

@REM Copy changes to our local copy of the repository
xcopy /ERVY . E:\checkout\ThumbWhere-Drupal7-Module-Releases\release-history\

POPD

@REM Commit them

PUSHD E:\checkout\ThumbWhere-Drupal7-Module-Releases

REM Set the path to home where we have the config
SET HOME=\home

REM Make sure we are up to date
"C:\Program Files\Git\bin\git.exe" pull

REM Add the new changes
"C:\Program Files\Git\bin\git.exe" add .

REM Add the new changes
"C:\Program Files\Git\bin\git.exe" commit -m "Automatic commit by %STREAM% build %1."

REM Push the new changes
"C:\Program Files\Git\bin\git.exe" push

POPD

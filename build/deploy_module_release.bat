REM Set the path to home where we have the config
SET HOME=\home

@REM Change to the release folder
PUSHD E:\checkout\ThumbWhere-Drupal7-Module-Releases\release-history\

REM -----------------------------------
REM Build package
REM -----------------------------------

@REM Make sure we have the feed (it will fail if it already exists - can be overidden by --force).

E:\inetpub\wwwroot\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe new ThumbWhere ThumbWhere 7.x http://drupalmodules.thumbwhere.com/release-history/ --exitcleanonerror

@REM Update the release
E:\inetpub\wwwroot\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe add E:\inetpub\wwwroot\ThumbWhere-Drupal7-Module\ThumbWhere ThumbWhere 7.x patch "Bug Fixes" dev %1 --recommended --supported --default

REM -----------------------------------
REM Now we update the local respository
REM -----------------------------------

REM Make sure we are up to date
"C:\Program Files\Git\bin\git.exe" pull

REM Add the new changes
"C:\Program Files\Git\bin\git.exe" add .

REM Add the new changes
"C:\Program Files\Git\bin\git.exe" commit -m "Automatic commit by build %1."

REM Push the new changes
"C:\Program Files\Git\bin\git.exe" push

POPD

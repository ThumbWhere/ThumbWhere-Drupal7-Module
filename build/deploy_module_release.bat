@REM Change to the release folder
PUSHD ..\..\ThumbWhere-Drupal7-Module-Releases\release-history\

@REM Make sure we have the feed (it will fail if it already exists - can be overidden by --force).

..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe new ThumbWhere ThumbWhere 7.x http://drupalmodules.thumbwhere.com/release-history/ --exitcleanonerror

@REM Update the release
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe add ..\..\ThumbWhere-Drupal7-Module\ThumbWhere ThumbWhere 7.x patch "Bug Fixes" dev %1 --recommended --supported --default

@REM Copy changes to our local copy of the repository
xcopy /ERVY . E:\checkout\ThumbWhere-Drupal7-Module-Releases\release-history\

POPD

@REM Commit them

PUSHD E:\checkout\ThumbWhere-Drupal7-Module-Releases

REM Push the new changes
git commit -a -m "Automatic commit by build %1."

REM Push them to the server
git push

POPD

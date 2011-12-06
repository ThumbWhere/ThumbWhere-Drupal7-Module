@REM Change to the release folder
PUSHD ..\..\ThumbWhere-Drupal7-Module-Releases\release-history\
@REM Make sure we have the feed (it will fail if it already exists - can be overidden by --force).
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe new ThumbWhere ThumbWhere 7.x http://drupalmodules.thumbwhere.com/release-history/ --exitcleanonerror
@REM Update the release
..\..\ThumbWhere-Drupal7-Module\tools\DrupalUtil.exe add ..\..\ThumbWhere-Drupal7-Module\ThumbWhere ThumbWhere 7.x patch "Bug Fixes" dev %1 --recommended --supported --default
POPD
@REM Copy changes to our local copy of the repository
xcopy /ERVY release-history E:\checkout\ThumbWhere-Drupal7-Module\release-history\

@REM Commit them
PUSHD E:\checkout\ThumbWhere-Drupal7-Module
git commit -a -m "New changes"
POPD

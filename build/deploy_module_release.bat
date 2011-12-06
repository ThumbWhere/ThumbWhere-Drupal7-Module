REM Change to the release folder
PUSHD ..\..\ThumbWhere-Drupal7-Module-Releases\release-history\

REM Make sure we have the feed (it will fail if it already exists - can be overidden by --force).
..\tools\DrupalUtil.exe new ThumbWhere ThumbWhere 7.x http://drupalmodules.thumbwhere.com/release-history/ --exitclean

REM Update the release
..\tools\DrupalUtil.exe add ..\..\ThumbWhere-Drupal7-Module\ThumbWhere ThumbWhere 7.x patch --recommended --supported --default
POPD

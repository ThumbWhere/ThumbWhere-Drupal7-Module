PUSHD ..
rmdir /Q /S %USERPROFILE%\sites\acquia-drupal\sites\default\modules\ThumbWhere
junction.exe %USERPROFILE%\sites\acquia-drupal\sites\default\modules\ThumbWhere ThumbWhere
POPD

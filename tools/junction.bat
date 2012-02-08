PUSHD ..
rmdir /Q /S %USERPROFILE%\sites\acquia-drupal\sites\default\modules\thumbwhere
tools\junction.exe %USERPROFILE%\sites\acquia-drupal\sites\default\modules\thumbwhere thumbwhere
POPD

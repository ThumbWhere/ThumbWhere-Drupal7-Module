PUSHD ..
mkdir %USERPROFILE%\sites\acquia-drupal\sites\default\modules\
rmdir /Q /S %USERPROFILE%\sites\acquia-drupal\sites\default\modules\thumbwhere
junction.exe %USERPROFILE%\sites\acquia-drupal\sites\default\modules\thumbwhere thumbwhere
POPD

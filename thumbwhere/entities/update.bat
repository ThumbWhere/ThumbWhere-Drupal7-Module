PUSHD \Inetpub\wwwroot\3520_ThumbWhereMediaServer
CALL autogen_model_implementation_drupal.bat
POPD
xcopy /ERVY ..\..\..\3520_ThumbWhereMediaServer\integrations\drupal\thumbwhere\entities .
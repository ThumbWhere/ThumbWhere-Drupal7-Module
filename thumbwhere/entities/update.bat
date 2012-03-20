PUSHD \Inetpub\wwwroot\3520_ThumbWhereMediaServer
CALL autogen_model_implementation_drupal.bat
CALL autogen_services_client_code.bat
POPD
xcopy /ERVY ..\..\..\3520_ThumbWhereMediaServer\integrations\drupal\thumbwhere\entities .
xcopy /ERVY ..\..\..\3520_ThumbWhereMediaServer\integrations\drupal\thumbwhere\dependencies\tw\services ..\dependencies\tw\services\
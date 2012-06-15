PUSHD \Inetpub\wwwroot\3520_ThumbWhereMediaServer
ECHO Generate Implementation
CALL autogen_model_implementation_drupal.bat
ECHO Generate Services Code
CALL autogen_services_client_code.bat
POPD
robocopy /E ..\..\..\3520_ThumbWhereMediaServer\integrations\drupal\thumbwhere\entities .
robocopy /E ..\..\..\3520_ThumbWhereMediaServer\integrations\drupal\thumbwhere\dependencies\tw\services ..\dependencies\tw\services\
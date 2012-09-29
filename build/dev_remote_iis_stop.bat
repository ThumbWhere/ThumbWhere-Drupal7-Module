:WaitingToBeStable

@for /F "tokens=3 delims=: " %%H in ('C:\windows\system32\sc \\unearthed query "W3SVC" ^| C:\windows\system32\findstr "        STATE"') do @(
  
  @echo "Current IIS status is '%%H'"
  
  @if /I "%%H" EQU "STOP_PENDING" (
   echo "STOP_PENDING"
   C:\windows\system32\ping 127.0.0.1 -n 2 -w 1000 > nul
   goto :WaitingToBeStable
  )
  @if /I "%%H" EQU "START_PENDING" (
    echo "START_PENDING"
	C:\windows\system32\ping 127.0.0.1 -n 2 -w 1000 > nul
   goto :WaitingToBeStable
  )
  @if /I "%%H" EQU "RUNNING" (
   C:\windows\system32\sc \\unearthed stop W3SVC
  )
)



:WaitingToBeStopped
@for /F "tokens=3 delims=: " %%H in ('C:\windows\system32\sc \\unearthed query "W3SVC" ^| C:\windows\system32\findstr "        STATE"') do @(
  
  @echo "Current IIS status is '%%H'"
  
  @if /I "%%H" NEQ "STOPPED" (
   echo "NOT STOPPED"
   C:\windows\system32\ping 127.0.0.1 -n 2 -w 1000 > nul
   goto :WaitingToBeStopped
  )
)


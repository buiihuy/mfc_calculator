# Path to my calculator
$myCalculatorPath = "D:\CODE\CYSTACK\WEEK3\Calculator\x64\Release\Calculator.exe"

# Check my calculator is exist or not
if (Test-Path $myCalculatorPath) {
    # Path to System32
    $system32Folder = [System.Environment]::SystemDirectory

    # Path to default calc.exe in System32
    $systemCalcPath = Join-Path -Path $system32Folder -ChildPath "calc.exe"

    # Rename win11 calculator
    Rename-Item -Path $systemCalcPath -NewName "calc_10h37.exe"

    # Copy my calculator into System32 and rename
    Copy-Item -Path $myCalculatorPath -Destination $systemCalcPath

    # Run cacl.exe
    Start-Process calc
} 
else {
    Write-Host "No such file or directory."
}

#-------------------------------------------------------------------------------------------#

# Path to startup folder
$startupFolderPath = [System.Environment]::GetFolderPath("Startup")

# Path to target file in Startup
$targetFilePath = Join-Path -Path $startupFolderPath -ChildPath "myCalculator.lnk"

# Creat an LNK file point to 
$WshShell = New-Object -ComObject WScript.Shell
$shortcut = $WshShell.CreateShortcut($targetFilePath)
$shortcut.TargetPath = $myCalculatorPath
$shortcut.WindowStyle = 7  # Hidden
$shortcut.Save()
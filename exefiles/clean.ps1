if($pwd.Path -ne "C:\Users\saton\projects\ccpp"){
    Set-Location "C:\Users\saton\projects\ccpp"
}

$exefiles = (Get-ChildItem -Path .\exefiles\* -Include "*.exe" -Name)

foreach ($exefile in $exefiles) {
    Remove-Item .\exefiles\$exefile
}
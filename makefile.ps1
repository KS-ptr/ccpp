if ($args.Count -ne 2 -and $args.Count -ne 3) {
    Write-Output "Wrong Length of Args (2 or 3)."
    exit
}

function MakeFile ($dir, $filename, $ext) {
    $full_filename = $filename + $ext
    New-Item C:\Users\saton\projects\ccpp\$dir\$full_filename
    if ($ext -eq ".cpp") {
        Set-Content -Path C:\Users\saton\projects\ccpp\$dir\$full_filename "#include<iostream>"
        Add-Content -Path C:\Users\saton\projects\ccpp\$dir\$full_filename "using namespace std;"
    }
}

if ($args.Count -eq 2) {
    $dir = $args[0]
    $filename = $args[1]
    $ext = ".cpp"
    MakeFile $dir $filename $ext
}

if ($args.Count -eq 3) {
    $dir = $args[0]
    $filename = $args[1]
    $ext = $args[2]
    MakeFile $dir $filename $ext
}
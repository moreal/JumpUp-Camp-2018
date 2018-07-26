param (
    [string] $filename,
    [string] $workspace
)

Set-Location $workspace

''

if (-not (Test-Path -Path ./bin/)) {
    New-Item -Type Directory -Name ./bin/
}

"[+] Compile $workspace/$filename"
"[+] Execute Binary"

''

$env:LC_ALL='C.UTF-8'

g++ -o ./bin/test.exe $filename -std=c++17 -w

"[!] Program was executed"

''

./bin/test.exe

''
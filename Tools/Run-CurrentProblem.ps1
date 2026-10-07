[CmdletBinding()]
param(
    [ValidateSet("Debug", "Release")]
    [string]$Configuration = "Debug",
    [string]$Problem,
    [switch]$SkipBuild
)

$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot

if (-not $Problem) {
    $latest = Get-ChildItem -Path (Join-Path $root "코딩테스트") -Filter *.cpp |
        Sort-Object LastWriteTime -Descending |
        Select-Object -First 1
    if (-not $latest) {
        throw "No problem source found in 코딩테스트/."
    }
    $Problem = [System.IO.Path]::GetFileNameWithoutExtension($latest.Name)
}

if (-not $SkipBuild) {
    & (Join-Path $PSScriptRoot "Build.ps1") -Configuration $Configuration
    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

$executable = Join-Path $root "out\build\vs2026\$Configuration\$Problem.exe"
if (-not (Test-Path -LiteralPath $executable)) {
    throw "Executable not found: $executable (did the build include 코딩테스트/$Problem.cpp?)"
}

Write-Output "Running problem: $Problem ($Configuration)"
$output = & $executable 2>&1
$exitCode = $LASTEXITCODE
$output | ForEach-Object { Write-Output $_ }

if ($exitCode -ne 0) {
    exit $exitCode
}

$text = $output -join [Environment]::NewLine
if ($text -match "\bFAIL\b") {
    Write-Error "One or more local cases failed."
    exit 1
}

if ($text -notmatch "\bPASS\b") {
    Write-Error "No PASS marker was emitted by the local harness."
    exit 2
}

Write-Output "All local cases passed."

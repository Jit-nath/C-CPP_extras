# Step 1: List all .exe files in the current directory and subdirectories
Write-Host "The following .exe files are found:" -ForegroundColor Cyan
Get-ChildItem -Recurse -Filter *.exe | ForEach-Object {
    Write-Host $_.Name
}

# Step 2: Ask for confirmation before proceeding with deletion
$confirmation = Read-Host "Do you want to proceed with deleting all .exe files listed above? (yes/no)"

if ($confirmation -eq 'yes') {
    # Step 3: Delete the .exe files
    Get-ChildItem -Recurse -Filter *.exe | ForEach-Object {
        Remove-Item $_.FullName -Force
        Write-Host "Deleted: $($_.Name)" -ForegroundColor Yellow
    }
    Write-Host "All .exe files have been deleted." -ForegroundColor Green
} else {
    Write-Host "Operation canceled. No files were deleted." -ForegroundColor Red
}

@echo off

del log.txt

"C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" OJ_Prj.sln /build "Debug|Win32" /Out log.txt

type log.txt
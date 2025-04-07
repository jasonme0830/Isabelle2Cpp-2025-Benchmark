# Benchmarks-Isabelle2Cpp
To benchmark C++ codes that generated from Isabelle2Cpp.

The files c_peter, imp, sml, llvm are download from https://github.com/lammich/isabelle_llvm.git,
which created by peter lammich.

All the operations are displayed in the makefile.

benchmark-Isabelle2Cpp
    |--fib
        |--llvm  (generated from Isabelle-llvm)

        |--before  (generated from Isabelle2Cpp)

        |--after  (generated from optimized Isabelle2Cpp)
        
    |--bs

        |--c_peter  (copy from peter lammich)
    
        |--cpp

        |--imp  (copy from peter lammich)

        |--sml  (copy from peter lammich)

        |--llvm  (copy from peter lammich) 

    |--go
        --go.mod
        |--AddListHead
            --exported.go
        |--List
            --exported.go
        --main.go

This message is for second reclone code.

vscode settings
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++-11",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
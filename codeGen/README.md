tested on nickel.cs.pitt.edu


## Generating code
`
make codeGen
`
or (on 64-bit system)
`
make codeGen64
`

## generating code
`
./myCodeGen < test/src1
`

## generate reference code
`
chmod +x codeGen.linux
./codeGen.linux < test/src1
`

## testing code
`
chmod +x spim.linux
./spim.linux -file mycode.s
`

## notes
`
do not delete the lex.yy.c
the code was written using a flex version that produces slightly different output than the one on oxygen.cs.pitt.edu,
the lex.yy.c generated on oxygen.cs.pitt.edu is incompatible with the rest of the code
`
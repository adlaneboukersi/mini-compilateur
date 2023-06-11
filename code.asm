TITLE ID01
DATA segment
  $temps DW 100 dup(?)
  tab1 DW 5 dup(?)
  f DW ?
  var3 DW ?
  var4 DW ?
  cst1 DB 100 dup(?)
  var5 DW ?
  cst2 DB ?
  var1 DW ?
  var2 DW ?
DATA ends
CODE segment
  ASSUME: CS:CODE,DS:DATA
  MAIN:
  MOV [cst2],'a'
  MOV AX,5
  MOV DX,0
  MOV BX,1
  IMUL BX
  MOV [$temps+0],AX
  MOV AX,5
  MOV DX,0
  MOV BX,1
  IMUL BX
  MOV [$temps+1],AX
  MOV AX,[$temps+0]
  ADD AX,[$temps+1]
  MOV [$temps+2],AX
  MOV AX,WORD PTR [$temps+2]
  MOV WORD PTR [var1],AX
  MOV AH,2
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AX,[var1]
  CMP AX, 0
  JGE $EtiqOut0
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut0:
  MOV BX,10
  MOV CX,0
  $EtiqOut1:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut1
  $EtiqOut2:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut2
  MOV AX,2
  SUB AX,7
  MOV [$temps+3],AX
  MOV AX,5
  MOV DX,0
  MOV BX,1
  IMUL BX
  MOV [$temps+4],AX
  MOV AX,[$temps+4]
  MOV DX,0
  MOV BX,8
  IMUL BX
  MOV [$temps+5],AX
  MOV AX,[$temps+5]
  MOV DX,0
  MOV BX,3
  IMUL BX
  MOV [$temps+6],AX
  MOV AX,[$temps+3]
  MOV DX,0
  MOV BX,[$temps+6]
  IMUL BX
  MOV [$temps+7],AX
  MOV AX,WORD PTR [$temps+7]
  MOV WORD PTR [var1],AX
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AX,[var1]
  CMP AX, 0
  JGE $EtiqOut3
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut3:
  MOV BX,10
  MOV CX,0
  $EtiqOut4:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut4
  $EtiqOut5:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut5
  MOV AX,5
  ADD AX,1
  MOV [$temps+8],AX
  MOV AX,[$temps+8]
  SUB AX,1
  MOV [$temps+9],AX
  MOV AX,WORD PTR [$temps+9]
  MOV WORD PTR [var1],AX
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AX,[var1]
  CMP AX, 0
  JGE $EtiqOut6
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut6:
  MOV BX,10
  MOV CX,0
  $EtiqOut7:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut7
  $EtiqOut8:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut8
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'d'
  INT 21H
  MOV DL,'o'
  INT 21H
  MOV DL,'n'
  INT 21H
  MOV DL,'n'
  INT 21H
  MOV DL,'e'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'2'
  INT 21H
  MOV DL,':'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV DX,0
  MOV CL,10
  MOV CH,0
  MOV BX,0
  $EtiqIn0:
  MOV AH,1
  INT 21h
  CMP AL,13
  JZ $EtiqIn1
  CMP AL,'-'
  JZ $EtiqIn2
  SUB AL,'0'
  MOV BL,AL
  MOV AX,DX
  MUL CL

  ADD AX,BX
  MOV DX,AX
  JMP $EtiqIn0
  $EtiqIn2:
  MOV CH,1
  JMP $EtiqIn0
  $EtiqIn1:
  CMP CH,0
  JZ $EtiqIn3
  NEG DX
  $EtiqIn3:
  MOV [var2],DX 
  MOV DL,10
  CMP AX, 0
  MOV AH,2
  INT 21H
  MOV DL,13
  MOV AH,2
  INT 21H
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'2'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AX,[var2]
  CMP AX, 0
  JGE $EtiqOut9
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut9:
  MOV BX,10
  MOV CX,0
  $EtiqOut10:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut10
  $EtiqOut11:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut11
  MOV AX,WORD PTR [var1]
  CMP AX,WORD PTR [var2]
  JGE $Etiq23
  MOV [$temps+10],0
  JMP $Etiq24
  $Etiq23:
  MOV [$temps+10],1
  $Etiq24:
  MOV AX,1
  CMP AX,0
  JZ $Etiq28
  MOV AX,WORD PTR [$temps+10]
  CMP AX,0
  JZ $Etiq28
  MOV [$temps+11],1
  JMP $Etiq29
  $Etiq28:
  MOV [$temps+11],0
  $Etiq29:
  MOV AX,WORD PTR [$temps+11]
  CMP AX,0
  JZ $Etiq32
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'t'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'u'
  INT 21H
  MOV DL,'e'
  INT 21H
  JMP $Etiq33
  $Etiq32:
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'f'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'l'
  INT 21H
  MOV DL,'s'
  INT 21H
  MOV DL,'e'
  INT 21H
  $Etiq33:
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'d'
  INT 21H
  MOV DL,'o'
  INT 21H
  MOV DL,'n'
  INT 21H
  MOV DL,'n'
  INT 21H
  MOV DL,'e'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV DL,'c'
  INT 21H
  MOV DL,'s'
  INT 21H
  MOV DL,'t'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,':'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV SI,0
  $EtiqIn4:
  MOV AH,1
  INT 21h
  CMP AL,13
JZ $EtiqIn5
  MOV cst1[SI],AL
  INC SI
  JMP $EtiqIn4
  $EtiqIn5:
  MOV cst1[SI],'$'
  MOV DL,10
  CMP AX, 0
  MOV AH,2
  INT 21H
  MOV DL,13
  MOV AH,2
  INT 21H
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'c'
  INT 21H
  MOV DL,'s'
  INT 21H
  MOV DL,'t'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AH,9
  MOV DX,OFFSET [cst1]
  INT 21H
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'c'
  INT 21H
  MOV DL,'s'
  INT 21H
  MOV DL,'t'
  INT 21H
  MOV DL,'2'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AH,2
  MOV DX,WORD PTR [cst2]
  INT 21H
  $Etiq37:
  MOV AX,[var1]
  ADD AX,1
  MOV [$temps+12],AX
  MOV AX,WORD PTR [$temps+12]
  MOV WORD PTR [var1],AX
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AX,[var1]
  CMP AX, 0
  JGE $EtiqOut12
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut12:
  MOV BX,10
  MOV CX,0
  $EtiqOut13:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut13
  $EtiqOut14:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut14
  MOV AX,WORD PTR [var1]
  CMP AX,WORD PTR [var2]
  JNZ $Etiq43
  MOV [$temps+13],0
  JMP $Etiq44
  $Etiq43:
  MOV [$temps+13],1
  $Etiq44:
  MOV AX,WORD PTR [$temps+13]
  CMP AX,0
  JNZ $Etiq37
  MOV [var1],1
  $Etiq46:
  MOV AX,WORD PTR [var1]
  CMP AX,10
  JG $Etiq63
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV DL,' '
  INT 21H
  MOV AX,[var1]
  CMP AX, 0
  JGE $EtiqOut15
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut15:
  MOV BX,10
  MOV CX,0
  $EtiqOut16:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut16
  $EtiqOut17:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut17
  MOV AX,WORD PTR [var1]
  CMP AX,5
  JL $Etiq51
  MOV [$temps+14],0
  JMP $Etiq52
  $Etiq51:
  MOV [$temps+14],1
  $Etiq52:
  MOV AX,WORD PTR [$temps+14]
  CMP AX,0
  JZ $Etiq60
  MOV [var5],1
  $Etiq54:
  MOV AX,WORD PTR [var5]
  CMP AX,3
  JG $Etiq59
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,34
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'5'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV DL,'e'
  INT 21H
  MOV DL,'s'
  INT 21H
  MOV DL,'t'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV DL,'i'
  INT 21H
  MOV DL,'n'
  INT 21H
  MOV DL,'f'
  INT 21H
  MOV DL,'e'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'i'
  INT 21H
  MOV DL,'e'
  INT 21H
  MOV DL,'u'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'e'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV DL,'d'
  INT 21H
  MOV DL,'e'
  INT 21H
  MOV DL,' '
  INT 21H
  MOV DL,'5'
  INT 21H
  MOV DL,34
  INT 21H
  MOV AX,[var5]
  ADD AX,1
  MOV [$temps+15],AX
  MOV AX,WORD PTR [$temps+15]
  MOV WORD PTR [var5],AX
  JMP $Etiq54
  $Etiq59:
  JMP $Etiq60
  $Etiq60:
  MOV AX,[var1]
  ADD AX,1
  MOV [$temps+16],AX
  MOV AX,WORD PTR [$temps+16]
  MOV WORD PTR [var1],AX
  JMP $Etiq46
  $Etiq63:
  MOV AX,WORD PTR [var1]
  MOV WORD PTR [tab1+0],AX
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'t'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'b'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'['
  INT 21H
  MOV DL,'0'
  INT 21H
  MOV DL,']'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV AX,[tab1+0]
  CMP AX, 0
  JGE $EtiqOut18
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut18:
  MOV BX,10
  MOV CX,0
  $EtiqOut19:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut19
  $EtiqOut20:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut20
  MOV AX,[tab1+0]
  ADD AX,5
  MOV [$temps+17],AX
  MOV AX,WORD PTR [$temps+17]
  MOV WORD PTR [tab1+1],AX
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'t'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'b'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'['
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,']'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV AX,[tab1+1]
  CMP AX, 0
  JGE $EtiqOut21
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut21:
  MOV BX,10
  MOV CX,0
  $EtiqOut22:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut22
  $EtiqOut23:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut23
  MOV AX,3
  MOV DX,0
  MOV BX,2
  IMUL BX
  MOV [$temps+18],AX
  MOV AX,[$temps+18]
  ADD AX,1
  MOV [$temps+19],AX
  MOV AX,WORD PTR [$temps+19]
  MOV WORD PTR [var1],AX
  MOV AX,3
  MOV DX,0
  MOV BX,2
  IMUL BX
  MOV [$temps+20],AX
  MOV AX,[$temps+20]
  ADD AX,1
  MOV [$temps+21],AX
  MOV AX,WORD PTR [$temps+21]
  MOV WORD PTR [var2],AX
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'1'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV AX,[var1]
  CMP AX, 0
  JGE $EtiqOut24
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut24:
  MOV BX,10
  MOV CX,0
  $EtiqOut25:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut25
  $EtiqOut26:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut26
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'2'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV AX,[var2]
  CMP AX, 0
  JGE $EtiqOut27
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut27:
  MOV BX,10
  MOV CX,0
  $EtiqOut28:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut28
  $EtiqOut29:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut29
  MOV AX,[var1]
  SUB AX,1
  MOV [$temps+22],AX
  MOV AX,WORD PTR [$temps+22]
  MOV WORD PTR [var1],AX
  MOV AX,[var1]
  MOV DX,0
  MOV BX,2
  IMUL BX
  MOV [$temps+23],AX
  MOV AX,WORD PTR [$temps+23]
  MOV WORD PTR [var3],AX
  MOV AX,[var3]
  ADD AX,7
  MOV [$temps+24],AX
  MOV AX,WORD PTR [$temps+24]
  MOV WORD PTR [var4],AX
  MOV AH,2
  MOV DL,10
  INT 21H
  MOV DL,13
  INT 21H
  MOV DL,'v'
  INT 21H
  MOV DL,'a'
  INT 21H
  MOV DL,'r'
  INT 21H
  MOV DL,'4'
  INT 21H
  MOV DL,'='
  INT 21H
  MOV AX,[var4]
  CMP AX, 0
  JGE $EtiqOut30
  MOV BX,AX
  MOV DL,'-'
  MOV AH,2
  INT 21H
  MOV AX,BX
  NEG AX
  $EtiqOut30:
  MOV BX,10
  MOV CX,0
  $EtiqOut31:
  MOV DX,0
  DIV BX
  ADD DX,'0'
  PUSH DX
  INC CX
  CMP AX,0
  JNZ $EtiqOut31
  $EtiqOut32:
  POP DX
  MOV AH,2
  INT 21H
  DEC CX
  CMP CX,0
  JNZ $EtiqOut32
CODE ends
END MAIN
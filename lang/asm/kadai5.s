# ------ [ Symbols ] ------
# 	symbol_0 	size: 16 	offset:     0(0) 	[matrix1]
# 	symbol_1 	size: 16 	offset:  0x10(16) 	[matrix2]
# 	symbol_2 	size: 16 	offset:  0x20(32) 	[matrix3]
# 	symbol_3 	size: 4 	offset:  0x30(48) 	[i]
# 	symbol_4 	size: 4 	offset:  0x34(52) 	[j]
# 	symbol_5 	size: 4 	offset:  0x38(56) 	[k]
# -------------------------
 INITIAL_GP = 0x10008000 # initial value of global pointer
 INITIAL_SP = 0x7ffffffc # initial value of stack pointer
# system call service number
 stop_service = 99

 .text # テキストセグメントの開始
init:
 # initialize $gp (global pointer) and $sp (stack pointer)
 la $gp, INITIAL_GP # $gp ←0x10008000 (INITIAL_GP)
 la $sp, INITIAL_SP # $sp ←0x7ffffffc (INITIAL_SP)
 jal main # jump to 'main'
 nop # (delay slot)
 li $v0, stop_service # $v0 <-99 (stop_service)
 syscall # stop
 nop
 # not reach here
stop: # if syscall return
 j stop # infinite loop...
 nop # (delay slot)

 .text 0x00001000 # 以降のコードを 0から配置 x00001000
main:
 la $t0, RESULT # $t0 <-0x10004000
  li $v0, 1
  # assignment [matrix1] <- imm (1)
  # clac array offset of [matrix1]
  # keep imm val (0) to stack
  li $t2, 0
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (0) to stack
  li $t3, 0
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 0  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 2
  # assignment [matrix1] <- imm (2)
  # clac array offset of [matrix1]
  # keep imm val (1) to stack
  li $t2, 1
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (0) to stack
  li $t3, 0
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 0  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 3
  # assignment [matrix1] <- imm (3)
  # clac array offset of [matrix1]
  # keep imm val (0) to stack
  li $t2, 0
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (1) to stack
  li $t3, 1
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 0  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 4
  # assignment [matrix1] <- imm (4)
  # clac array offset of [matrix1]
  # keep imm val (1) to stack
  li $t2, 1
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (1) to stack
  li $t3, 1
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 0  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 5
  # assignment [matrix2] <- imm (5)
  # clac array offset of [matrix2]
  # keep imm val (0) to stack
  li $t2, 0
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (0) to stack
  li $t3, 0
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 16  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 6
  # assignment [matrix2] <- imm (6)
  # clac array offset of [matrix2]
  # keep imm val (1) to stack
  li $t2, 1
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (0) to stack
  li $t3, 0
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 16  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 7
  # assignment [matrix2] <- imm (7)
  # clac array offset of [matrix2]
  # keep imm val (0) to stack
  li $t2, 0
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (1) to stack
  li $t3, 1
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 16  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 8
  # assignment [matrix2] <- imm (8)
  # clac array offset of [matrix2]
  # keep imm val (1) to stack
  li $t2, 1
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep imm val (1) to stack
  li $t3, 1
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 16  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  li $v0, 0
  # assignment [i] <- imm (0)
  sw $v0, 48($t0)
  nop
$FOR0:
  # keep val (i) to stack
  lw $t2, 48($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (2) to stack
  li $t3, 2
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDFOR0
  nop
  li $v0, 0
  # assignment [j] <- imm (0)
  sw $v0, 52($t0)
  nop
$FOR1:
  # keep val (j) to stack
  lw $t2, 52($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (2) to stack
  li $t3, 2
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDFOR1
  nop
  li $v0, 0
  # assignment [matrix3] <- imm (0)
  # clac array offset of [matrix3]
  # keep val (j) to stack
  lw $t2, 52($t0)
  nop
  sw $t2, 4($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep val (i) to stack
  lw $t3, 48($t0)
  nop
  sw $t3, 4($sp)
  nop
  # pop stack
  lw $t3, 4($sp)
  nop
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 32  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  # keep val (j) to stack
  lw $v0, 52($t0)
  nop
  # unary operation
  addi $v0, $v0, 1
  sw $v0, 52($t0)
  nop
  j $FOR1
  nop
$ENDFOR1:
  # keep val (i) to stack
  lw $v0, 48($t0)
  nop
  # unary operation
  addi $v0, $v0, 1
  sw $v0, 48($t0)
  nop
  j $FOR0
  nop
$ENDFOR0:
  li $v0, 0
  # assignment [i] <- imm (0)
  sw $v0, 48($t0)
  nop
$FOR2:
  # keep val (i) to stack
  lw $t2, 48($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (2) to stack
  li $t3, 2
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDFOR2
  nop
  li $v0, 0
  # assignment [j] <- imm (0)
  sw $v0, 52($t0)
  nop
$FOR3:
  # keep val (j) to stack
  lw $t2, 52($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (2) to stack
  li $t3, 2
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDFOR3
  nop
  li $v0, 0
  # assignment [k] <- imm (0)
  sw $v0, 56($t0)
  nop
$FOR4:
  # keep val (k) to stack
  lw $t2, 56($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (2) to stack
  li $t3, 2
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDFOR4
  nop
  # clac array offset of [matrix3]
  # keep val (j) to stack
  lw $t2, 52($t0)
  nop
  sw $t2, 4($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep val (i) to stack
  lw $t3, 48($t0)
  nop
  sw $t3, 4($sp)
  nop
  # pop stack
  lw $t3, 4($sp)
  nop
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 32  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  # keep element of array(matrix3) to stack
  lw $t2, 0($t2)
  nop
  sw $t2, 4($sp)
  nop
  # clac array offset of [matrix1]
  # keep val (k) to stack
  lw $t2, 56($t0)
  nop
  sw $t2, 8($sp)
  nop
  # pop stack
  lw $t2, 8($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep val (i) to stack
  lw $t3, 48($t0)
  nop
  sw $t3, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 0  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  # keep element of array(matrix1) to stack
  lw $t2, 0($t2)
  nop
  sw $t2, 8($sp)
  nop
  # clac array offset of [matrix2]
  # keep val (j) to stack
  lw $t2, 52($t0)
  nop
  sw $t2, 12($sp)
  nop
  # pop stack
  lw $t2, 12($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep val (k) to stack
  lw $t3, 56($t0)
  nop
  sw $t3, 12($sp)
  nop
  # pop stack
  lw $t3, 12($sp)
  nop
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 16  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t3, $t0, $t2
  # array offset -> [$t3]
  # keep element of array(matrix2) to stack
  lw $t3, 0($t3)
  nop
  sw $t3, 12($sp)
  nop
  # pop stack
  lw $t3, 12($sp)
  nop
  # pop stack
  lw $t2, 8($sp)
  nop
  # mul exp
  mult $t2, $t3
  mflo $v0
  sw $v0, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [matrix3] <- exp val
  # clac array offset of [matrix3]
  # keep val (j) to stack
  lw $t2, 52($t0)
  nop
  sw $t2, 8($sp)
  nop
  # pop stack
  lw $t2, 8($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # keep val (i) to stack
  lw $t3, 48($t0)
  nop
  sw $t3, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  li $t4, 8  # mul exp
  mult $t3, $t4
  mflo $t3
  # add exp
  add $t2, $t2, $t3
  li $t3, 32  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 0($t2)
  nop
  # keep val (k) to stack
  lw $v0, 56($t0)
  nop
  # unary operation
  addi $v0, $v0, 1
  sw $v0, 56($t0)
  nop
  j $FOR4
  nop
$ENDFOR4:
  # keep val (j) to stack
  lw $v0, 52($t0)
  nop
  # unary operation
  addi $v0, $v0, 1
  sw $v0, 52($t0)
  nop
  j $FOR3
  nop
$ENDFOR3:
  # keep val (i) to stack
  lw $v0, 48($t0)
  nop
  # unary operation
  addi $v0, $v0, 1
  sw $v0, 48($t0)
  nop
  j $FOR2
  nop
$ENDFOR2:

 li $v0, stop_service
 syscall
 nop
 jr $ra
 nop

.data 0x10004000
 RESULT:

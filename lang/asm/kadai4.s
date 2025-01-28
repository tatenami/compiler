# ------ [ Symbols ] ------
# 	symbol_0 	size: 4 	offset:     0(0) 	[N]
# 	symbol_1 	size: 4 	offset:   0x4(4) 	[i]
# 	symbol_2 	size: 4 	offset:   0x8(8) 	[j]
# 	symbol_3 	size: 4 	offset:   0xc(12) 	[k]
# 	symbol_4 	size: 4004 	offset:  0x10(16) 	[a]
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
  li $v0, 1000
  # assignment [N] <- imm (1000)
  sw $v0, 0($t0)
  nop
  li $v0, 1
  # assignment [i] <- imm (1)
  sw $v0, 4($t0)
  nop
$WHILE0:
  # keep val (i) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep val (N) to stack
  lw $t3, 0($t0)
  nop
  sw $t3, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<='
  sub $t1, $t2, $t3
  slti $t1, $t1, 1
  beq $t1, $zero, $ENDWHILE0
  nop
  li $v0, 1
  # assignment [a] <- imm (1)
  # clac array offset of [a]
  # keep val (i) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  li $t3, 16  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  # keep val (i) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  # pop stack
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [i] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 4($t0)
  nop
  j $WHILE0
  nop
$ENDWHILE0:
  li $v0, 2
  # assignment [i] <- imm (2)
  sw $v0, 4($t0)
  nop
$WHILE1:
  # keep val (i) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep val (N) to stack
  lw $t2, 0($t0)
  nop
  sw $t2, 8($sp)
  nop
  # keep imm val (2) to stack
  li $t3, 2
  # pop stack
  lw $t2, 8($sp)
  nop
  # div exp
  div $t2, $t3
  mflo $v0
  sw $v0, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<='
  sub $t1, $t2, $t3
  slti $t1, $t1, 1
  beq $t1, $zero, $ENDWHILE1
  nop
  li $v0, 2
  # assignment [j] <- imm (2)
  sw $v0, 8($t0)
  nop
$WHILE2:
  # keep val (j) to stack
  lw $t2, 8($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep val (N) to stack
  lw $t2, 0($t0)
  nop
  sw $t2, 8($sp)
  nop
  # keep val (i) to stack
  lw $t3, 4($t0)
  nop
  sw $t3, 12($sp)
  nop
  # pop stack
  lw $t3, 12($sp)
  nop
  # pop stack
  lw $t2, 8($sp)
  nop
  # div exp
  div $t2, $t3
  mflo $v0
  sw $v0, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # comp '<='
  sub $t1, $t2, $t3
  slti $t1, $t1, 1
  beq $t1, $zero, $ENDWHILE2
  nop
  # keep val (i) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep val (j) to stack
  lw $t3, 8($t0)
  nop
  sw $t3, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # mul exp
  mult $t2, $t3
  mflo $v0
  sw $v0, 4($sp)
  nop
  # assignment [k] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 12($t0)
  nop
  li $v0, 0
  # assignment [a] <- imm (0)
  # clac array offset of [a]
  # keep val (k) to stack
  lw $t2, 12($t0)
  nop
  sw $t2, 4($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  li $t3, 16  # add exp
  add $t2, $t2, $t3
  # add exp
  add $t2, $t0, $t2
  # array offset -> [$t2]
  sw $v0, 0($t2)
  nop
  # keep val (j) to stack
  lw $t2, 8($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  # pop stack
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [j] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 8($t0)
  nop
  j $WHILE2
  nop
$ENDWHILE2:
  # keep val (i) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  # pop stack
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [i] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 4($t0)
  nop
  j $WHILE1
  nop
$ENDWHILE1:

 li $v0, stop_service
 syscall
 nop
 jr $ra
 nop

.data 0x10004000
 RESULT:

# ------ [ Symbols ] ------
# 	symbol_0 	size: 4 	offset:     0(0) 	[fizz]
# 	symbol_1 	size: 4 	offset:   0x4(4) 	[buzz]
# 	symbol_2 	size: 4 	offset:   0x8(8) 	[fizzbuzz]
# 	symbol_3 	size: 4 	offset:   0xc(12) 	[others]
# 	symbol_4 	size: 4 	offset:  0x10(16) 	[i]
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
  li $v0, 0
  # assignment [fizz] <- imm (0)
  sw $v0, 0($t0)
  nop
  li $v0, 0
  # assignment [buzz] <- imm (0)
  sw $v0, 4($t0)
  nop
  li $v0, 0
  # assignment [fizzbuzz] <- imm (0)
  sw $v0, 8($t0)
  nop
  li $v0, 0
  # assignment [others] <- imm (0)
  sw $v0, 12($t0)
  nop
  li $v0, 1
  # assignment [i] <- imm (1)
  sw $v0, 16($t0)
  nop
$WHILE0:
  # keep val (i) to stack
  lw $t2, 16($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (31) to stack
  li $t3, 31
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDWHILE0
  nop
  # --- [START] if-else stmt ---
  # keep val (i) to stack
  lw $t2, 16($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (15) to stack
  li $t3, 15
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # div exp
  div $t2, $t3
  mfhi $v0
  sw $v0, 4($sp)
  nop
  # keep imm val (0) to stack
  li $t3, 0
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # comp '=='
  sub $t1, $t2, $t3
  sltiu $t1, $t1, 1
  # else stmt
  bne $t1, $zero, $IF0
  nop
  # --- [START] if-else stmt ---
  # keep val (i) to stack
  lw $t2, 16($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (3) to stack
  li $t3, 3
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # div exp
  div $t2, $t3
  mfhi $v0
  sw $v0, 4($sp)
  nop
  # keep imm val (0) to stack
  li $t3, 0
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # comp '=='
  sub $t1, $t2, $t3
  sltiu $t1, $t1, 1
  # else stmt
  bne $t1, $zero, $IF1
  nop
  # --- [START] if-else stmt ---
  # keep val (i) to stack
  lw $t2, 16($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (5) to stack
  li $t3, 5
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # div exp
  div $t2, $t3
  mfhi $v0
  sw $v0, 4($sp)
  nop
  # keep imm val (0) to stack
  li $t3, 0
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # comp '=='
  sub $t1, $t2, $t3
  sltiu $t1, $t1, 1
  # else stmt
  bne $t1, $zero, $IF2
  nop
  # keep val (others) to stack
  lw $t2, 12($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [others] <- exp val
  lw $v0, 4($sp)
  nop
  sw $v0, 12($t0)
  nop
  j $END_IF2
  nop
  # if stmt
$IF2:
  # keep val (buzz) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [buzz] <- exp val
  lw $v0, 4($sp)
  nop
  sw $v0, 4($t0)
  nop
$END_IF2:
  j $END_IF1
  nop
  # if stmt
$IF1:
  # keep val (fizz) to stack
  lw $t2, 0($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [fizz] <- exp val
  lw $v0, 4($sp)
  nop
  sw $v0, 0($t0)
  nop
$END_IF1:
  j $END_IF0
  nop
  # if stmt
$IF0:
  # keep val (fizzbuzz) to stack
  lw $t2, 8($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [fizzbuzz] <- exp val
  lw $v0, 4($sp)
  nop
  sw $v0, 8($t0)
  nop
$END_IF0:
  # keep val (i) to stack
  lw $t2, 16($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  sw $t3, 8($sp)
  nop
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [i] <- exp val
  lw $v0, 4($sp)
  nop
  sw $v0, 16($t0)
  nop
  j $WHILE0
  nop
$ENDWHILE0:

 li $v0, stop_service
 syscall
 nop
 jr $ra
 nop

.data 0x10004000
 RESULT:

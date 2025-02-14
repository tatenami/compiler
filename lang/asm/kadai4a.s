# ------ [ Symbols ] ------
# 	symbol_0 	size: 4 	offset:     0 	[N]
# 	symbol_1 	size: 4 	offset:   0x4 	[i]
# 	symbol_2 	size: 4 	offset:   0x8 	[j]
# 	symbol_3 	size: 4 	offset:   0xc 	[k]
# 	symbol_4 	size: 4004 	offset: 0xfb0 	[a]
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
  lw $t3, 8($sp)
  nop
  lw $t2, 4($sp)
  nop
  # comp '<='
  sub $t1, $t2, $t3
  slti $t1, $t1, 1
  beq $t1, $zero, $ENDWHILE0
  nop
  li $v0, 1
  # assignment [a] <- imm (1)
  # keep val (i) to stack
  lw $t2, 4($t0)
  nop
  sw $t2, 4($sp)
  nop
  lw $t2, 4($sp)
  nop
  li $t3, 4  # mul exp
  mult $t2, $t3
  mflo $t2
  # add exp
  add $t2, $t0, $t2
  sw $v0, 0($t2)
  nop
  # keep val (i) to stack
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
  # assignment [i] <- exp val
  lw $v0, 4($sp)
  nop
  sw $v0, 4($t0)
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

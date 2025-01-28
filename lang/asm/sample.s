# ------ [ Symbols ] ------
# 	symbol_0 	size: 4 	offset:     0(0) 	[and]
# 	symbol_1 	size: 4 	offset:   0x4(4) 	[or]
# 	symbol_2 	size: 4 	offset:   0x8(8) 	[xor]
# 	symbol_3 	size: 4 	offset:   0xc(12) 	[lshift]
# 	symbol_4 	size: 4 	offset:  0x10(16) 	[rshift]
# 	symbol_5 	size: 4 	offset:  0x14(20) 	[a]
# 	symbol_6 	size: 4 	offset:  0x18(24) 	[b]
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
  # assignment [a] <- imm (1)
  sw $v0, 20($t0)
  nop
  li $v0, 7
  # assignment [b] <- imm (7)
  sw $v0, 24($t0)
  nop
  # keep val (a) to stack
  lw $t2, 20($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep val (b) to stack
  lw $t3, 24($t0)
  nop
  sw $t3, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # and exp
  and $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [and] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 0($t0)
  nop
  # keep val (a) to stack
  lw $t2, 20($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep val (b) to stack
  lw $t3, 24($t0)
  nop
  sw $t3, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # or exp
  or $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [or] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 4($t0)
  nop
  # keep val (a) to stack
  lw $t2, 20($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep val (b) to stack
  lw $t3, 24($t0)
  nop
  sw $t3, 8($sp)
  nop
  # pop stack
  lw $t3, 8($sp)
  nop
  # pop stack
  lw $t2, 4($sp)
  nop
  # xor exp
  xor $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [xor] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 8($t0)
  nop
  # keep val (a) to stack
  lw $t2, 20($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  # pop stack
  lw $t2, 4($sp)
  nop
  # R-shift exp
  srav $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [rshift] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 16($t0)
  nop
  # keep val (b) to stack
  lw $t2, 24($t0)
  nop
  sw $t2, 4($sp)
  nop
  # keep imm val (1) to stack
  li $t3, 1
  # pop stack
  lw $t2, 4($sp)
  nop
  # L-shift exp
  sllv $v0, $t2, $t3
  sw $v0, 4($sp)
  nop
  # assignment [lshift] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 12($t0)
  nop
  # keep val (a) to stack
  lw $v0, 20($t0)
  nop
  sub $v0, $zero, $v0
  addi $v0, $v0, -1
  sw $v0, 4($sp)
  nop
  # assignment [b] <- exp val
  # pop stack
  lw $v0, 4($sp)
  nop
  sw $v0, 24($t0)
  nop

 li $v0, stop_service
 syscall
 nop
 jr $ra
 nop

.data 0x10004000
 RESULT:

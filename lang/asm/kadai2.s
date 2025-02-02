# ------ [ Symbols ] ------
# 	symbol_0 	size: 4 	offset:     0(0) 	[i]
# 	symbol_1 	size: 4 	offset:   0x4(4) 	[fact]
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
  # assignment [fact] <- val
  # keep imm val (1) to reg($v0)
  li $v0, 1
  sw $v0, 4($t0)
  nop
  # assignment [i] <- val
  # keep imm val (1) to reg($v0)
  li $v0, 1
  sw $v0, 0($t0)
  nop
$WHILE0:
  # keep imm val (6) to reg($t3)
  li $t3, 6
  # keep val (i) to reg($t2)
  lw $t2, 0($t0)
  nop
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDWHILE0
  nop
  # assignment [fact] <- val
  # keep val (i) to reg($t3)
  lw $t3, 0($t0)
  # keep val (fact) to reg($t2)
  lw $t2, 4($t0)
  nop
  # mul exp
  mult $t2, $t3
  mflo $v0
  sw $v0, 0($sp)
  nop
  # pop stack
  lw $v0, 0($sp)
  nop
  sw $v0, 4($t0)
  nop
  # assignment [i] <- val
  # keep imm val (1) to reg($t3)
  li $t3, 1
  # keep val (i) to reg($t2)
  lw $t2, 0($t0)
  nop
  # add exp
  add $v0, $t2, $t3
  sw $v0, 0($sp)
  nop
  # pop stack
  lw $v0, 0($sp)
  nop
  sw $v0, 0($t0)
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

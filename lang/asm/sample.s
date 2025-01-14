# ------ [ Symbols ] ------
# 	symbol_0 	size: 4 	offset:     0 	[i]
# 	symbol_1 	size: 4 	offset:   0x4 	[sum]
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
  li $t2, 0
  # assignment [sum] <- imm (0)
  sw $t2, 4($t0)
  nop
  li $t2, 1
  # assignment [i] <- imm (1)
  sw $t2, 0($t0)
  nop
$WHILE0:
  # keep val to register
  lw $t2, 0($t0)
  nop
  # keep imm val (11) to register
  li $t3, 11
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDWHILE0
$WHILE1:
  # keep val to register
  lw $t2, 4($t0)
  nop
  # keep imm val (11) to register
  li $t3, 11
  # comp '<'
  slt $t1, $t2, $t3
  beq $t1, $zero, $ENDWHILE1
  # assignment [sum] <- exp val
  sw $v0, 4($t0)
  nop
  j $WHILE1
  nop
$ENDWHILE1:
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

/*
** $Id: op_esc4.c,v 1.1 2007-01-26 14:18:37 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_esc4" opcode="0xdc"/>
*/

int op_esc4(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  struct s_modrm        *modrm;
  
  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  switch(modrm->r) {
  case 0:
    new->instr = ASM_FADD;
    break;
  case 1:
    new->instr = ASM_FMUL;
    break;
  case 2:
    new->instr= ASM_FCOM;
    break;
  case 3:
    new->instr = ASM_FCOMP;
    break;
  case 4:
    new->instr = ASM_FSUB;
    break;
  case 5:
    new->instr = ASM_FSUBR;
    break;
  case 6:
    new->instr = ASM_FDIV;
    break;
  case 7:
    new->instr = ASM_FDIVR;
    break;
  }
    
  if (modrm->mod == 3) {
    new->op1.type = ASM_OTYPE_FIXED;
    new->op1.content = ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE;
    new->op1.len = 1;
    new->op1.scale = modrm->m;
    new->op2.type = ASM_OTYPE_FIXED;
    new->op2.content = ASM_OP_FPU | ASM_OP_BASE;
  } else {
    new->op1.type = ASM_OTYPE_FIXED;
    operand_rmv(&new->op1, opcode + 1, len - 1, proc);
  }
  if (new->op1.type)
    new->len += new->op1.len;
  return (new->len);
}
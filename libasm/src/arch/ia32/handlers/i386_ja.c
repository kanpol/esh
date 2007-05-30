/*
** $Id: i386_ja.c,v 1.4 2007-05-30 00:15:41 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_ja" opcode="0x87"/>
*/


int i386_ja(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_CONDBRANCH;
  new->instr = ASM_BRANCH_U_GREATER;
  new->len += 1;
  printf("kiko\n");
#if LIBASM_USE_OPERAND_VECTOR
  new->len += asm_operand_fetch(&new->op1, opcode + 1, ASM_OTYPE_JUMP, new);
#else
  new->op1.type = ASM_OTYPE_JUMP;
  new->op1.content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op1.ptr = opcode + 1;
  new->op1.len = 4;
  memcpy(&new->op1.imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}

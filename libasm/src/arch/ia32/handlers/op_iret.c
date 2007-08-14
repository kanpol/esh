/**
 * @file op_iret.c
 * @ingroup handlers_ia32
 * $Id: op_iret.c,v 1.5 2007-08-14 06:52:55 strauss Exp $
 *
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * <instruction opcode="0xcf" func="op_iret"/>
 */

int op_iret(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_IRET;
  new->type = ASM_TYPE_INT | ASM_TYPE_TOUCHSP | ASM_TYPE_RETPROC |
                ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_NT | ASM_FLAG_VM;
  return (new->len);
}

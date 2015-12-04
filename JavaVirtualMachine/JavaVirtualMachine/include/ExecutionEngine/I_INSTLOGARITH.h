//#################################################################################################
/*! \file I_INSTLOGARITH.h
 *
 *  \brief Interface de instrucoes logico aritimeticas da JVM.
 *
 *  Interface responsavel por disponibilizar os servicos relacionados a instrucoes logico atmeticas
 */
//##################################################################################################

#ifndef I_INSTLOGARITH_h
#define I_INSTLOGARITH_h
#ifdef INSTLOGARITH_SERV
#define EXT11
#else
#define EXT11 extern
#endif

#include "../Estruturas/E_JVM.h"

//--------------------------------------------------------------------------------------------------
#define SHIFT_MASK_32 0x1F
#define SHIFT_MASK_64 0x3F

/*!
 *  Instrucao para soma de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void iadd(Thread*);

/*!
 *  Instrucao para soma de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void ladd(Thread*);
/*!
 *  Instrucao para soma de float de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void fadd(Thread*);
/*!
 *  Instrucao para soma de double de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void dadd(Thread*);
/*!
 *  Instrucao para subtracao de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void isub(Thread*);
/*!
 *  Instrucao para subtracao de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lsub(Thread*);
/*!
 *  Instrucao para subtracao de float de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void fsub(Thread*);
/*!
 *  Instrucao para subtracao de double de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void dsub(Thread*);
/*!
 *  Instrucao para multiplicacao de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void imul(Thread*);
/*!
 *  Instrucao para multiplicacao de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lmul(Thread*);
/*!
 *  Instrucao para multiplicacao de float de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void fmul(Thread*);
/*!
 *  Instrucao para multiplicacao de double de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void dmul(Thread*);
/*!
 *  Instrucao para divisao de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void idiv(Thread*);
/*!
 *  Instrucao para divisao de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void Ldiv(Thread*);
/*!
 *  Instrucao para divisao de float de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void fdiv(Thread*);
/*!
 *  Instrucao para divisao de double de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void ddiv(Thread*);
/*!
 *  Instrucao para resto de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void irem(Thread*);
/*!
 *  Instrucao para resto de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lrem(Thread*);
/*!
 *  Instrucao para resto de float de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void frem(Thread*);
/*!
 *  Instrucao para resto de double de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void Drem(Thread*);
/*!
 *  Instrucao para nega de inteiro de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void ineg(Thread*);
/*!
 *  Instrucao para nega de inteiro de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lneg(Thread*);
/*!
 *  Instrucao para nega de float de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void fneg(Thread*);
/*!
 *  Instrucao para nega de double de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void dneg(Thread*);
/*!
 *  Instrucao para shift left de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void ishl(Thread*);
/*!
 *  Instrucao para shift left de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lshl(Thread*);
/*!
 *  Instrucao para shift right de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void ishr(Thread*);
/*!
 *  Instrucao para shift right de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lshr(Thread*);
/*!
 *  Instrucao para shift right sem sinal de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void iushr(Thread*);
/*!
 *  Instrucao para shift right sem sinal de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lushr(Thread*);
/*!
 *  Instrucao para and de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void iand(Thread*);
/*!
 *  Instrucao para and de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void land(Thread*);
/*!
 *  Instrucao para or de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void ior(Thread*);
/*!
 *  Instrucao para or de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lor(Thread*);
/*!
 *  Instrucao para xor de inteiros de 32 bits
 *  \param Thread
 *  \return void
 */
EXT11 void ixor(Thread*);
/*!
 *  Instrucao para xor de inteiros de 64 bits
 *  \param Thread
 *  \return void
 */
EXT11 void lxor(Thread*);
/*!
 *  Instrucao para incremento de inteiros de 32 bits local
 *  \param Thread
 *  \return void
 */
EXT11 void iinc(Thread*);



#endif /* I_INSTLOGARITH_h */

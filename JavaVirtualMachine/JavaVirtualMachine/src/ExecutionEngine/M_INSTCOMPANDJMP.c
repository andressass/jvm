//
//  M_INSTCOMPANDJMP.c
//  JavaVirtualMachine
//
//  Created by Gabriel Araujo Dantas on 04/12/15.
//  Copyright © 2015 Rondinele Prado. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "../../include/ExecutionEngine/I_INSTCOMPANDJMP.h"
#include "../../include/MemoryUnit/I_MEMORYUNIT.h"

void lcmp(Environment *environment){
    
    u8 operando1 = 0;
    u8 operando2 = 0;
    
    u4 operandoPilha1 = 0;
    u4 operandoPilha2 = 0;
    
    u4 resultado = -1000;
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operandoPilha2 = popFromOperandStack(environment->thread);
    
    operando1 = (u8) operandoPilha2;
    operando1 = (u8) operandoPilha1 << 32;
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operandoPilha2 = popFromOperandStack(environment->thread);
    
    operando2 = (u8) operandoPilha2;
    operando2 = (u8) operando1 << 32;
    
    if (operando2 > operando1) {
        resultado = 1;
    }else if (operando2 == operando1){
        resultado = 0;
    }else{
        resultado = -1;
    }
    pushInOperandStack(environment->thread, resultado);
}

void fcmpl(Environment *environment){
    
    float operando1 = 0;
    float operando2 = 0;
    
    u4 operandoPilha1 = 0;
    u4 operandoPilha2 = 0;
    u4 resultado = -1000;
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operando1 = u4ToFLoat(operandoPilha1);
    
    operandoPilha2 = popFromOperandStack(environment->thread);
    operando2 = u4ToFLoat(operandoPilha2);
    
    if(operando2 > operando1){
        resultado = 1;
    }else if (operando2 == operando1){
        resultado = 0;
    }else if (operando2 < operando1){
        resultado = -1;
    }else{
        //Caso o valor passado seja um NaN
        resultado = -1;
    }
    pushInOperandStack(environment->thread, resultado);
}

void fcmpg(Environment *environment){
    float operando1 = 0;
    float operando2 = 0;
    
    u4 operandoPilha1 = 0;
    u4 operandoPilha2 = 0;
    u4 resultado = -1000;
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operando1 = u4ToFLoat(operandoPilha1);  
    
    operandoPilha2 = popFromOperandStack(environment->thread);
    operando2 = u4ToFLoat(operandoPilha2);
    
    if(operando2 > operando1){
        resultado = 1;
    }else if (operando2 == operando1){
        resultado = 0;
    }else if (operando2 < operando1){
        resultado = -1;
    }else{
        //Caso o valor passado seja um NaN
        resultado = 1;
    }
    pushInOperandStack(environment->thread, resultado);
}

void dcmpl(Environment *environment){

    double operando1 = 0;
    double operando2 = 0;
    
    u4 operandoPilha1 = 0;
    u4 operandoPilha2 = 0;
    u4 resultado = -1000;
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operandoPilha2 = popFromOperandStack(environment ->thread);
    
    operando1 = u4ToDouble(operandoPilha1, operandoPilha2);
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operandoPilha2 = popFromOperandStack(environment->thread);
    
    operando2 = u4ToDouble(operandoPilha1, operandoPilha2);
    
    if(operando2 > operando1){
        resultado = 1;
    }else if (operando2 == operando1){
        resultado = 0;
    }else if (operando2 < operando1){
        resultado = -1;
    }else{
        resultado = -1;
    }
    pushInOperandStack(environment->thread, resultado);
}
void dcmpg(Environment *environment){
    double operando1 = 0;
    double operando2 = 0;
    
    u4 operandoPilha1 = 0;
    u4 operandoPilha2 = 0;
    u4 resultado = -1000;
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operandoPilha2 = popFromOperandStack(environment ->thread);
    
    operando1 = u4ToDouble(operandoPilha1, operandoPilha2);
    
    operandoPilha1 = popFromOperandStack(environment->thread);
    operandoPilha2 = popFromOperandStack(environment->thread);
    
    operando2 = u4ToDouble(operandoPilha1, operandoPilha2);
    
    if(operando2 > operando1){
        resultado = 1;
    }else if (operando2 == operando1){
        resultado = 0;
    }else if (operando2 < operando1){
        resultado = -1;
    }else{
        resultado = 1;
    }
    pushInOperandStack(environment->thread, resultado);

}

void ifeq(Environment *environment){
    u2 offset;
    u4 operando = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;
    
    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando = popFromOperandStack(environment->thread);
    
    if(operando == 0){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void ifne(Environment *environment){
    u2 offset;
    u4 operando = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;

    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando = popFromOperandStack(environment->thread);
    
    if(operando != 0){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void iflt(Environment *environment){
    u2 offset;
    u4 operando = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;

    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando = popFromOperandStack(environment->thread);
    
    //Como u4 eh unsigned fiz um cast para int que contem 4 bytes porem sem unsigned
    int operandoSemUnsigned = (int) operando;
    
    if(operandoSemUnsigned < 0){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void ifge(Environment *environment){
    u2 offset;
    u4 operando = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;

    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando = popFromOperandStack(environment->thread);
    
    //Como u4 eh unsigned fiz um cast para int que contem 4 bytes porem sem unsigned
    int operandoSemUnsigned = (int) operando;
    
    if(operandoSemUnsigned >= 0){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void ifgt(Environment *environment){
    u2 offset;
    u4 operando = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;

    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando = popFromOperandStack(environment->thread);
    
    //Como u4 eh unsigned fiz um cast para int que contem 4 bytes porem sem unsigned
    int operandoSemUnsigned = (int) operando;
    
    if(operandoSemUnsigned > 0){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void ifle(Environment *environment){
    u2 offset;
    u4 operando = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;

    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando = popFromOperandStack(environment->thread);
    
    //Como u4 eh unsigned fiz um cast para int que contem 4 bytes porem sem unsigned
    int operandoSemUnsigned = (int) operando;
    
    if(operandoSemUnsigned <= 0){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void if_icmpeq(Environment *environment){
    u2 offset;
    u4 operando1 = 0;
    u4 operando2 = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;

    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando1 = popFromOperandStack(environment->thread);
    operando2 = popFromOperandStack(environment->thread);
    
    if(operando2 == operando1){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void if_icmpne(Environment *environment){

    u2 offset;
    u4 operando1 = 0;
    u4 operando2 = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;
    
    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando1 = popFromOperandStack(environment->thread);
    operando2 = popFromOperandStack(environment->thread);
    
    if(operando2 != operando1){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void if_icmplt(Environment *environment){
    u2 offset;
    u4 operando1 = 0;
    u4 operando2 = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;
    
    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando1 = popFromOperandStack(environment->thread);
    operando2 = popFromOperandStack(environment->thread);
    
    if(operando2 < operando1){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void if_icmpge(Environment *environment){
    u2 offset;
    u4 operando1 = 0;
    u4 operando2 = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;
    
    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando1 = popFromOperandStack(environment->thread);
    operando2 = popFromOperandStack(environment->thread);
    
    if(operando2 >= operando1){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void if_icmpgt(Environment *environment){
    u2 offset;
    u4 operando1 = 0;
    u4 operando2 = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;
    
    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando1 = popFromOperandStack(environment->thread);
    operando2 = popFromOperandStack(environment->thread);
    
    if(operando2 > operando1){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void if_icmple(Environment *environment){
    u2 offset;
    u4 operando1 = 0;
    u4 operando2 = 0;
    u4 pc = 0;
    u1 byte1, byte2;
    u1 *code;
    CodeAttribute *codeAttribute;
    
    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    //perguntar como que chego no code com as estruturas criadas
    code = codeAttribute->code;
    
    byte1 = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    
    byte2 = *(code + (pc + 1));
    environment->thread->vmStack->top->returnPC++;
    
    offset = (u2)byte1;
    offset = offset << 8;
    offset |= byte2;
    offset -= 3;
    
    operando1 = popFromOperandStack(environment->thread);
    operando2 = popFromOperandStack(environment->thread);
    
    if(operando2 <= operando1){
        environment->thread->vmStack->top->returnPC += offset;
    }
}

void goto(Environment *environment) {
    u2 index;
    u4 pc = 0;
    u1 byte;
    u1 *code;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    code = codeAttribute->code;

    byte = *(code + pc);

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    index = (u2)byte;

    index = index << 8;
    byte = *(code + pc);
    index |= (u2)byte;

    environment->thread->vmStack->top->returnPC += index - 2;
}

void jsr(Environment *environment) {
    u2 index;
    u4 pc = 0;
    u1 byte;
    u1 *code;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    code = codeAttribute->code;

    byte = *(code + pc);

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    index = (u2)byte;

    index = index << 8;
    byte = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    index |= (u2)byte;

    pushOperandStack(environment->thread,environment->thread->vmStack->top->returnPC);

    environment->thread->vmStack->top->returnPC += index - 2;
}

void ret() {
   //
}

void tableswitch(Environment *environment) {
    u4 i, pad, low, high, def, offset, index, opCode, pc;
    u1 byte;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    code = codeAttribute->code;
 
    opCode = environment->thread->vmStack->top->returnPC;
    pc = environment->thread->vmStack->top->returnPC;
    code = codeAttribute->code;
    byte = *(code + pc);

    low = 0;
    high = 0;
    def = 0;
    offset = 0;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    pad = environment->thread->vmStack->top->returnPC % 4;

    if (pad != 0) {
        for (i = 0; i < 4 - pad; i++) {
            environment->thread->vmStack->top->returnPC++;
            pc = environment->thread->vmStack->top->returnPC;
        }
    }

    for (i = 0; i < 3; i++) {
        def |= (u4)byte;
        def = def << 8;
        environment->thread->vmStack->top->returnPC++; 
        pc = environment->thread->vmStack->top->returnPC;
        byte = *(code + pc);
    }

    def |= (u4)byte;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);

    for (i = 0; i < 3; i++) {
        low |= (u4)byte;
        low = low << 8;
        environment->thread->vmStack->top->returnPC++;
        pc = environment->thread->vmStack->top->returnPC;
        byte = *(code + pc);
    }

    low |= (u4)byte;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);

    for (i = 0; i < 3; i++) {
        high |= (u4)byte;
        high = high << 8;
        environment->thread->vmStack->top->returnPC++;
        pc = environment->thread->vmStack->top->returnPC;
        byte = *(code + pc);
    }

    high |= (u4)byte;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);

    index = popFromOperandStack(environment->thread);

    if ((index < low) || (index > high)) {
        environment->thread->vmStack->top->returnPC = def + opCode;
    } else {
        for (i = 0; i < index * 4; i++) {
            environment->thread->vmStack->top->returnPC++;
            pc = environment->thread->vmStack->top->returnPC;
            byte = *(code + pc);
        }
        for (i = 0; i < 3; i++) {
            offset |= (u4)byte;
            offset = high << 8;
            environment->thread->vmStack->top->returnPC++;
            pc = environment->thread->vmStack->top->returnPC;
            byte = *(code + pc);
        }
        offset |= byte + opCode;
        environment->thread->vmStack->top->returnPC = offset;
    }
}

void lookupswitch(Environment *environment) {
    u4 i, j, pad, npairs = 0, def = 0, key, found, opCode, pc;
    npair *pair, *auxiliar; // criar nova struct npair{ u4 match; u4 offset; } 
    u1 byte;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    code = codeAttribute->code;
 
    opCode = environment->thread->vmStack->top->returnPC;
    pc = environment->thread->vmStack->top->returnPC;
    code = codeAttribute->code;
    byte = *(code + pc);

    environment->thread->vmStack->top->returnPC++;
    pad = environment->thread->vmStack->top->returnPC % 4;

    if (pad != 0) {
        for (i = 0; i < 4 - pad; i++) {
            environment->thread->vmStack->top->returnPC++;
            pc = environment->thread->vmStack->top->returnPC;
        }
    }

    for (i = 0; i < 3; i++) {
        def |= (u4)byte;
        def = def << 8;
        environment->thread->vmStack->top->returnPC++; 
        pc = environment->thread->vmStack->top->returnPC;
        byte = *(code + pc);
    }

    def |= (u4)byte;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);

    for (i = 0; i < 3; i++) {
        npairs |= (u4)byte;
        npairs = npairs << 8;
        environment->thread->vmStack->top->returnPC++; 
        pc = environment->thread->vmStack->top->returnPC;
        byte = *(code + pc);
    }

    npairs |= (u4)byte;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);

    pair = calloc(npairs, sizeof(npair));
    auxiliar = pair;
    auxiliar->match = 0;

    for (i = 0; i < npairs; i++) {
        pair->match = 0;

        for (j = 0; j < 3; j++) {
            pair->match |= (u4)byte;
            pair->match = pair->match << 8;
            environment->thread->vmStack->top->returnPC++; 
            pc = environment->thread->vmStack->top->returnPC;
            byte = *(code + pc);
        }


        pair->match |= (u4)byte;

        environment->thread->vmStack->top->returnPC++;
        pc = environment->thread->vmStack->top->returnPC;
        byte = *(code + pc);

        pair->offset = 0;

        for (j = 0; j < 3; j++) {
            pair->offset |= (u4)byte;
            pair->offset = pair->offset << 8;
            environment->thread->vmStack->top->returnPC++; 
            pc = environment->thread->vmStack->top->returnPC;
            byte = *(code + pc);
        }
        
        pair->offset |= (u4)byte;

        environment->thread->vmStack->top->returnPC++;
        pc = environment->thread->vmStack->top->returnPC;
        byte = *(code + pc);
        pair++;
    }

    key = popFromOperandStack(environment->thread);
    found = 0;
    i = 0;
    /*pair = auxiliar;*/

    while ((!found) && (i < npairs)) {
        if (key == auxiliar->match) {
            found = 1;
            environment->thread->vmStack->top->returnPC = auxiliar->offset + opCode;
        } else {
            i++;
            auxiliar++;
        }
    }

    if (!found) {
        environment->thread->vmStack->top->returnPC = def + opCode;
    }
}

void ifnull(Environment *environment) {
    u2 index;
    u4 auxiliar, pc = 0;
    u1 byte;
    u1 *code;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    code = codeAttribute->code;

    byte = *(code + pc);

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;

    auxiliar1 = popFromOperandStack(environment->thread);
    index = (u2)byte;
    
    index = index << 8;
    byte = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    index |= (u2)byte;

    if (auxiliar1 == CONSTANT_NULL) {
        environment->thread->vmStack->top->returnPC += index - 2;
    } else {
        environment->thread->vmStack->top->returnPC++;
    }
}

void ifnonnull(Environment *environment) {
    u2 index;
    u4 auxiliar, pc = 0;
    u1 byte;
    u1 *code;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    
    pc = environment->thread->vmStack->top->returnPC;
    code = codeAttribute->code;

    byte = *(code + pc);

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;

    auxiliar1 = popFromOperandStack(environment->thread);
    index = (u2)byte;
    
    index = index << 8;
    byte = *(code + pc);
    environment->thread->vmStack->top->returnPC++;
    index |= (u2)byte;

    if (auxiliar1 != CONSTANT_NULL) {
        environment->thread->vmStack->top->returnPC += index - 2;
    } else {
        environment->thread->vmStack->top->returnPC++;
    }
}


void jsr_w(Environment *environment) {
    u8 index;
    u4 pc = 0;
    u1 byte;
    u1 *code;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    code = codeAttribute->code;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index = (u8)byte;
    index = index << 8;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index |= (u8)byte;
    index = index << 8;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index |= (u8)byte;
    index = index << 8;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index |= (u8)byte;

    pushOperandStack(environment->thread,environment->thread->vmStack->top->returnPC);

    environment->thread->vmStack->top->returnPC += index - 4;
}

void goto_w(Environment *environment) {
    u8 index;
    u4 pc = 0;
    u1 byte;
    u1 *code;
    CodeAttribute *codeAttribute;

    codeAttribute = getCodeFromMethodInfo(environment->methodArea->classTable->javaClass->arqClass->methods, environment->methodArea->classTable->javaClass->arqClass->constant_pool);
    code = codeAttribute->code;

    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index = (u8)byte;
    index = index << 8;
    
    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index |= (u8)byte;
    index = index << 8;
   
    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index |= (u8)byte;
    index = index << 8;
   
    environment->thread->vmStack->top->returnPC++;
    pc = environment->thread->vmStack->top->returnPC;
    byte = *(code + pc);
    index |= (u8)byte;

    environment->thread->vmStack->top->returnPC += index - 4;
}
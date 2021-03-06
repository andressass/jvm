//#################################################################################################
/*! \file I_LECLASS.h
 *
 *  \brief Interface do Leitor e Exibidor de arquivos ".class".
 *
 *  Interface responsavel por prover os metodos relacionados a leitura e exibicao de um arquivo
 *  ".class".
 */
//##################################################################################################


#ifndef I_LECLASS
#define I_LECLASS
#if defined(LCLASS_SERV) && defined(ECLASS_SERV) && defined(OPCLASS_SERV)
#define EXT4
#else
#define EXT4 extern
#endif

#include<stdio.h>
#include<stdlib.h>
#include "IP_LECLASS.h"


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por prover o servico de leitura de um arquivo ".class", preenchendo uma 
 * estrutura ArqClass.
 *
 * \param arq_class         Estrutura inicializada do tipo ArqClass a ser preenchida.
 * \param arquivo_entrada   Arquivo ".class" a ser lido.
 * \return Resultado da operacao
 */
EXT4 OPresult LECLASS_leitor(ArqClass* arq_class, const char* arquivo_entrada);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por prover o servico de exibicao de uma estrutura ".class"
 *
 * \param arq_class         Estrutura inicializada do tipo ArqClass a ser exibida.
 * \return Resultado da operacao
 */
EXT4 OPresult LECLASS_exibidor(ArqClass* arq_class);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por prover o servico de liberacao recursiva de uma estrutura ".class"
 *
 * \param arq_class         Estrutura inicializada do tipo ArqClass a ser liberada.
 */
EXT4 void LECLASS_free(ArqClass* arq_class);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo responsavel por prover mensagens de resuldados de erro de operacoes do leitor ".class"
 *
 * \param resultado         Tipo resultado a ser decodificado
 * \param fileName         Nome do arquivo
 */
EXT4 void LECLASS_exibeErroOperacao(OPresult resultado, const char* fileName);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que que obtem uma string de caracteres unicode no pool de constantes de uma estrutura
 * CONST_UTF8 referente ao nome da classe apontada pelo indice passado
 *
 * \param cp      ponteiro para o pool de constantes
 * \param index   indice da classe no pool de constantes.
 *  \return        string de char de 16bits (w_char_t).
 */
EXT4 char* getClassNameFromConstantPool(cp_info* cp, u2 index);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que, dado um indice valido de field_info ou methdo_info para um pool de constantes, 
 * procura e retorna por referencia o nome da classe do field/metd, o nome do field/metd, e o 
 * descritor do field/metd.
 *
 * \param index Indice valido para o fieldInfo.
 * \param constant_pool Referencia para o pool de constantes a ser utilizado.
 * \param class_name Referencia para um vetor de char a receber o nome da classe do field/metd
 * \param name Referencia para um vetor de char a receber o nome do field/metd
 * \param descriptor Referencia para um vetor de char a receber o descritor do field/metd
 */
EXT4 void getFieldOrMethodInfoAttributesFromConstantPool(u2 index,
                                                 cp_info* constant_pool,
                                                 char** class_name,
                                                 char** name,
                                                 char** descriptor);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que, dado uma referencia para uma lista de tabela de excecoes e seu respectivo tamanho,
 * cria, preenche e retorna uma referencia para um vetor de estruturas exception table.
 *
 * \param code Ponteiro para o vetor que contem as excetion_tables
 * \param exception_table_length Numero de elementos na tabela de excessoes
 * \param cp ponteiro para o pool de constantes
 * \return Ponteiro para um vetor de tabela de excessoes preenchida
 */
EXT4 ExceptionTable* parseExceptionTable(u1* exceptionTableList, u2 exception_table_length);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que que obtem uma string de caracteres unicode no pool de constantes de uma estrutura
 * CONST_UTF8 apontada pelo indice passado
 *
 * \param cp      ponteiro para o pool de constantes
 * \param index   indice da estrutura UTF8_Info no pool de constantes.
 *  \return        string de char de 16bits (w_char_t).
 */
EXT4 wchar_t * getUnicodeFromConstantPool(cp_info* cp, u2 index);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que que obtem uma string de caracteres UTF8 no pool de constantes de uma estrutura
 * CONST_UTF8 apontada pelo indice passado
 *
 * \param cp      ponteiro para o pool de constantes
 * \param index   indice da estrutura UTF8_Info no pool de constantes.
 *  \return        string de char de 8bits (char *).
 */
EXT4 char * getUTF8FromConstantPool(cp_info* cp, u2 index);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que, dado uma referencia para um vetor de informacoes de um atributo do tipo code,
 * preenche e retorna uma estrutura
 * CodeAttribute.
 *
 * \param info Referencia para o atributo code
 * \return Estrutura codeAttribute preenchida
 */
EXT4 CodeAttribute* parseCode(u1* info);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que, dado uma referencia para um vetor de informacoes de um atributo do tipo constant 
 * value, preenche e retorna uma estrutura ConstantValueAtribute.
 *
 * \param info Referencia para o atributo constant value
 * \return Estrutura ConstantValueAttribute preenchida
 */
EXT4 ConstantValueAttribute* parseConstantValue(u1* info);


//--------------------------------------------------------------------------------------------------
/*!
 * Metodo que, dado uma referencia para um vetor de informacoes de um atributo do tipo exception,
 * preenche e retorna uma estrutura ExceptionAttribute.
 *
 * \param info Referencia para o atributo exception
 * \return Estrutura ExceptionAttribute preenchida
 */
EXT4 ExceptionAttribute* parseException(u1* info);



#endif

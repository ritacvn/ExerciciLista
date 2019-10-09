//
//  main.c
//  EDAExercicio
//
//  Created by Rita de Cássia Vasconcelos do Nascimento on 09/10/19.
//  Copyright © 2019 Rita de Cássia Vasconcelos do Nascimento. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stddef.h>

//ESTRUTURA DO NÓ DA LISTA
    typedef struct No_Lista{
        char sexo, nome[200];
        int idade;
        struct No_Lista *proximo_no;
    }NO_LISTA;
int TotalElemento = 0;
//FUNÇÃO QUE INSERE NO INÍCIO DA LISTA
    void InsereNaLista(NO_LISTA **cabeca, char nomex[200], int idadex, char sexox){
        
    //Alocação dinâmica da lista
    NO_LISTA *novo_no = malloc(sizeof(NO_LISTA));
    strcpy(novo_no->nome,nomex);
        novo_no->idade=idadex;
        novo_no->sexo=sexox;
    //Verificando se a lista está vazia
    if(*cabeca==0){
        novo_no->proximo_no = 0;
        *cabeca = novo_no;
    }
    else{
        novo_no->proximo_no = 0;
        *cabeca = novo_no;
    }
        TotalElemento++;
}

//FUNÇÃO QUE EXIBE OS ELEMENTOS DA LISTA
void ExibeLista(NO_LISTA *cabeca){
    if (TotalElemento<1){
        printf("Impossível exibir. A lista está vazia!\n");
    }else{
        
        NO_LISTA *auxiliar_cabeca = cabeca;
        printf("\nA LISTA possui: %d elemento(s) cadastrado(s).\n",TotalElemento);
        while( auxiliar_cabeca != 0){
            printf("******* Dados Cadastrados na Lista *******\n");
            printf("NOME: %s\n", auxiliar_cabeca->nome); printf("IDADE: %d\n",auxiliar_cabeca->idade);
                printf("SEXO: %c\n", auxiliar_cabeca->sexo);
            printf("--------------------------------------------------\n"); auxiliar_cabeca = auxiliar_cabeca->proximo_no;
        }
        
    }
}
    //FUNÇÃO QUE REMOVE O NÓ DA LISTA
    void RemoveNoLista(NO_LISTA *cabeca){
        if (TotalElemento<1){
            printf("Impossível remover. A lista está vazia!\n");
        }else{
            NO_LISTA *remove_no = cabeca;
            NO_LISTA *no_anterior = cabeca;
       
        while( remove_no->proximo_no != 0){
                no_anterior = remove_no;
                remove_no = remove_no->proximo_no;
        }

                printf("\n******* Cadastro Removido Com sucesso!");
               printf("Nome: %s\n", remove_no->nome);
               printf("Idade: %d\n", remove_no->idade);
                printf("Sexo: %c\n", remove_no->sexo);
               printf("--------------------------------------------------\n");
            no_anterior->proximo_no = 0;
               
               }
    }
            
               
        int main(){
            //setlocale(LC_ALL, "Portuguese");
            NO_LISTA *cabeca = 0;
            int idade, op = 0;
            char sexo, nome[200];
            
            while (op!= 4) {
                //system("cls");
                printf("****** ESTRUTURA DE DADOS - LISTA ****** \n\n");
                printf("Digite um [1] - Cadastrar\n");
                printf("Digite um [2] - Exibir\n");
                printf("Digite um [3] - Remover\n");
                printf("Digite um [4] - Sair\n");
                
                printf("Escolha sua opção\n");
                scanf("%d",&op);
                
                switch (op) {
                    case 1:
                        printf("\n Realizando Cadastro: \n");
                        printf("Digite o nome:");
                        scanf("%s",&nome);
                        
                        printf("Digite a idade:");
                        scanf("%d",&idade);
                        
                        printf("Digite o sexo:");
                        scanf("%s",&sexo);
                        
                        InsereNaLista(&cabeca, nome, idade, sexo);
                        
                    break;
                        
                    case 2:
                        ExibeLista(cabeca);
                    break;
                        
                    case 3:
                        RemoveNoLista(cabeca);
                    break;
                        
                    case 4:
                        printf("Você escolheu sair!");
                        exit(0);
                    break;
                        
                    default:
                        printf("Opcao errada!");
                    break;
                
                }
                
            }
        
        }

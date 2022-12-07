#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (){

    int sessao; //variavel para saber o nÂ° de sessoes
    int quantidade_de_pessoas = 0; 
    int quantidade_de_pessoas_do_sexoM = 0;
    int quantidade_de_pessoas_do_sexoF = 0;
    int i,j;
    int inteira = 0, meia = 0;
    char sexo;
    int criancas = 0, adolescentes = 0, adultos = 0, idosos = 0, idade = 0;
    char tipo_de_ingresso[10];
    int valor_total = 0;

    while (sessao != 2){  //para exigir duas sessÃµes, enquanto for digitado algo diferente de 2 a pergunta se repitirÃ¡. 
        printf("Informe a quantidade de sessoes:\n");
        scanf("%d",&sessao);
    }

for (sessao = 0; sessao = 2; i++){

    while (quantidade_de_pessoas <5){ //para exigir que sejam no minÃ­mo 10 pessoas, enquanto digitar um nÃºmero menor que 10, a pergunta se repitirÃ¡.
        printf("Quantas pessoas: \n");
        scanf("%d",&quantidade_de_pessoas);
    }
    
    for (i=1; i <= quantidade_de_pessoas; i++){ //este for irÃ¡ funcinar para todas as prÃ³ximas perguntas, garantindo que as mesmas sejam feitas para quantas pessoas for preciso
        printf("\nQual seu sexo:");
        scanf(" %c",&sexo);
 
        while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f'){ //este "for" serve para garantir que Ã± seja digitado nda difeirente dos caracteres exigidos. 
            printf("\nQual seu sexo:");                                  //Por isso a lÃ³gica tem de ser diferente de, e deve ser utilizado o "&" para garantir todas as condiÃ§Ãµes.
            scanf(" %c",&sexo); //aqui o espaÃ§o antes do "%c", serve para garantir que o "/n" Ã± seja lido com carater, o que daria erro no cÃ³digo.
        }
    
        if (sexo == 'M' || sexo == 'm'){ //este "if" serve para contabilizar o nÃºmero de pessoas de cada sexo
            quantidade_de_pessoas_do_sexoM++;
        }else if (sexo == 'F' || sexo == 'f'){
            quantidade_de_pessoas_do_sexoF++;
        }
       
	do{
       printf("\nQual sua idade:"); //aqui comeÃ§amos a coletar a idade dos clientes 
       scanf("%d",&idade);

    }while (idade <= 2); //este "while" serve para validar a idade, uma vez que Ã± pode ser negativa nem zerada.
        //printf("\nQual sua idade:");
        //scanf("%i",&idade);

        if (idade >= 3 && idade <= 13){  //aqui entramos no "if" de classificaÃ§Ã£o das idades e jÃ¡ contabilizamos cada uma das classificaÃ§Ãµes.
            criancas++;
        }else if (idade >= 14 && idade <= 17){
           adolescentes++;
        }else if (idade >= 18 && idade <= 64){
            adultos++;
        }else if (idade >= 65 && idade <= 100){
            idosos++;
        }     
        else{
            printf("Idade invalida!");
        }   
       
  
    do //foi usado o "do while" porque acreditamos que ele caberia melhor com as prÃ³ximas estrututras desenvolvidas
    {
           printf("\nO ingresso sera Meia ou Inteira?");  //aqui perguntamos qual o tipo de ingresso
           scanf("%s",&tipo_de_ingresso);       
    
            for( j = 0; j < strlen(tipo_de_ingresso); j++){ //este "for" foi usado para validar qualquer forma que o usuario digitasse as strings requeridas, passando inteira e meia para o minusculo.
                tipo_de_ingresso[j] = tolower(tipo_de_ingresso[j]); //foi preciso passar letra por letra das strings inteira e meia para minusculas, uma vz que a lingugem C,Ã± faz comparaÃ§Ã£o de estrings
            }

    }while (strcmp(tipo_de_ingresso, "inteira") && strcmp(tipo_de_ingresso, "meia")); //como a linguagem C, Ã± faz comparaÃ§Ã£o entre strings, foi prciso usar essa funÃ§Ã£o de string para comparar os tipos de ingresso.

        if (tipo_de_ingresso[0] == 'i'){  //foi usado um vetor para comparar se a primeira letra Ã©️ "i", pois assim jÃ¡ sabemos que serÃ¡ inteira 
            valor_total = valor_total + 50; //aqui Ã©️ onde somamos o valor dos ingressos por tipo 
            inteira = inteira + 1; //aqui contabilizamos quantas interias apareceram 
        }else{ //como o "if" ja verifica se Ã©️ inteira, qualquer outra coisa digitada e aceita serÃ¡ meia.
            valor_total = valor_total + 25;
            meia = meia + 1;
        }

    }

}
    


    printf("A quantidade de pessoas do sexo masculino foi: %i \n A quantidade de pessoas do sexo feminino: %i",quantidade_de_pessoas_do_sexoM, quantidade_de_pessoas_do_sexoF);
    printf("\nA quantidade de idosos foi: %i \n A quantidade de crianca foi: %i \n A quantidade de adolescnete foi: %i \n A quantidade de adulto foi: %i", idosos, criancas, adolescentes, adultos);
    printf("\nO valor total arrecado na sessao foi de R$%i\n", valor_total);

    
    if ("inteira" > "meia"){
        printf("\nHouveram mais inteiras");
    }else{
        printf("\nHouveram mais meias");
    }

return 0;}
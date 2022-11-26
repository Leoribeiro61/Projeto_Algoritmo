#include <stdio.h>

int main (){

    int sessao; 
    int quantidade_de_pessoas = 0;
    int quantidade_de_pessoas_do_sexoM = 0;
    int quantidade_de_pessoas_do_sexoF = 0;
    int i;
    char sexo;
    int criancas = 0, adolescentes = 0, adultos = 0, idosos = 0, idade;

    while (sessao != 2){
        printf("Informe a quantidade de sessoes:\n");
        scanf("%i",&sessao);
    }

    while (quantidade_de_pessoas <10){
        printf("Quantas pessoas:\n");
        scanf("%i",&quantidade_de_pessoas);
    }
    

    for (i=1; i<= quantidade_de_pessoas; i++){
        printf("Qual seu sexo:\n");
        scanf(" %c",&sexo);

        if (sexo == 'M'){
            quantidade_de_pessoas_do_sexoM++;
        }else{
            quantidade_de_pessoas_do_sexoF++;
        }

        printf("Qual sua idade:\n");
        scanf("%i",&idade);

        if (idade >3 && idade <=13){
            criancas++;
        }else if (idade >13 && idade <=17){
           adolescentes++;
        }else if (idade >17 && idade <=64){
            adultos++;
        }else {
            idosos++;
        }             
       
    }

    printf("qtd crianca:%i         qtd adultos:%i      ", criancas,adultos);


    
}
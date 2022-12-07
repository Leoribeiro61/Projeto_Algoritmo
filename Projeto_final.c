//Vinicius Arantes Leao - UC22200223 - Ciencias da Computacao; Leonardo Ribeiro De Macedo - UC22200681 - Ciencia da computacao; Maria Rafaela Alves Azevedo De Jesus - UC22200231 - Analise e desenvolvimento de sistemas
#include <stdio.h> // cabeçalho padrão de entrada e saída
#include <string.h> // manipulação de cadeia de caracteres
#include <ctype.h> // manipulação de caracteres
#include<locale.h> // adaptaçoes para o idioma português 

int main (){ // função principal para o inicio do código  

    int sessao; //variavel para saber o número de sessoes
    int quantidade_de_pessoas = 0; 
    int quantidade_de_pessoas_do_sexoM = 0;
    int quantidade_de_pessoas_do_sexoF = 0;
    int i,j,k;
    int inteira = 0, meia = 0;
    char sexo;
    int criancas = 0, adolescentes = 0, adultos = 0, idosos = 0, idade = 0;
    char tipo_de_ingresso[10];
    int valor_total = 0;
    char filme[100];
    int adultoM = 0, adultoF = 0; 
    
    setlocale(LC_ALL, "Portuguese"); // serve para usar o idioma português 

    while (sessao != 2){  //para exigir duas sessões, enquanto for digitado algo diferente de 2 a pergunta se repete. 
        printf("Informe a quantidade de sessões: \n"); //mostrar algo na tela
        scanf("%d",&sessao); //ler dados do usuário 
    }
	for (k=1; k<=sessao; k++){ // o "K" é uma variável de auxílio para adquirir os dados das duas sessões
	
		printf("Qual o nome do filme que deseja assistir na %dª sessão: \n", k);
		fflush(stdin); //limpa o buffer antes da leitura
		scanf("%[^\n]s", filme); //"%[^\n]s" ler string com "espaço"
		
		
    	while (quantidade_de_pessoas <10){ //para exigir que sejam no mínimo 10 pessoas, enquanto digitar um número menor que 10, a pergunta se repete.
        	printf("Quantas pessoas na %dª sessão: \n", k);
        	scanf("%d",&quantidade_de_pessoas);
    	}
    
    for (i=1; i <= quantidade_de_pessoas; i++){ //este for irá funcinar para todas as próximas perguntas, garantindo que as mesmas sejam feitas para quantas pessoas for preciso
        printf("Qual o sexo do %dº cliente (M - masculino) e (F - feminino) : \n", i);
        fflush(stdin);
        scanf(" %c",&sexo);
 
        while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f'){ //este "while" serve para garantir que a única letra lida seja "m" ou "f". 
            printf("Qual o sexo do %dº cliente (M - masculino) e (F - feminino) : \n", i);                                 
            scanf(" %c",&sexo); //aqui o espaço antes do "%c", serve para garantir que o "/n" não seja lido com carater, o que daria erro no código.
        }
    
        if (sexo == 'M' || sexo == 'm'){ //este "if" serve para contabilizar o número de pessoas de cada sexo
            quantidade_de_pessoas_do_sexoM++;
        }else if (sexo == 'F' || sexo == 'f'){
            quantidade_de_pessoas_do_sexoF++;
        }
       
	do{
       printf("Qual a idade do %dº cliente : \n", i); //aqui começamos a coletar a idade dos clientes 
       scanf("%d",&idade);

    }while (idade <= 2 || idade > 100); //este "while" serve para validar a idade, uma vez que não pode ser negativa nem zerada.

        if (idade >= 3 && idade <= 13){  //aqui entramos no "if" de classificação das idades e já contabilizamos cada uma das classificações.
            criancas++;
        }else if (idade >= 14 && idade <= 17){
           adolescentes++;
        }else if (idade >= 18 && idade <= 64){
            adultos++;
            if (sexo == 'M' || sexo == 'm'){ //esse "if" serve para contabilizar pessoas do sexo masculino maiores de 18 anos.
            	adultoM++;
			}
			else if(sexo == 'F' || sexo == 'f'){//esse "if" serve para contabilizar pessoas do sexo feminino maiores de 18 anos.
				adultoF++;
			}
        }else if (idade >= 65 && idade <= 100){
            idosos++;
            if (sexo == 'M' || sexo == 'm'){//esse "if" serve para contabilizar pessoas do sexo masculino maiores de 18 anos.
            	adultoM++;
			}
			else if(sexo == 'F' || sexo == 'f'){//esse "if" serve para contabilizar pessoas do sexo feminino maiores de 18 anos.
				adultoF++;
			}
        }     
        else{
            printf("Idade inválida! \n");
        }   
       
  
    do //foi usado o "do while" porque acreditamos que ele caberia melhor com as próximas estrututras desenvolvidas
    {
           printf("O ingresso será Meia ou Inteira? \n");  //aqui perguntamos qual o tipo de ingresso
           scanf("%s",&tipo_de_ingresso);       
    
            for( j = 0; j < strlen(tipo_de_ingresso); j++){ //este "for" foi usado para validar qualquer forma que o usuario digitasse as strings requeridas, passando inteira e meia para o minusculo.
                tipo_de_ingresso[j] = tolower(tipo_de_ingresso[j]); //foi preciso passar letra por letra das strings inteira e meia para minusculas, uma vez que a linguagem C,não faz comparação de em strings
            }

    }while (strcmp(tipo_de_ingresso, "inteira") && strcmp(tipo_de_ingresso, "meia")); //como a linguagem C, não faz comparação entre strings, foi preciso usar essa função de string para comparar os tipos de ingresso.

        if (tipo_de_ingresso[0] == 'i'){  //foi usado um vetor para comparar se a primeira letra é "i", assim sabemos que será inteira 
            valor_total = valor_total + 50; //aqui é onde somamos o valor dos ingressos por tipo 
            inteira = inteira + 1; //aqui contabilizamos quantas interias apareceram 
        }else{ //como o "if" ja verifica se é inteira, qualquer outra coisa digitada e aceita será meia.
            valor_total = valor_total + 25;
            meia = meia + 1;
        } 
		
    }
		
    printf("A quantidade de pessoas do sexo masculino foi: %d \n", quantidade_de_pessoas_do_sexoM);// esses "printf" mostram os dados lidos de cada uma das sessões
    
	printf("A quantidade de pessoas do sexo feminino foi: %d \n",quantidade_de_pessoas_do_sexoF);
	
	printf("O nome do filme é: %s \n", filme);
    
	printf("A quantidade de crianças foi: %d \n", criancas); 
	
	printf("A quantidade de adolescente foi: %d \n", adolescentes);
	
	printf("A quantidade de adulto foi: %d \n", adultos);
	
	printf("A quantidade de idosos foi: %d \n", idosos);
	
    printf("O valor total arrecado na sessão foi de R$%d \n", valor_total);
    
    printf("O público masculino maior que 18 foi: %d \n", adultoM);
    
    printf("O público feminino maior que 18 foi: %d \n", adultoF);
    
    printf("Quantidade de inteiras: %d \n", inteira); // nova funcionalidade que printa a quantidade de inteiras pagas.
    
    printf("Quantidade de meias: %d \n", meia); // nova funcionalidade que printa a quantidade de meias pagas.

    if (meia > inteira){// este "if" verifica se houve mais pagamentos de meia ou inteira
		printf("Houveram mais pagamentos de meia entrada \n");
	} else if (meia == inteira){
		printf("A quantidade de pagamentos de meias e inteiras foram iguais \n"); // este "else if" serve para verificar se houve a mesma quantidade de meias e inteiras(nova funcionalidade)
	}
		else printf("Houveram mais pagamentos de inteiras \n");
    
// aqui as variáveis são zeradas para que não sejam somadas os valores da sessao 1 com os valores da sessao 2 na interação 2. 

    quantidade_de_pessoas = 0;
    quantidade_de_pessoas_do_sexoM = 0;
    quantidade_de_pessoas_do_sexoF = 0;
    criancas = 0;
	adolescentes = 0;
	adultos = 0;
	idosos = 0;
	adultoM = 0; 
	adultoF = 0;
	valor_total = 0;
	inteira = 0; 
	meia = 0;
}
return 0;}
/* Faca um programa para ler e escrever na tela os seguinte dados: */ 
/* nome, endereco, telefone, cidade, cep */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

	char nome[100], endereco[100], cidade[100], tel[12], cep[10];
		
	printf("Digite seu nome:\n");
	gets(nome);

	printf("Digite seu endereço:\n");
	gets(endereco);

	printf("Digite o numero seu telefone:\n");
	gets(tel);

	printf("Digite sua cidade:\n");
	gets(cidade);
	
	printf("Digite seu CEP:\n");
	gets(cep);

	printf("Cadastro concluido:\n Nome: %s\n Endereco: %s\n Telefone: %s\n Cidade: %s\n CEP: %s\n", nome, endereco, tel, cidade, cep);

	getchar();
	
}

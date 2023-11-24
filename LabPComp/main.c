#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int insercao(int n, int v[])
{
   long int pesforco = 0;
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i){
         v[i+1] = v[i];// COMANDO A SER CONTABILIZADO
         pesforco++;
      }
      v[i+1] = x;
   }
   return pesforco;
}


long int bs(int n, int *vetor) {
	int c = 0, d, troca, trocou = 1;
    long int pesforco = 0;
	while ((c < (n - 1)) & trocou) {
		trocou = 0;
		for (d = 0; d < n - c - 1; d++){
            pesforco++;
			if (vetor[d] > vetor[d + 1]) { // COMANDO A SER CONTABILIZADO
				troca = vetor[d];
				vetor[d] = vetor[d + 1];
				vetor[d + 1] = troca;
				trocou = 1;
			}
		}
		c++;
	}
}

int *gera_vet_aleatorio(int pn){
    int *pvet = (int *)malloc(sizeof(int)*pn);
    int pind;
    for(pind=0;pind<pn;pind++)
        pvet[pind] = rand();

    return pvet;
}

void opcaoT(FILE *pArqTeste, FILE *pArqComp) {
    int n;
    long int eB, eI;
    while (!feof(pArqTeste)) {
        fscanf(pArqTeste, "%d", &n);
        int *V = gera_vet_aleatorio(n);
        eB = bs(n, V) / n;
        eI = insercao(n, V) / n;
        fprintf(pArqComp, "[%d, %ld, %ld]\n", n, eB, eI);
        free(V); // Liberar memória alocada dinamicamente
    }
    printf("Esforço gerado com sucesso\n");
}




int main() {
    FILE *pArqTeste, *pArqComp;
    char opcao;
    pArqTeste = fopen("testes.txt", "r");
    pArqComp = fopen("esforcocompucaional.txt", "w+");  
    if (!pArqTeste || !pArqComp) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    while (1) {
        printf("\nEscolha uma opcao: ");
        printf("\nT - Gerar esforcocomputacional.txt");
        printf("\nR - Ler esforcocomputacional.txt");
        printf("\nS - Sair\n");
        scanf(" %c", &opcao);

        switch (opcao) {
        case 'T':
            opcaoT(pArqTeste, pArqComp);
            fseek(pArqTeste, 0, SEEK_SET); // Voltar para o início do arquivo de teste
            break;
        case 'R':
            //opcaoR(pArqComp);
            break;
        case 'S':
            fclose(pArqTeste);
            fclose(pArqComp);
            return 0;
        default:
            printf("Opcao invalida. Escolha novamente.\n");
        }
    }
} 
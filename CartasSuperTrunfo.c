#include <stdio.h>
#include <string.h> // Necessário para funções de string como strcpy, embora não seja estritamente necessário para este desafio

// Define o tamanho máximo para o nome da cidade e outros arrays de caracteres
#define TAM_NOME_CIDADE 50
#define TAM_CODIGO_CARTA 4 // 3 caracteres (Ex: A01) + 1 para o terminador nulo '\0'

// 1. Definição da Estrutura de Dados (A Carta)
// Agrupa todas as propriedades da cidade em um único tipo.
struct CartaCidade {
    char estado;                      // 'A' a 'H'
    char codigo_carta[TAM_CODIGO_CARTA]; // Ex: "A01"
    char nome_cidade[TAM_NOME_CIDADE]; // Nome da cidade
    long populacao;                   // População (usando long para números grandes)
    float area_km2;                   // Área em km²
    float pib_bilhoes;                // PIB (em bilhões de moeda local/reais)
    int num_pontos_turisticos;        // Quantidade de pontos turísticos
};

// Protótipo da função para exibir os dados de uma carta
void exibir_carta(int numero_carta, struct CartaCidade carta);

int main() {
    // Declaração das variáveis para duas cartas (requisito mínimo)
    struct CartaCidade carta1, carta2;

    printf("==========================================\n");
    printf("   SISTEMA DE CADASTRO DE CARTAS (NOVIÇO)\n");
    printf("        Tema: Cidades dos Países\n");
    printf("==========================================\n");

    // --- CADASTRO DA CARTA 1 ---
    printf("\n--- INSERIR DADOS DA CARTA 1 ---\n");

    printf("Estado (A-H): ");
    // O ' %c' ignora espaços em branco ou novas linhas antes de ler o char
    scanf(" %c", &carta1.estado); 

    printf("Código da Carta (3 caracteres, Ex: A01): ");
    // Limita a leitura a 3 caracteres + \0
    scanf("%3s", carta1.codigo_carta); 

    printf("Nome da Cidade (sem espaços): ");
    // Lê até 49 caracteres, parando no primeiro espaço
    scanf("%49s", carta1.nome_cidade); 

    printf("População (Ex: 12345678): ");
    // Usa %ld para ler um long int
    scanf("%ld", &carta1.populacao);

    printf("Área (em km², Ex: 1521.11): ");
    scanf("%f", &carta1.area_km2);

    printf("PIB (em bilhões, Ex: 699.28): ");
    scanf("%f", &carta1.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);


    // --- CADASTRO DA CARTA 2 ---
    printf("\n\n--- INSERIR DADOS DA CARTA 2 ---\n");

    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado); 

    printf("Código da Carta (3 caracteres, Ex: B02): ");
    scanf("%3s", carta2.codigo_carta); 

    printf("Nome da Cidade (sem espaços): ");
    scanf("%49s", carta2.nome_cidade);

    printf("População (Ex: 6748000): ");
    scanf("%ld", &carta2.populacao);

    printf("Área (em km², Ex: 1200.25): ");
    scanf("%f", &carta2.area_km2);

    printf("PIB (em bilhões, Ex: 300.50): ");
    scanf("%f", &carta2.pib_bilhoes);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);


    // --- EXIBIÇÃO DOS DADOS CADASTRADOS ---
    printf("\n\n==========================================\n");
    printf("   RELATÓRIO DE CARTAS CADASTRADAS\n");
    printf("==========================================\n");

    // Exibe os dados da primeira carta
    exibir_carta(1, carta1);

    // Exibe os dados da segunda carta
    exibir_carta(2, carta2);
    
    printf("\n--- FIM DO PROGRAMA ---\n");

    return 0; 
}

/**
 * @brief Exibe os dados de uma carta formatados de forma clara e organizada.
 * * @param numero_carta O número sequencial da carta (1, 2, etc.).
 * @param carta A estrutura CartaCidade a ser exibida.
 */
void exibir_carta(int numero_carta, struct CartaCidade carta) {
    printf("\n------------------------------------------\n");
    printf("✅ Carta %d: %s\n", numero_carta, carta.nome_cidade);
    printf("------------------------------------------\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo_carta);
    printf("População: %ld habitantes\n", carta.populacao);
    // %.2f formata o float com 2 casas decimais
    printf("Área: %.2f km²\n", carta.area_km2);
    printf("PIB: %.2f bilhões (unidade local)\n", carta.pib_bilhoes);
    printf("Pontos Turísticos: %d\n", carta.num_pontos_turisticos);
}
#include <stdio.h>
#include <stdlib.h>

// Função para liberar a memória alocada para a imagem
void liberarImagem(unsigned char **imagemR, unsigned char **imagemG, unsigned char **imagemB, int altura)
{
    for (int i = 0; i < altura; i++)
    {
        free(imagemR[i]);
        free(imagemG[i]);
        free(imagemB[i]);
    }
    free(imagemR);
    free(imagemG);
    free(imagemB);
}

// Função para alocar dinamicamente as matrizes R, G e B
void alocarMatrizesRGB(int largura, int altura, unsigned char ***imagemR, unsigned char ***imagemG, unsigned char ***imagemB)
{
    // Aloca o vetor de ponteiros para as linhas das matrizes R, G e B
    *imagemR = (unsigned char **)malloc(altura * sizeof(unsigned char *));
    *imagemG = (unsigned char **)malloc(altura * sizeof(unsigned char *));
    *imagemB = (unsigned char **)malloc(altura * sizeof(unsigned char *));

    // Verifica se a alocação foi bem sucedida
    if (!(*imagemR) || !(*imagemG) || !(*imagemB))
    {
        fprintf(stderr, "Erro de alocação de memória para as matrizes R, G e B\n");
        exit(1); // Encerra o programa em caso de erro
    }

    // Para cada linha, aloca um vetor de bytes para os pixels R, G e B
    for (int i = 0; i < altura; i++)
    {
        (*imagemR)[i] = (unsigned char *)malloc(largura * sizeof(unsigned char));
        (*imagemG)[i] = (unsigned char *)malloc(largura * sizeof(unsigned char));
        (*imagemB)[i] = (unsigned char *)malloc(largura * sizeof(unsigned char));

        // Verifica se a alocação foi bem sucedida
        if (!(*imagemR)[i] || !(*imagemG)[i] || !(*imagemB)[i])
        {
            fprintf(stderr, "Erro de alocação de memória para as linhas das matrizes R, G e B\n");

            // Libera as linhas já alocadas antes do erro
            for (int j = 0; j < i; j++)
            {
                free((*imagemR)[j]);
                free((*imagemG)[j]);
                free((*imagemB)[j]);
            }

            // Libera o vetor de ponteiros para as linhas
            free(*imagemR);
            free(*imagemG);
            free(*imagemB);

            exit(1); // Encerra o programa em caso de erro
        }
    }
}

// Função para carregar uma imagem a partir de um arquivo
void carregarImagem(const char *nomeArquivo, int *largura, int *altura, unsigned char ***imagemR, unsigned char ***imagemG, unsigned char ***imagemB)
{
    // Abre o arquivo para leitura
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        fprintf(stderr, "Erro ao abrir o arquivo de imagem\n");
        exit(1); // Encerra o programa em caso de erro
    }

    char formato[3];
    fscanf(arquivo, "%s\n%d %d\n", formato, largura, altura); // Lê o formato, largura e altura da imagem

    // Verifica o formato da imagem
    if (formato[0] != 'P' || formato[1] != '3')
    {
        fprintf(stderr, "Formato de imagem não suportado\n");
        fclose(arquivo);
        exit(1); // Encerra o programa em caso de erro
    }

    // Chama a função para alocar dinamicamente as matrizes R, G e B
    alocarMatrizesRGB(*largura, *altura, imagemR, imagemG, imagemB);

    // Lê os pixels R, G e B da imagem do arquivo
    for (int i = 0; i < *altura; i++)
    {
        for (int j = 0; j < *largura; j++)
        {
            fscanf(arquivo, "%hhu %hhu %hhu", &((*imagemR)[i][j]), &((*imagemG)[i][j]), &((*imagemB)[i][j]));
        }
    }

    fclose(arquivo); // Fecha o arquivo após a leitura
}

// Função para salvar uma imagem em um arquivo
void salvarImagem(const char *nomeArquivo, unsigned char **imagemR, unsigned char **imagemG, unsigned char **imagemB, int largura, int altura)
{
    // Abre o arquivo para escrita binária
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (!arquivo)
    {
        fprintf(stderr, "Erro ao criar arquivo de imagem\n");
        exit(1); // Encerra o programa em caso de erro
    }

    // Escreve o cabeçalho da imagem no arquivo
    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d %d\n255\n", largura, altura);

    // Escreve os pixels R, G e B da imagem no arquivo
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            fprintf(arquivo, "%d %d %d ", imagemG[i][j], imagemB[i][j], imagemR[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo); // Fecha o arquivo após a escrita
}

// Função para interpolar uma imagem usando 1-vizinhança
void interpolarImagem1Vizinhanca(unsigned char **entradaR, unsigned char **entradaG, unsigned char **entradaB, int largura, int altura, float m, float n, unsigned char ***saidaR, unsigned char ***saidaG, unsigned char ***saidaB)
{
    int novaLargura = (int)(largura * m);
    int novaAltura = (int)(altura * n);

    // Aloca memória para as matrizes de saída (imagem interpolada)
    *saidaR = (unsigned char **)malloc(novaAltura * sizeof(unsigned char *));
    *saidaG = (unsigned char **)malloc(novaAltura * sizeof(unsigned char *));
    *saidaB = (unsigned char **)malloc(novaAltura * sizeof(unsigned char *));

    // Verifica se a alocação foi bem sucedida
    if (!(*saidaR) || !(*saidaG) || !(*saidaB))
    {
        fprintf(stderr, "Erro de alocação de memória para a imagem interpolada\n");
        exit(1); // Encerra o programa em caso de erro
    }

    // Chama a função para alocar dinamicamente as matrizes R, G e B para a imagem interpolada
    alocarMatrizesRGB(novaLargura, novaAltura, saidaR, saidaG, saidaB);

    // Loop para percorrer todos os pixels da imagem interpolada
    for (int y = 0; y < novaAltura; y++)
    {
        for (int x = 0; x < novaLargura; x++)
        {
            // Calcula as coordenadas na imagem original correspondentes ao pixel (x, y) da imagem interpolada
            float origemX = (float)x / novaLargura * largura;
            float origemY = (float)y / novaAltura * altura;

            // Determina os índices dos pixels na imagem original para interpolação usando 1-vizinhança
            int x0 = (int)origemX;
            int y0 = (int)origemY;
            int x1 = (x0 + 1) % largura;
            int y1 = y0;
            float fracX = origemX - x0;
            float fracY = origemY - y0;

            // Interpolação bilinear para cada canal de cor (R, G, B)
            (*saidaR)[y][x] = (1 - fracX) * (1 - fracY) * entradaR[y0][x0] +
                              fracX * (1 - fracY) * entradaR[y0][x1] +
                              (1 - fracX) * fracY * entradaR[y1][x0] +
                              fracX * fracY * entradaR[y1][x1];

            (*saidaG)[y][x] = (1 - fracX) * (1 - fracY) * entradaG[y0][x0] +
                              fracX * (1 - fracY) * entradaG[y0][x1] +
                              (1 - fracX) * fracY * entradaG[y1][x0] +
                              fracX * fracY * entradaG[y1][x1];

            (*saidaB)[y][x] = (1 - fracX) * (1 - fracY) * entradaB[y0][x0] +
                              fracX * (1 - fracY) * entradaB[y0][x1] +
                              (1 - fracX) * fracY * entradaB[y1][x0] +
                              fracX * fracY * entradaB[y1][x1];
        }
    }
}

// Função para interpolar uma imagem usando 4-vizinhança
void interpolarImagem4Vizinhanca(unsigned char **entradaR, unsigned char **entradaG, unsigned char **entradaB, int largura, int altura, float m, float n, unsigned char ***saidaR, unsigned char ***saidaG, unsigned char ***saidaB)
{
    int novaLargura = (int)(largura * m);
    int novaAltura = (int)(altura * n);

    // Aloca memória para as matrizes de saída (imagem interpolada)
    *saidaR = (unsigned char **)malloc(novaAltura * sizeof(unsigned char *));
    *saidaG = (unsigned char **)malloc(novaAltura * sizeof(unsigned char *));
    *saidaB = (unsigned char **)malloc(novaAltura * sizeof(unsigned char *));

    // Verifica se a alocação foi bem sucedida
    if (!(*saidaR) || !(*saidaG) || !(*saidaB))
    {
        fprintf(stderr, "Erro de alocação de memória para a imagem interpolada\n");
        exit(1); // Encerra o programa em caso de erro
    }

    // Chama a função para alocar dinamicamente as matrizes R, G e B para a imagem interpolada
    alocarMatrizesRGB(novaLargura, novaAltura, saidaR, saidaG, saidaB);

    // Loop para percorrer todos os pixels da imagem interpolada
    for (int y = 0; y < novaAltura; y++)
    {
        for (int x = 0; x < novaLargura; x++)
        {
            // Calcula as coordenadas na imagem original correspondentes ao pixel (x, y) da imagem interpolada
            float origemX = (float)x / novaLargura * largura;
            float origemY = (float)y / novaAltura * altura;

            // Determina os índices dos pixels na imagem original para interpolação usando 4-vizinhança
            int x0 = (int)origemX;
            int y0 = (int)origemY;
            int x1 = (x0 + 1) % largura;
            int y1 = (y0 + 1) % altura;
            float fracX = origemX - x0;
            float fracY = origemY - y0;

            // Interpolação bilinear para cada canal de cor (R, G, B)
            (*saidaR)[y][x] = (1 - fracX) * (1 - fracY) * entradaR[y0][x0] +
                              fracX * (1 - fracY) * entradaR[y0][x1] +
                              (1 - fracX) * fracY * entradaR[y1][x0] +
                              fracX * fracY * entradaR[y1][x1];

            (*saidaG)[y][x] = (1 - fracX) * (1 - fracY) * entradaG[y0][x0] +
                              fracX * (1 - fracY) * entradaG[y0][x1] +
                              (1 - fracX) * fracY * entradaG[y1][x0] +
                              fracX * fracY * entradaG[y1][x1];

            (*saidaB)[y][x] = (1 - fracX) * (1 - fracY) * entradaB[y0][x0] +
                              fracX * (1 - fracY) * entradaB[y0][x1] +
                              (1 - fracX) * fracY * entradaB[y1][x0] +
                              fracX * fracY * entradaB[y1][x1];
        }
    }
}

// Função principal
int main(void)
{
    float m, n; // Constantes de proporcionalidade
    char nomeArquivo[100]; // Nome do arquivo de entrada

    // Solicita ao usuário os valores de m e n
    printf("Digite o valor de m (constante de proporcionalidade em relação à largura): ");
    scanf("%f", &m);

    printf("Digite o valor de n (constante de proporcionalidade em relação à altura): ");
    scanf("%f", &n);

    printf("Insira o nome do arquivo: \n");
    scanf("%s", nomeArquivo);

    int largura, altura; // Variáveis para armazenar a largura e altura da imagem
    unsigned char **imagemR; // Matriz para o canal R da imagem
    unsigned char **imagemG; // Matriz para o canal G da imagem
    unsigned char **imagemB; // Matriz para o canal B da imagem

    // Carrega a imagem do arquivo especificado
    carregarImagem(nomeArquivo, &largura, &altura, &imagemR, &imagemG, &imagemB);

    // Variáveis para as imagens interpoladas (1-vizinhança e 4-vizinhança)
    unsigned char **imagemInterpoladaR1;
    unsigned char **imagemInterpoladaG1;
    unsigned char **imagemInterpoladaB1;
    unsigned char **imagemInterpoladaR4;
    unsigned char **imagemInterpoladaG4;
    unsigned char **imagemInterpoladaB4;

    // Interpolação usando 1-vizinhança
    interpolarImagem1Vizinhanca(imagemR, imagemG, imagemB, largura, altura, m, n, &imagemInterpoladaR1, &imagemInterpoladaG1, &imagemInterpoladaB1);
    salvarImagem("1vizinhanca.ppm", imagemInterpoladaR1, imagemInterpoladaG1, imagemInterpoladaB1, largura * m, altura * n);

    // Interpolação usando 4-vizinhança
    interpolarImagem4Vizinhanca(imagemR, imagemG, imagemB, largura, altura, m, n, &imagemInterpoladaR4, &imagemInterpoladaG4, &imagemInterpoladaB4);

    // Salva as imagens interpoladas em arquivos diferentes
    salvarImagem("4vizinhanca.ppm", imagemInterpoladaR4, imagemInterpoladaG4, imagemInterpoladaB4, largura * m, altura * n);

    // Libera a memória alocada para as imagens
    liberarImagem(imagemR, imagemG, imagemB, altura);
    liberarImagem(imagemInterpoladaR1, imagemInterpoladaG1, imagemInterpoladaB1, altura * n);
    liberarImagem(imagemInterpoladaR4, imagemInterpoladaG4, imagemInterpoladaB4, altura * n);

    return 0; // Retorna 0 indicando que o programa encerrou com sucesso
}

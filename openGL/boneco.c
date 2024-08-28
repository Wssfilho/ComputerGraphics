#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

// Declaração das variáveis para controle dos ângulos de cada parte do robô, sendo os dedos inicializados com graus diferente
static GLint ombroEsq = 30, cotoveloEsq = 0, maoEsq = 0;
static GLint ombroDir = -30, cotoveloDir = 0, maoDir = 0;
static GLint pernaEsq = 0, joelhoEsq = 0;
static GLint pernaDir = 0, joelhoDir = 0;
static GLint cabeca = 0, pescoco = 0, tronco = 0;
static GLint dedo1Esq = 0, dedo2Esq = 0, dedo1Esq2 = -45, dedo2Esq2 = 45, dedo1Esq3 = 45, dedo2Esq3 = -45;
static GLint dedo1Dir = 0, dedo2Dir = 0, dedo1Dir2 = 45, dedo2Dir2 = -45, dedo1Dir3 = -45, dedo2Dir3 = 45;

void DesenhaTexto(char * string, float x, float y) //funcão para formatar e inserir texto n atela
{
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glRasterPos2f(x, y);
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
    glPopMatrix();
}

void DesenhaQuadradoBrc(float R, float G, float B) //float R, float G, float B
{
    glColor3f(R, G, B);
    //desenha um quadrado com as coordenadas dos vertices. Recebe RGB para definir a cor.

    glBegin(GL_POLYGON); //desenha um poligono qudrado
        glVertex2f(-1, 1);
        glVertex2f(-1, -1);
        glVertex2f(1, -1);
        glVertex2f(1, 1);
    glEnd();
}

void DesenhaQuadradoCrp(float R, float G, float B) //float R, float G, float B
{
    //idem a funcao DesenhaQuadradoBrc, mas separado para evitar possiveis erros de sobreposicao
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
        glVertex2f(-1, 1);
        glVertex2f(-1, -1);
        glVertex2f(1, -1);
        glVertex2f(1, 1);
    glEnd();
}

void DesenhaHexa(float R, float G, float B) //desenha um exagono para formar a cabeça
{
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
        glVertex2f(0.5f, 2.0f);   // Top-right //em inglês por conta do site de referencia de estudo
        glVertex2f(-0.5f, 2.0f);  // Top-left
        glVertex2f(-0.5f, 1.2f);  // Left
        glVertex2f(-0.2f, 0.2f); // Bottom-left
        glVertex2f(0.2f, 0.2f);  // Bottom-right
        glVertex2f(0.5f, 1.2f);   // Right
    glEnd();
}

void DesenhaCapa(float R, float G, float B) //desenha a capa do robo com um triangulo
{
    glColor3f(R, G, B); //recebe a cor
    glBegin(GL_TRIANGLES); //coordenadas de um triângulo
        glVertex2f(0.0f, 3.1f);   // Top-right
        glVertex2f(2.5f, -2.2f);  // Top-left
        glVertex2f(-2.5f, -2.2f);  // Left
    glEnd();
}

void DesenhaLinha(float R, float G, float B) //desenha uma linha para por como anteninha do robo
{
    glColor3f(R, G, B); //recebe a cor
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glVertex2f(0.5f, 3.8f);
        glVertex2f(0.9f, 4.1f);
    glEnd();
}


void Desenho(void)
{
    glClearColor(0.95, 0.95, 1.0, 0); //cor de fundo
    glClear(GL_COLOR_BUFFER_BIT); //limpa o buffer de cor
    DesenhaTexto("Instrucoes:", -9.0, -1.0);
    DesenhaTexto("Direitos(CAPS)", -9.0, -1.5);
    DesenhaTexto("Ombro: a, s;", -9.0, -2.0);
    DesenhaTexto("Cotovelo: m, n;", -9.0, -2.5); //insere textos
    DesenhaTexto("Mao: z, x;", -9.0, -3.0);
    DesenhaTexto("Dedo superior: d, f, e, r, t, y;", -9.0, -3.5);
    DesenhaTexto("Dedo inferior: g, h, j, k, l, o;", -9.0, -4.0);
    // Desenhar a capa
        DesenhaCapa(0.0, 0.0, 0.5);
    // Desenhar o tronco
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0); //translada o tronco
        glRotatef((GLfloat)tronco, 0.0, 0.0, 1.0); //rotaciona o tronco
        glPushMatrix(); 
            glScalef(1.0, 2.0, 1.0); //escala o tronco
            DesenhaQuadradoCrp(0.8, 0.8, 0.8); //desenha o tronco
        glPopMatrix(); //finaliza o tronco
        DesenhaHexa(0.0, 0.0, 0.9); //desenha a cabeça
        
        glColor3f(0.8, 0.8, 0.8);
        glPushMatrix();
        glTranslatef(0.0, 3.0, 0.0);
        glutSolidSphere(1.0, 10, 10);
        glPopMatrix();
        // Desenhar e pescoço
        glPushMatrix();
            glTranslatef(0.0, 2.0, 0.0);
            glRotatef((GLfloat)pescoco, 0.0, 0.0, 1.0);
            glTranslatef(0.0, 0.5, 0.0);
            glPushMatrix();
                glScalef(0.5, 0.5, 1.0);
                DesenhaQuadradoBrc(0.8, 0.8, 0.8);
            glPopMatrix();
            glTranslatef(0.0, 0.5, 0.0);
            glRotatef((GLfloat)cabeca, 0.0, 0.0, 1.0);
            glPushMatrix();
                glScalef(0.7, 0.5, 1.0);
                DesenhaQuadradoBrc(0.0, 0.0, 0.0);
            glPopMatrix();
        glPopMatrix();

        // Desenha antena
        DesenhaLinha(0.75, 0.75, 0.75); //desenha a antena
        glColor3f(0.0f, 0.0f, 0.9f); //cor do da bolinha antena
        glPushMatrix(); 
        glTranslatef(0.8, 4.0, 0.0);
        glutSolidSphere(0.17, 20, 20); //desenha bolinha antena
        glPopMatrix();

        // Desenhar os olhos
        glColor3f(0.1f, 0.5f, 1.0f); 
        glPushMatrix();
        glTranslatef(0.3, 3.0, 0.0);
        glutSolidSphere(0.17, 20, 20);
        glPopMatrix();
        glColor3f(0.1f, 0.5f, 1.0f);
        glPushMatrix();
        glTranslatef(-0.3, 3.0, 0.0);
        glutSolidSphere(0.17, 20, 20);
        glPopMatrix();

        // Desenhar o braço esquerdo
        glPushMatrix();
            glTranslatef(-1.0, 1.5, 0.0); //translada o braço esquerdo
            glRotatef((GLfloat)ombroEsq, 0.0, 0.0, 1.0); //rotaciona o braço esquerdo
            glTranslatef(-0.5, 0.0, 0.0); //translada o braço esquerdo
            glPushMatrix();
                glScalef(0.6, 0.2, 1.0); //escala o braço esquerdo
                DesenhaQuadradoBrc(0.75, 0.75, 0.75); //desenha o braço esquerdo
            glPopMatrix();

            // Junta do Ombro esquerdo
            glPushMatrix();
                glScalef(0.1, 0.2, 1.0); //escala a junta do ombro esquerdo
                glTranslatef(5.0, 0.0, 0.0); //translada a junta do ombro esquerdo
                DesenhaQuadradoBrc(0.1, 0.5, 1.0); //desenha a junta do ombro esquerdo
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.6, 0.0, 0.0); //translada o braço esquerdo
                glRotatef((GLfloat)cotoveloEsq, 0.0, 0.0, 1.0); //rotaciona o cotovelo esquerdo
                glTranslatef(-0.3, 0.0, 0.0); //translada o cotovelo esquerdo
                glPushMatrix();
                    glScalef(0.3, 0.25, 1.0); //escala o cotovelo esquerdo
                    DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                glPopMatrix();
                // Desenhar a mão esquerda e dedos
                glPushMatrix();
                //idem para os outros membros, com hierarquia, escala, translacao e rotacao
                    glTranslatef(-0.3, 0.0, 0.0);
                    glRotatef((GLfloat)maoEsq, 0.0, 0.0, 1.0); //rotaciona a mao esquerda
                    glTranslatef(-0.4, 0.0, 0.0);
                    glPushMatrix();
                        glScalef(0.4, 0.2, 1.0);
                        DesenhaQuadradoBrc(0.7, 0.7, 0.7);
                    glPopMatrix();
                    // Desenhar os dedos
                    glPushMatrix(); // Dedo superior
                        glTranslatef(-0.37, 0.2, 0.0);
                        glRotatef((GLfloat)dedo1Esq, 0.0, 0.0, 1.0);
                        glTranslatef(-0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();

                        // Segundo segmento do dedo superior
                        glTranslatef(-0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo1Esq2, 0.0, 0.0, 1.0);
                        glTranslatef(-0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.7);
                        glPopMatrix();

                        // Terceiro segmento do dedo superior
                        glTranslatef(-0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo1Esq3, 0.0, 0.0, 1.0);
                        glTranslatef(-0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix(); // Dedo inferior
                        glTranslatef(-0.37, -0.2, 0.0);
                        glRotatef((GLfloat)dedo2Esq, 0.0, 0.0, 1.0);
                        glTranslatef(-0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();

                        // Segundo segmento do dedo inferior
                        glTranslatef(-0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo2Esq2, 0.0, 0.0, 1.0);
                        glTranslatef(-0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.7);
                        glPopMatrix();

                        // Terceiro segmento do dedo inferior
                        glTranslatef(-0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo2Esq3, 0.0, 0.0, 1.0);
                        glTranslatef(-0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        // Desenhar o braço direito
        glPushMatrix();
            glTranslatef(1.0, 1.5, 0.0);
            glRotatef((GLfloat)ombroDir, 0.0, 0.0, 1.0);
            glTranslatef(0.5, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.6, 0.2, 1.0);
                DesenhaQuadradoBrc(0.75, 0.75, 0.75);
            glPopMatrix();

            // Junta do Ombro direito
            glPushMatrix();
                glScalef(0.1, 0.2, 1.0);
                glTranslatef(-5.0, 0.0, 0.0);
                DesenhaQuadradoBrc(0.1, 0.5, 1.0);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.6, 0.0, 0.0);
                glRotatef((GLfloat)cotoveloDir, 0.0, 0.0, 1.0);
                glTranslatef(0.3, 0.0, 0.0);
                glPushMatrix();
                    glScalef(0.3, 0.25, 1.0);
                    DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                glPopMatrix();
                // Desenhar a mão direita e dedos
                glPushMatrix();
                    glTranslatef(0.3, 0.0, 0.0);
                    glRotatef((GLfloat)maoDir, 0.0, 0.0, 1.0);
                    glTranslatef(0.4, 0.0, 0.0);
                    glPushMatrix();
                        glScalef(0.4, 0.2, 1.0);
                        DesenhaQuadradoBrc(0.7, 0.7, 0.7);
                    glPopMatrix();
                    // Desenhar os dedos
                    glPushMatrix(); // Dedo superior
                        glTranslatef(0.37, 0.2, 0.0);
                        glRotatef((GLfloat)dedo1Dir, 0.0, 0.0, 1.0);
                        glTranslatef(0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();

                        // Segundo segmento do dedo superior
                        glTranslatef(0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo1Dir2, 0.0, 0.0, 1.0);
                        glTranslatef(0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.7);
                        glPopMatrix();

                        // Terceiro segmento do dedo superior
                        glTranslatef(0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo1Dir3, 0.0, 0.0, 1.0);
                        glTranslatef(0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();
                    glPopMatrix();

                    glPushMatrix(); // Dedo inferior
                        glTranslatef(0.37, -0.2, 0.0);
                        glRotatef((GLfloat)dedo2Dir, 0.0, 0.0, 1.0);
                        glTranslatef(0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();

                        // Segundo segmento do dedo inferior
                        glTranslatef(0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo2Dir2, 0.0, 0.0, 1.0);
                        glTranslatef(0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.7);
                        glPopMatrix();

                        // Terceiro segmento do dedo inferior
                        glTranslatef(0.2, 0.0, 0.0);
                        glRotatef((GLfloat)dedo2Dir3, 0.0, 0.0, 1.0);
                        glTranslatef(0.2, 0.0, 0.0);
                        glPushMatrix();
                            glScalef(0.2, 0.1, 1.0);
                            DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        // Desenhar a perna esquerda
        glPushMatrix();
            glTranslatef(-0.5, -1.5, 0.0);
            glRotatef((GLfloat)pernaEsq, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.9, 0.0);
            glPushMatrix();
                glScalef(0.3, 0.4, 0.5);
                DesenhaQuadradoBrc(0.7, 0.7, 0.7);
            glPopMatrix();
            glPushMatrix();
            //desenha os joelhos
                glTranslatef(0.0, -1.0, 0.0);
                glRotatef((GLfloat)joelhoEsq, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.3, 0.0);
                glPushMatrix();
                    glScalef(0.2, 0.9, 0.0);
                    DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                glPopMatrix();
                glPushMatrix();
                glPopMatrix();
            glPopMatrix();

        // Junta da perna esquerda
        glPopMatrix();
        glScalef(0.35, 0.1, 0.5);
        glTranslatef(-1.5, -20.0, 0.0);
        DesenhaQuadradoBrc(0.1, 0.5, 1.0);
        glPopMatrix();

        // Desenhar a perna direita
        glPushMatrix();
            glTranslatef(0.5, -1.5, 0.0);
            glRotatef((GLfloat)pernaDir, 0.0, 0.0, 1.0);
            glTranslatef(0.0, -0.9, 0.0);
            glPushMatrix();
                glScalef(0.3, 0.4, 0.5);
                DesenhaQuadradoBrc(0.7, 0.7, 0.7);
            glPopMatrix();
            glPushMatrix();
            //desenha joelhos
                glTranslatef(0.0, -1.0, 0.0);
                glRotatef((GLfloat)joelhoDir, 0.0, 0.0, 1.0);
                glTranslatef(0.0, -0.3, 0.0);
                glPushMatrix();
                    glScalef(0.2, 0.9, 0.0);
                    DesenhaQuadradoBrc(0.0, 0.0, 0.9);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        // Junta da perna direita
        glPushMatrix();
        glScalef(-0.35, 0.1, 0.5);
        glTranslatef(-1.5, -20.0, 0.0);
        DesenhaQuadradoBrc(0.1, 0.5, 1.0);
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void Redimensionamento(GLint largura, GLint altura) { //para redimencionar o robo caso queira
    if (altura == 0) altura = 1; //evita divisao por zero
    GLfloat aspecto = (GLfloat) largura / (GLfloat) altura; //calcula o aspecto da tela
    glViewport(0, 0, largura, altura); //define a area de visualizacao
    glMatrixMode(GL_PROJECTION); //define a matriz de projecao
    glLoadIdentity(); //carrega a matriz identidade

    if (largura >= altura) 
    {
        gluOrtho2D(-5.0 * aspecto, 5.0 * aspecto, -5.0, 5.0); //define a projecao ortografica
    } else {
        gluOrtho2D(-5.0, 5.0, -5.0 / aspecto, 5.0 / aspecto); //define a projecao ortografica
    }

    glMatrixMode(GL_MODELVIEW); //define a matriz de visualizacao
    glLoadIdentity();
}


void Teclado(unsigned char tecla, GLint x, GLint y) 
{
    switch (tecla) {
        // Controle do braço esquerdo
        // controle por hierarquia
        //5 é a velocidade
        case 'a':
            ombroEsq = (ombroEsq + 5);
            break;
        case 's':
            ombroEsq = (ombroEsq - 5);
            break;
        case 'n':
            cotoveloEsq = (cotoveloEsq + 5);
            break;
        case 'm':
            cotoveloEsq = (cotoveloEsq - 5);
            break;
        case 'z':
            maoEsq = (maoEsq + 5);
            break;
        case 'x':
            maoEsq = (maoEsq - 5);
            break;

        // Controle do braço direito
        case 'A':
            ombroDir = (ombroDir + 5);
            break;
        case 'S':
            ombroDir = (ombroDir - 5);
            break;
        case 'N':
            cotoveloDir = (cotoveloDir + 5);
            break;
        case 'M':
            cotoveloDir = (cotoveloDir - 5);
            break;
        case 'Z':
            maoDir = (maoDir + 5);
            break;
        case 'X':
            maoDir = (maoDir - 5);
            break;

        // Controle dos dedos
        // Dedos esquerdos
        case 'd':
            dedo1Esq = (dedo1Esq + 5);
            break;
        case 'f':
            dedo1Esq = (dedo1Esq - 5);
            break;
        case 'e':
            dedo1Esq2 = (dedo1Esq2 + 5);
            break;
        case 'r':
            dedo1Esq2 = (dedo1Esq2 - 5);
            break;
        case 't':
            dedo1Esq3 = (dedo1Esq3 + 5);
            break;
        case 'y':
            dedo1Esq3 = (dedo1Esq3 - 5);
            break;
        case 'g':
            dedo2Esq = (dedo2Esq + 5);
            break;
        case 'h':
            dedo2Esq = (dedo2Esq - 5);
            break;
        case 'j':
            dedo2Esq2= (dedo2Esq2 + 5);
            break;
        case 'k':
            dedo2Esq2 = (dedo2Esq2 - 5);
            break;
        case 'l':
            dedo2Esq3 = (dedo2Esq3 + 5);
            break;
        case 'o':
            dedo2Esq3 = (dedo2Esq3 - 5);
            break;
        // Dedos direitos
        case 'D':
            dedo1Dir = (dedo1Dir + 5);
            break;
        case 'F':
            dedo1Dir = (dedo1Dir - 5);
            break;
        case 'E':
            dedo1Dir2 = (dedo1Dir2 + 5);
            break;
        case 'R':
            dedo1Dir2 = (dedo1Dir2 - 5);
            break;
        case 'T':
            dedo1Dir3 = (dedo1Dir3 + 5);
            break;
        case 'Y':
            dedo1Dir3 = (dedo1Dir3 - 5);
            break;
        case 'G':
            dedo2Dir = (dedo2Dir + 5);
            break;
        case 'H':
            dedo2Dir = (dedo2Dir - 5);
            break;
        case 'J':
            dedo2Dir2 = (dedo2Dir2 + 5);
            break;
        case 'K':
            dedo2Dir2 = (dedo2Dir2 - 5);
            break;
        case 'L':
            dedo2Dir3 = (dedo2Dir3 + 5);
            break;
        case 'O':
            dedo2Dir3 = (dedo2Dir3 - 5);
            break;
        // Sair do programa
        case 27:
            exit(0);
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) 
{
    //main para chamar os callbacks e iniciar o arquivo
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Astro");
    glutDisplayFunc(Desenho);
    glutReshapeFunc(Redimensionamento);
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
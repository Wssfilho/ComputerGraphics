#include <GL/glut.h>
#include <stdlib.h>

static GLint ombroEsq = -20, cotoveloEsq = 0, maoEsq = 0, dedoEsqEsq = -15, dedoEsqEsq2 = 5, dedoEsqEsq3 = 35, dedoEsqDir = 25, dedoEsqDir2 = -10, dedoEsqDir3 = -30;
static GLint ombroDir = 20, cotoveloDir = 0, maoDir = 0, dedoDirEsq = -15, dedoDirEsq2 = 5, dedoDirEsq3 = 35, dedoDirDir = 25, dedoDirDir2 = -10, dedoDirDir3 = -30;

void Desenho(void);
void Redimensionamento(GLint largura, GLint altura);
void Teclado (unsigned char tecla, GLint x, GLint y);
void DesenhaQuadrado(void);
void DesenhaTrapezio(void);
void DesenhaOlhos(void);
void DesenhaPupilas(void);
void desenhaTexto(const char *string);
void desenhaTexto2(char *string);
void specialKeys(int key, int x, int y);
void init();
void getScreenSize();

void desenhaTexto(const char *string) {
    // Define a cor do texto como preto
    glColor3ub(0, 0, 0);
    glPushMatrix();
    // Posição inicial no universo onde o texto será colocado
    float posicaoY = 6.5;
    glRasterPos2f(-6.5, posicaoY);
    // Exibe caracter a caracter
    while (*string) {
        if (*string == '\n') {
            // Se o caractere for '\n', mova a posição do raster para a próxima linha
            posicaoY -= 0.2; // Move para baixo para a próxima linha
            glRasterPos2f(-6.5, posicaoY - 0.2); // Define a nova posição do raster
        } else {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *string); // Renderiza o caractere atual
        }
        string++; // Move para o próximo caractere
    }
    glPopMatrix(); // Volta para a posição inicial
}

void desenhaTexto2(char *string){
  	glPushMatrix();
        glColor3ub(200, 20, 132);
        // Posição no universo onde o texto será colocado
        glRasterPos2f(-6.5, 6.4);
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*string++);
	glPopMatrix();
}

void DesenhaQuadrado(void) {
     glBegin(GL_QUADS);
          glVertex2f(-1,1);
          glVertex2f(-1,-1);
          glVertex2f(1,-1);
          glVertex2f(1,1);
     glEnd();
}

void DesenhaTrapezio(void) {
    glBegin(GL_QUADS);
          glVertex2f(-1,1);
          glVertex2f(-1.2,-1);
          glVertex2f(1.2,-1);
          glVertex2f(1,1);
     glEnd();
}

void DesenhaOlhos(void) {
    GLUquadricObj *discoExterior = gluNewQuadric();
    GLUquadricObj *discoInterior = gluNewQuadric();

    glPushMatrix(); // Olho
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            gluDisk(discoExterior, 0, 0.23, 30, 30);  // Sombra

            glColor3f(1, 1, 1);
            gluDisk(discoInterior, 0, 0.20, 30, 30);  // Círculo 

            glPushMatrix();
                glTranslatef(0.075, 0, 1);
                glScalef(0.5, 0.5, 1.0); //tamanho
                DesenhaPupilas();
            glPopMatrix();
    glPopMatrix();
}

void DesenhaPupilas(void) {
    GLUquadricObj *discoExterior = gluNewQuadric();
    GLUquadricObj *discoInterior = gluNewQuadric();

    glPushMatrix(); // pupila
            glColor3f(0.0, 0.0, 0.0); // Cor da "sombra"
            gluDisk(discoExterior, 0, 0.23, 30, 30);  // "Sombra"


            glTranslatef(0.07, 0.02, -1);
            glColor3f(1, 1, 1);
            gluDisk(discoInterior, 0, 0.11, 30, 30);  // Círculo 
        glPopMatrix();
}

void Desenho(void) {
   GLUquadricObj *discoExterior = gluNewQuadric();
   GLUquadricObj *discoInterior = gluNewQuadric();
   GLUquadricObj *meiaLua = gluNewQuadric();
   
   glClear (GL_COLOR_BUFFER_BIT);

   desenhaTexto("\n-> F1 e F2 - ombro esquerdo\n-> F3 e F4 - ombro direito\n-> F5 e F6 - cotovelo esquerdo\n-> F7 e F8 - cotovelo direito\n-> F9 e F10 - mao esquerda\n-> F11 e F12 - mao direita\n-> q e w - dedo (1) esquerdo da mao esquerda\n-> e e r - dedo (2) esquerdo da mao esquerda\n-> t e y - dedo (3) esquerdo da mao esquerda\n-> u e i - dedo (1) direito da mao esquerda\n-> o e p - dedo (2) direito da mao esquerda\n-> a e s - dedo (3) direito da mao esquerda\n-> d e f - dedo (1) esquerdo da mao direita\n-> g e h - dedo (2) esquerdo da mao direita\n-> j e k - dedo (3) esquerdo da mao direita\n-> l e z - dedo (1) direito da mao direita\n-> x e c - dedo (2) direito da mao direita\n-> v e b - dedo (3) direito da mao direita\n-> espaco - default");
   desenhaTexto2("MENU: ");

   glPushMatrix(); //Perna

         glPushMatrix(); // Coxa direita
            glColor3f(0.0, 0.0, 0.0); // Cor
            glTranslatef(0.5, -1.05, -1);

            glPushMatrix(); // coxa direita
               glScalef(0.07, 0.5, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix(); // Fim coxa direita

        glPushMatrix(); // Coxa esquerda
            glColor3f(0.0, 0.0, 0.0); // Cor
            glTranslatef(-0.5, -1.05, -1);
            
            glPushMatrix(); // coxa esquerda
               glScalef(0.07, 0.5, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix(); // Fim coxa esquerda

        glPushMatrix(); // Canela direita
            glColor3f(0.0, 0.0, 0.0); // Cor
            glTranslatef(0.5, -2, -1);

            glPushMatrix(); // canela direita
               glScalef(0.07, 0.5, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix(); // Fim canela direita

        glPushMatrix(); // Canela esquerda
            glColor3f(0.0, 0.0, 0.0); // Cor
            glTranslatef(-0.5, -2, -1);
            
            glPushMatrix(); // canela esquerda
               glScalef(0.07, 0.5, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix(); // Fim canela esquerda

        glPushMatrix(); // Sapato direito
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(0.5, -2.79, -1);

            gluPartialDisk(meiaLua, 0, 0.32, 30, 30, 270, 180);  // Sombra
            glPushMatrix(); 
               glScalef(0.32, 0.04, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
            glColor3f(0.8, 0.8, 0.8);
            gluPartialDisk(meiaLua, 0, 0.28, 30, 30, 270, 180);  // Cor sapato
        glPopMatrix(); //Fim sapato direito

        glPushMatrix(); // Sapato esquerdo
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(-0.5, -2.79, -1);

            gluPartialDisk(meiaLua, 0, 0.32, 30, 30, 270, 180);  // Sombra
            glPushMatrix();
               glScalef(0.32, 0.04, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
            glColor3f(0.8, 0.8, 0.8);
            gluPartialDisk(meiaLua, 0, 0.28, 30, 30, 270, 180);  // Cor sapato
        glPopMatrix(); //Fim sapato esquerdo

        glPushMatrix(); // Joelho direito
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(0.5, -1.5, -1);

            gluDisk(discoExterior, 0, 0.115, 30, 30);  // Sombra
            glColor3f(0.8, 0.8, 0.8);
            gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo do joelho
        glPopMatrix(); //Fim joelho direito

        glPushMatrix(); // Joelho esquerdo
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(-0.5, -1.5, -1);

            gluDisk(discoExterior, 0, 0.115, 30, 30);  // Sombra
            glColor3f(0.8, 0.8, 0.8);
            gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo do joelho
        glPopMatrix(); //Fim joelho esquerdo

        glPushMatrix(); // Circulo da perna direita
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(0.5, -1.05, -1);

            gluDisk(discoExterior, 0, 0.227, 30, 30);  // Sombra
            glColor3f(0.8, 0.8, 0.8);
            gluDisk(discoInterior, 0, 0.2, 30, 30);  // Círculo da perna
        glPopMatrix(); // Fim circulo da perna direita

        glPushMatrix(); // Circulo da perna esquerda
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(-0.5, -1.05, -1);

            gluDisk(discoExterior, 0, 0.227, 30, 30);  // Sombra
            glColor3f(0.8, 0.8, 0.8);
            gluDisk(discoInterior, 0, 0.2, 30, 30);  // Círculo da perna
        glPopMatrix(); //Fim circulo da perna esquerda

   glPopMatrix(); // Fim perna

   glPushMatrix(); //Rosto

        glPushMatrix(); //chapeu
            // Antena da cabeça
            glPushMatrix(); 
                glColor3f(0.0, 0.0, 0.0);
                glTranslatef(0.0, 2.85, 0.0); 
                glScalef(1.0, -1.0, 0.0); 
                glutSolidSphere(0.2, 50, 50); 
            glPopMatrix();

            glPushMatrix(); // Cabo da antena
                glLineWidth(5.0); // Definindo a largura da linha
                glTranslatef(-0.15, 3.1, 0.0);
                glScalef(0.7, 0.7, 1.0); 
                glRotatef(-120.0, 0.0, 0.0, 1.0); // Rotaciona ao redor do eixo z

                glBegin(GL_LINE_STRIP); // Desenha a linha 
                    glColor3f(0.0, 0.0, 0.0); 
                    for (float x = -0.3; x <= 0.4; x += 0.02) {
                        float y = x * x; // Parábola
                        glVertex3f(x, 0.2 + y, 0.0);
                    }
                glEnd();
            glPopMatrix(); 

            glPushMatrix();  //bolinha acima da antena
                glColor3f(0.0, 0.0, 0.0);
                glTranslatef(0.16, 3.2, 0.0); 
                glScalef(1.0, -1.0, 0.0); 
                glutSolidSphere(0.06, 50, 50); 
            glPopMatrix(); 
        glPopMatrix(); //Fim chapeu

        glPushMatrix(); // Pescoço
            glColor3f(0.0, 0.0, 0.0); // Cor
            glTranslatef(0, 1.18, -1);
            
            glPushMatrix(); // Pescoço
               glScalef(0.05, 0.25, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix(); //Fim pescoço

        glPushMatrix(); // Orelha esquerda
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(-0.68, 2.25, -1);

            glScalef(1, 1.15, 1.0);
            gluDisk(discoExterior, 0, 0.227, 30, 30);  // Sombra
            glColor3f(0.8, 0.8, 0.8);
            gluDisk(discoInterior, 0, 0.2, 30, 30);  // Círculo
        glPopMatrix(); //Fim orelha esquerda

        glPushMatrix(); // Orelha direita
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(0.68, 2.25, -1);

            glScalef(1, 1.15, 1.0);
            gluDisk(discoExterior, 0, 0.227, 30, 30);  // Sombra
            glColor3f(0.8, 0.8, 0.8);
            gluDisk(discoInterior, 0, 0.2, 30, 30);  // Círculo
        glPopMatrix(); //Fim orelha direita

        glPushMatrix(); // Sombra cabeça
            glColor3f(0, 0, 0); //Cor preta
            glTranslatef(0, 2.13, -1);
            
            glPushMatrix(); // Sombra cabeça
               glScalef(0.735, 0.735, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix(); //Fim sombra cabeça

        glPushMatrix(); // Cabeça
            glColor3f(0.8, 0.8, 0.8); //Cor cinza
            glTranslatef(0, 2.13, -1);
            
            glPushMatrix(); // Cabeça
               glScalef(0.7, 0.7, 1.0); //tamanho do quadrado
               DesenhaQuadrado();
            glPopMatrix();
        glPopMatrix(); // Fim cabeça

        glPushMatrix(); // Boca sorrindo
            glLineWidth(5.0); // Definindo a largura da linha
            glTranslatef(0, 2.65, -1);
            glScalef(0.7, 0.7, 1.0);

            glBegin(GL_LINE_STRIP); // Desenha a linha da boca
                glColor3f(0.0, 0.0, 0.0); 
                    for (float x = -0.3; x <= 0.3; x += 0.01) {
                        float y = x * x; // Parábola
                        glVertex3f(x, -1.4 + y, 1.0);
                    }
            glEnd();
        glPopMatrix(); // Fim boca

        glPushMatrix(); // Olho direito
            glTranslatef(0.35, 2.35, -1);

            glPushMatrix();
               glScalef(1, 1, 1.0); //tamanho
               DesenhaOlhos();
            glPopMatrix();
        glPopMatrix(); //Fim olho direito

        glPushMatrix(); // Olho esquerdo
            glTranslatef(-0.35, 2.35, -1);

            glPushMatrix();
               glScalef(1, 1, 1.0); //tamanho
               DesenhaOlhos();
            glPopMatrix();
        glPopMatrix(); // Fim olho esquerdo

   glPopMatrix(); // Fim Rosto

   glPushMatrix(); // Braços !!!!!!!!!!!!!!!!!

        // Ombro esquerdo!!!
        glPushMatrix(); 
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(-0.93, 0.71, -1);
            glRotatef ((GLfloat) ombroEsq, 0.0, 0.0, 1.0);

            glPushMatrix(); // Desenha o braço (reta entre o ombro e o cotovelo)
                glTranslatef(0, -0.3, 0);
                glScalef(0.07, 0.4, 1.0);
                DesenhaQuadrado();
            glPopMatrix();
            
            glPushMatrix(); // Desenha o círculo (clavícula)          
                glScalef(1, 1.15, 1.0);
                gluDisk(discoExterior, 0, 0.227, 30, 30);  // Sombra
                glColor3f(0.8, 0.8, 0.8);
                gluDisk(discoInterior, 0, 0.2, 30, 30);  // Círculo
            glPopMatrix();

            //Cotovelo esquerdo!!
            glPushMatrix();
                glColor3f(0.0, 0.0, 0.0); // Cor preta
                glTranslatef(0, -0.7, 0.0); //Ajusta a posição do cotovelo
                glRotatef((GLfloat) cotoveloEsq, 0.0, 0.0, 1.0);
                
                glPushMatrix(); // Desenha o antebraço (reta entre o cotovelo e a mão)
                    glTranslatef(0, -0.4, 0.0);
                    glScalef(0.07, 0.4, 1.0);
                    DesenhaQuadrado();
                glPopMatrix();
                
                glPushMatrix(); //Circulo do cotovelo
                    glScalef(1, 1.15, 1.0);
                    gluDisk(discoExterior, 0, 0.115, 30, 30);  // Sombra
                    glColor3f(0.8, 0.8, 0.8);
                    gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo
                glPopMatrix();

                // Mão Esquerda!!
                glPushMatrix(); 
                    glColor3f(0.0, 0.0, 0.0); // Cor da sombra
                    glTranslatef(0, -0.8, 0.0); // Ajuste a posição da maoEsq
                    glRotatef((GLfloat) maoEsq, 0.0, 0.0, 1.0);
                    
                    glPushMatrix(); //Desenha a reta
                        glTranslatef(0, -0.15, 0.0);
                        glScalef(0.07, 0.15, 1.0);
                        DesenhaQuadrado();
                    glPopMatrix();    

                    glPushMatrix(); //Desenha o círculo 
                        glScalef(1, 1.15, 1.0);
                        gluDisk(discoExterior, 0, 0.115, 30, 30);  // Sombra
                        glColor3f(0.8, 0.8, 0.8);
                        gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo
                    glPopMatrix();    

                    // Dedo Esquerdo Esquerdo (mão esquerda)!!
                    glPushMatrix(); 
                        glColor3f(0.28, 0.30, 0.31); // Cor do dedoEsqEsq
                        glTranslatef(-0.038, -0.3, 0.0); // Ajuste a posição do dedo
                        glRotatef((GLfloat) dedoEsqEsq, 0.0, 0.0, 1.0);

                        glPushMatrix(); //desenha a reta
                            glTranslatef(0, -0.075, 0.0);
                            glScalef(0.03, 0.12, 1.0);
                            DesenhaQuadrado();
                        glPopMatrix();

                        glPushMatrix(); //desenha o círculo
                            glColor3f(0, 0, 0);//cor da sombra
                            glScalef(1, 1.15, 1.0);
                            gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                            glColor3f(0.8, 0.8, 0.8);
                            gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                        glPopMatrix();

                        //Dedo Esquerdo Esquerdo 2 (mão esquerdo) !!
                        glPushMatrix(); 
                            glColor3f(0.28, 0.30, 0.31); // Cor do dedoEsqDir
                            glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                            glRotatef((GLfloat) dedoEsqEsq2, 0.0, 0.0, 1.0);
                            
                            glPushMatrix(); // desenha reta
                                glTranslatef(0, -0.075, 0.0);
                                glScalef(0.03, 0.12, 1.0);
                                DesenhaQuadrado();
                            glPopMatrix();
                            
                            glPushMatrix(); // desenha o círculo
                                glColor3f(0, 0, 0);//cor da sombra
                                glScalef(1, 1.15, 1.0);
                                gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                glColor3f(0.8, 0.8, 0.8);
                                gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                            glPopMatrix();

                            //Dedo Esquerdo Esquerdo 3 (mão esquerda) !!
                            glPushMatrix();  
                                glColor3f(0.28, 0.30, 0.31); // Cor do dedo3
                                glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                                glRotatef((GLfloat) dedoEsqEsq3, 0.0, 0.0, 1.0);
                                
                                glPushMatrix(); // desenha a reta
                                    glTranslatef(0, -0.075, 0.0);
                                    glScalef(0.03, 0.12, 1.0);
                                    DesenhaQuadrado();
                                glPopMatrix();

                                glPushMatrix(); // desenha o círculo
                                    glColor3f(0, 0, 0);//cor da sombra
                                    glScalef(1, 1.15, 1.0);
                                    gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                    glColor3f(0.8, 0.8, 0.8);
                                    gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                                glPopMatrix();

                            glPopMatrix(); //Fim Dedo Esquerdo Esquerdo 3

                        glPopMatrix(); //Fim Dedo Esquerdo Esquerdo 2

                    glPopMatrix(); // Fim Dedo Esquerdo Esquerdo

                    //Dedo Esquerdo Direito (mão direita) !!
                    glPushMatrix(); 
                        glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                        glTranslatef(0.038, -0.3, 0.0); // Ajuste a posição do dedo
                        glRotatef((GLfloat) dedoEsqDir, 0.0, 0.0, 1.0);
                        
                        glPushMatrix(); // reta
                            glTranslatef(0, -0.075, 0.0);
                            glScalef(0.03, 0.12, 1.0);
                            DesenhaQuadrado();
                        glPopMatrix();
                        
                        glPushMatrix(); // círculo
                            glColor3f(0, 0, 0);//cor da sombra
                            glScalef(1, 1.15, 1.0);
                            gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                            glColor3f(0.8, 0.8, 0.8);
                            gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                        glPopMatrix();

                        // Dedo Esquerdo Direito 2 (mão direita) !!
                        glPushMatrix();
                            glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                            glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                            glRotatef((GLfloat) dedoEsqDir2, 0.0, 0.0, 1.0);
                            
                            glPushMatrix(); // reta
                                glTranslatef(0, -0.075, 0.0);
                                glScalef(0.03, 0.12, 1.0);
                                DesenhaQuadrado();
                            glPopMatrix();

                            glPushMatrix(); //círculo
                                glColor3f(0, 0, 0);//cor da sombra
                                glScalef(1, 1.15, 1.0);
                                gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                glColor3f(0.8, 0.8, 0.8);
                                gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                            glPopMatrix();
                            
                            //Dedo Esquerdo Direito 3 (mão direita) !!
                            glPushMatrix(); 
                                glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                                glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                                glRotatef((GLfloat) dedoEsqDir3, 0.0, 0.0, 1.0);
                             
                                glPushMatrix(); //reta
                                    glTranslatef(0, -0.075, 0.0);
                                    glScalef(0.03, 0.12, 1.0);
                                    DesenhaQuadrado();
                                glPopMatrix();
                            
                                glPushMatrix(); //círculo
                                    glColor3f(0, 0, 0);//cor da sombra
                                    glScalef(1, 1.15, 1.0);
                                    gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                    glColor3f(0.8, 0.8, 0.8);
                                    gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                                glPopMatrix();
                            glPopMatrix(); //Fim Dedo Esquerdo direito

                        glPopMatrix(); // Fim Dedo Esquerdo direito 2

                    glPopMatrix(); //Fim Dedo Esquerdo Direito

                glPopMatrix(); // Fim Mão Esquerda

            glPopMatrix(); //Fim Cotovelo esquerdo

        glPopMatrix(); //Fim ombro esquerdo

        // Ombro Direito!!!
        glPushMatrix(); 
            glColor3f(0.0, 0.0, 0.0); // Cor da sombra
            glTranslatef(0.93, 0.71, -1);
            glRotatef ((GLfloat) ombroDir, 0.0, 0.0, 1.0);

            glPushMatrix(); // Desenha o braço (reta entre o ombro e o cotovelo)
                glTranslatef(0, -0.3, 0);
                glScalef(0.07, 0.4, 1.0);
                DesenhaQuadrado();
            glPopMatrix();
            
            glPushMatrix(); // Desenha o círculo (clavícula)          
                glScalef(1, 1.15, 1.0);
                gluDisk(discoExterior, 0, 0.227, 30, 30);  // Sombra
                glColor3f(0.8, 0.8, 0.8);
                gluDisk(discoInterior, 0, 0.2, 30, 30);  // Círculo
            glPopMatrix();

            //Cotovelo Direito!!
            glPushMatrix();
                glColor3f(0.0, 0.0, 0.0); // Cor preta
                glTranslatef(0, -0.7, 0.0); //Ajusta a posição do cotovelo
                glRotatef((GLfloat) cotoveloDir, 0.0, 0.0, 1.0);
                
                glPushMatrix(); // Desenha o antebraço (reta entre o cotovelo e a mão)
                    glTranslatef(0, -0.4, 0.0);
                    glScalef(0.07, 0.4, 1.0);
                    DesenhaQuadrado();
                glPopMatrix();
                
                glPushMatrix(); //Circulo do cotovelo
                    glScalef(1, 1.15, 1.0);
                    gluDisk(discoExterior, 0, 0.115, 30, 30);  // Sombra
                    glColor3f(0.8, 0.8, 0.8);
                    gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo
                glPopMatrix();

                // Mão Direita!!
                glPushMatrix(); 
                    glColor3f(0.0, 0.0, 0.0); // Cor da sombra
                    glTranslatef(0, -0.8, 0.0); // Ajuste a posição da mao
                    glRotatef((GLfloat) maoDir, 0.0, 0.0, 1.0);
                    
                    glPushMatrix(); //Desenha a reta
                        glTranslatef(0, -0.15, 0.0);
                        glScalef(0.07, 0.15, 1.0);
                        DesenhaQuadrado();
                    glPopMatrix();    

                    glPushMatrix(); //Desenha o círculo 
                        glScalef(1, 1.15, 1.0);
                        gluDisk(discoExterior, 0, 0.115, 30, 30);  // Sombra
                        glColor3f(0.8, 0.8, 0.8);
                        gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo
                    glPopMatrix();    

                    // Dedo Direito Esquerdo (mão direita)!!
                    glPushMatrix(); 
                        glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                        glTranslatef(-0.038, -0.3, 0.0); // Ajuste a posição do dedo
                        glRotatef((GLfloat) dedoDirEsq, 0.0, 0.0, 1.0);

                        glPushMatrix(); //desenha a reta
                            glTranslatef(0, -0.075, 0.0);
                            glScalef(0.03, 0.12, 1.0);
                            DesenhaQuadrado();
                        glPopMatrix();

                        glPushMatrix(); //desenha o círculo
                            glColor3f(0, 0, 0);//cor da sombra
                            glScalef(1, 1.15, 1.0);
                            gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                            glColor3f(0.8, 0.8, 0.8);
                            gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                        glPopMatrix();

                        //Dedo Direito Esquerdo 2 (mão direita) !!
                        glPushMatrix(); 
                            glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                            glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                            glRotatef((GLfloat) dedoDirEsq2, 0.0, 0.0, 1.0);
                            
                            glPushMatrix(); // desenha reta
                                glTranslatef(0, -0.075, 0.0);
                                glScalef(0.03, 0.12, 1.0);
                                DesenhaQuadrado();
                            glPopMatrix();
                            
                            glPushMatrix(); // desenha o círculo
                                glColor3f(0, 0, 0);//cor da sombra
                                glScalef(1, 1.15, 1.0);
                                gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                glColor3f(0.8, 0.8, 0.8);
                                gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                            glPopMatrix();

                            //Dedo Direita Esquerdo 3 (mão direita) !!
                            glPushMatrix(); 
                                glColor3f(0.28, 0.30, 0.31); // Cor do dedo3
                                glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                                glRotatef((GLfloat) dedoDirEsq3, 0.0, 0.0, 1.0);
                                
                                glPushMatrix(); // desenha a reta
                                    glTranslatef(0, -0.075, 0.0);
                                    glScalef(0.03, 0.12, 1.0);
                                    DesenhaQuadrado();
                                glPopMatrix();

                                glPushMatrix(); // desenha o círculo
                                    glColor3f(0, 0, 0);//cor da sombra
                                    glScalef(1, 1.15, 1.0);
                                    gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                    glColor3f(0.8, 0.8, 0.8);
                                    gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                                glPopMatrix();

                            glPopMatrix(); //Fim Dedo Direita Esquerdo 3

                        glPopMatrix(); //Fim Dedo Direita Esquerdo 2

                    glPopMatrix(); // Fim Dedo Direita Esquerdo

                    //Dedo Direito Direito (mão direita) !!
                    glPushMatrix(); 
                        glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                        glTranslatef(0.038, -0.3, 0.0); // Ajuste a posição do dedo
                        glRotatef((GLfloat) dedoDirDir, 0.0, 0.0, 1.0);
                        
                        glPushMatrix(); // reta
                            glTranslatef(0, -0.075, 0.0);
                            glScalef(0.03, 0.12, 1.0);
                            DesenhaQuadrado();
                        glPopMatrix();
                        
                        glPushMatrix(); // círculo
                            glColor3f(0, 0, 0);//cor da sombra
                            glScalef(1, 1.15, 1.0);
                            gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                            glColor3f(0.8, 0.8, 0.8);
                            gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                        glPopMatrix();

                        // Dedo Direito Direito 2 (mão direita) !!
                        glPushMatrix(); 
                            glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                            glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                            glRotatef((GLfloat) dedoDirDir2, 0.0, 0.0, 1.0);
                            
                            glPushMatrix(); // reta
                                glTranslatef(0, -0.075, 0.0);
                                glScalef(0.03, 0.12, 1.0);
                                DesenhaQuadrado();
                            glPopMatrix();

                            glPushMatrix(); //círculo
                                glColor3f(0, 0, 0);//cor da sombra
                                glScalef(1, 1.15, 1.0);
                                gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                glColor3f(0.8, 0.8, 0.8);
                                gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                            glPopMatrix();

                            //Dedo Direito Direito 3 (mão direita) !!
                            glPushMatrix(); 
                                glColor3f(0.28, 0.30, 0.31); // Cor do dedo
                                glTranslatef(0, -0.25, 0.0); // Ajuste a posição do dedo
                                glRotatef((GLfloat) dedoDirDir3, 0.0, 0.0, 1.0);
                             
                                glPushMatrix(); //reta
                                    glTranslatef(0, -0.075, 0.0);
                                    glScalef(0.03, 0.12, 1.0);
                                    DesenhaQuadrado();
                                glPopMatrix();
                            
                                glPushMatrix(); //círculo
                                    glColor3f(0, 0, 0);//cor da sombra
                                    glScalef(1, 1.15, 1.0);
                                    gluDisk(discoExterior, 0, 0.061, 30, 30);  // Sombra
                                    glColor3f(0.8, 0.8, 0.8);
                                    gluDisk(discoInterior, 0, 0.041, 30, 30);  // Círculo
                                glPopMatrix();
                            glPopMatrix(); //Fim Dedo Direito direito

                        glPopMatrix(); // Fim Dedo Direito direito 2

                    glPopMatrix(); //Fim Dedo Direito Direito

                glPopMatrix(); // Fim Mão direita

            glPopMatrix(); //Fim Cotovelo direito

        glPopMatrix(); //Fim ombro direito

   glPopMatrix(); // Fim Braços

   glPushMatrix(); //Corpo 
   // Sombra do corpo
        glColor3f(0.0, 0.0, 0.0); //Cor preta
        glTranslatef (0.0, 0.0, 0.0);
        glTranslatef (0.0, 0.0, 0.0);
        glPushMatrix(); // sombra Corpo
            glScalef(0.90, 1.05, 1.0); //tamanho do quadrado
            DesenhaTrapezio();
        glPopMatrix();

   //Corpo
        glColor3f(0.8, 0.8, 0.8); //Cor cinza
        glTranslatef (0.0, 0.0, 0.0);
        glTranslatef (0.0, 0.0, 0.0);
        glPushMatrix(); // Corpo
            glScalef(0.85, 1, 1.0); //tamanho do quadrado
            DesenhaTrapezio();
        glPopMatrix();
   

   // Parafusos
        glPushMatrix(); // Esq superior
            glColor3f(0.0, 0.0, 0.0); 
            glTranslatef (-0.7, 0.8, 0.0);
            gluDisk(discoExterior, 0, 0.13, 30, 30);  // Sombra
            glColor3f(0.99, 0.99, 0.99);
            gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo 
        glPopMatrix(); 

        glPushMatrix(); // Dir superior
            glColor3f(0.0, 0.0, 0.0); 
            glTranslatef (0.7, 0.8, 0.0);
            gluDisk(discoExterior, 0, 0.13, 30, 30);  // Sombra
            glColor3f(0.99, 0.99, 0.99);
            gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo 
        glPopMatrix(); 

        glPushMatrix(); // Esq inferior
            glColor3f(0.0, 0.0, 0.0); 
            glTranslatef (-0.8, -0.8, 0.0);
            gluDisk(discoExterior, 0, 0.13, 30, 30);  // Sombra
            glColor3f(0.99, 0.99, 0.99);
            gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo 
        glPopMatrix(); 

        glPushMatrix(); // Dir inferior
            glColor3f(0.0, 0.0, 0.0); 
            glTranslatef (0.8, -0.8, 0.0);
            gluDisk(discoExterior, 0, 0.13, 30, 30);  // Sombra
            glColor3f(0.99, 0.99, 0.99);
            gluDisk(discoInterior, 0, 0.095, 30, 30);  // Círculo 
        glPopMatrix(); 

        glPushMatrix(); // Desenha linha diagonal no parafuso
            glColor3f(0.0, 0.0, 0.0); // Cor da linha 
            glTranslatef (-0.7, 0.8, 0.0);
            glBegin(GL_LINES);
                glVertex2f(-0.09, -0.09);
                glVertex2f(0.09, 0.09);
            glEnd();
       glPopMatrix();

        glPushMatrix(); // Desenha linha diagonal no parafuso
            glColor3f(0.0, 0.0, 0.0); // Cor da linha 
            glTranslatef (0.7, 0.8, 0.0);
            glBegin(GL_LINES);
                glVertex2f(-0.09, -0.09);
                glVertex2f(0.09, 0.09);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Desenha linha diagonal no parafuso
            glColor3f(0.0, 0.0, 0.0); // Cor da linha 
            glTranslatef (-0.8, -0.8, 0.0);
            glBegin(GL_LINES);
                glVertex2f(-0.09, -0.09);
                glVertex2f(0.09, 0.09);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Desenha linha diagonal no parafuso
            glColor3f(0.0, 0.0, 0.0); // Cor da linha 
            glTranslatef (0.8, -0.8, 0.0);
            glBegin(GL_LINES);
                glVertex2f(-0.09, -0.09);
                glVertex2f(0.09, 0.09);
            glEnd();
        glPopMatrix();

    glPopMatrix(); // Fim Corpo

   glutSwapBuffers();
}

void Redimensionamento(GLint largura, GLint altura) {
   glViewport (0, 0, (GLsizei) largura, (GLsizei) altura);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D(-6.8,6.8,-6.8,6.8);//Exibição Bidimensional
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void Teclado (unsigned char tecla, GLint x, GLint y) {
   switch (tecla) {
    //Dedos mão esquerda
      case 'q':
         dedoEsqEsq = (dedoEsqEsq + 5);
         break;
      case 'w':
         dedoEsqEsq = (dedoEsqEsq - 5);
         break;
      case 'e':
         dedoEsqEsq2 = (dedoEsqEsq2 + 5);
         break;
      case 'r':
         dedoEsqEsq2 = (dedoEsqEsq2 - 5);
         break;
      case 't':
         dedoEsqEsq3 = (dedoEsqEsq3 + 5);
         break;
      case 'y':
         dedoEsqEsq3 = (dedoEsqEsq3 - 5);
         break;
      case 'u':
         dedoEsqDir = (dedoEsqDir + 5);
         break;
      case 'i':
         dedoEsqDir = (dedoEsqDir - 5);
         break;
      case 'o':
         dedoEsqDir2 = (dedoEsqDir2 + 5);
         break;
      case 'p':
         dedoEsqDir2 = (dedoEsqDir2 - 5);
         break;
      case 'a':
         dedoEsqDir3 = (dedoEsqDir3 + 5);
         break;
      case 's':
         dedoEsqDir3 = (dedoEsqDir3 - 5);
         break;

    //Dedos mão direita
      case 'd':
         dedoDirEsq = (dedoDirEsq + 5);
         break;
      case 'f':
         dedoDirEsq = (dedoDirEsq - 5);
         break;
      case 'g':
         dedoDirEsq2 = (dedoDirEsq2 + 5);
         break;
      case 'h':
         dedoDirEsq2 = (dedoDirEsq2 - 5);
         break;
      case 'j':
         dedoDirEsq3 = (dedoDirEsq3 + 5);
         break;
      case 'k':
         dedoDirEsq3 = (dedoDirEsq3 - 5);
         break;
      case 'l':
         dedoDirDir = (dedoDirDir + 5);
         break;
      case 'z':
         dedoDirDir = (dedoDirDir - 5);
         break;
      case 'x':
         dedoDirDir2 = (dedoDirDir2 + 5);
         break;
      case 'c':
         dedoDirDir2 = (dedoDirDir2 - 5);
         break;
      case 'v':
         dedoDirDir3 = (dedoDirDir3 + 5);
         break;
      case 'b':
         dedoDirDir3 = (dedoDirDir3 - 5);
         break;

      case 27: //sai com esc
         exit(0);
         break;
      case 32: ombroEsq = -20, cotoveloEsq = 0, maoEsq = 0, dedoEsqEsq = -15, dedoEsqEsq2 = 5, dedoEsqEsq3 = 35, dedoEsqDir = 25, dedoEsqDir2 = -10, dedoEsqDir3 = -30, ombroDir = 20, cotoveloDir = 0, maoDir = 0, dedoDirEsq = -15, dedoDirEsq2 = 5, dedoDirEsq3 = 35, dedoDirDir = 25, dedoDirDir2 = -10, dedoDirDir3 = -30; glutPostRedisplay(); break; //vai pro default
      default:
         break;
   }
   glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        //Ombros
        case GLUT_KEY_F1:
            ombroEsq = (ombroEsq + 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F2:
            ombroEsq = (ombroEsq - 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F3:
            ombroDir = (ombroDir + 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F4:
            ombroDir = (ombroDir - 5);
            glutPostRedisplay();
            break;

        //Cotovelos
        case GLUT_KEY_F5:
            cotoveloEsq = (cotoveloEsq + 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F6:
            cotoveloEsq = (cotoveloEsq - 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F7:
            cotoveloDir = (cotoveloDir + 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F8:
            cotoveloDir = (cotoveloDir - 5);
            glutPostRedisplay();
            break;

        //Mãos
        case GLUT_KEY_F9:
            maoEsq = (maoEsq + 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F10:
            maoEsq = (maoEsq - 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F11:
            maoDir = (maoDir + 5);
            glutPostRedisplay();
            break;
        case GLUT_KEY_F12:
            maoDir = (maoDir - 5);
            glutPostRedisplay();
            break;
    }
}

void init() {
    glClearColor(1.0, 0.79, 0.85, 1.0); // Fundo rosa
    glEnable(GL_DEPTH_TEST);
}

int screenWidth, screenHeight;

void getScreenSize() {
    screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

   getScreenSize();

   glutInitWindowSize (screenWidth/2, screenHeight/1.2);
   glutCreateWindow (argv[0]);

   init();

   glutDisplayFunc(Desenho);
   glutReshapeFunc(Redimensionamento);
   glutKeyboardFunc(Teclado);
   glutSpecialFunc(specialKeys);
   
   glutMainLoop();
   return 0;
}
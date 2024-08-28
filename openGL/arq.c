#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Variáveis globais para rastrear as opções selecionadas pelo usuário
int contornoFacial = 1;
int cabelos = 1;
int olhos = 1;
char boca = 1;
char sobrancelha = 1;
char nariz = 1;

void desenharContornoFacial(int opcao);
void desenharCabelos(int opcao);
void desenharOlhos(int opcao);
void desenharBoca(char opcao);
void desenharSobrancelha(char opcao);
void desenharNariz(char opcao);
void display(void);
void keyboard(unsigned char key, int x, int y);
void Special_keyboard(GLint tecla, int x, int y);

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(00, 00);
  glutCreateWindow(argv[0]);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glOrtho(-1, 1, -1, 1, -1, 1);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(Special_keyboard);
  glutMainLoop();
  printf("\nTestando... \n");
  return 0;
}

void desenharContornoFacial(int opcao)
{
  switch (opcao)
  {
  case 1:
    glColor3f(0.87, 0.72, 0.63);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.4);  // inferior esquerdo
    glVertex2f(-0.4, -0.2); // inferior direito
    glVertex2f(0.0, -0.4);  // superior esquerdo
    glVertex2f(0.4, -0.2);  // superior direito
    glVertex2f(0.4, 0.4);   // superior esquerdo
    glEnd();
    break;
  case 2:
    glColor3f(0.0, 0.0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.4);  // inferior esquerdo
    glVertex2f(-0.3, -0.3); // inferior direito
    glVertex2f(0.0, -0.4);  // superior esquerdo
    glVertex2f(0.3, -0.3);  // superior direito
    glVertex2f(0.4, 0.4);   // superior esquerdo
    glEnd();
    break;
  case 3:
    glColor3f(0.0, 0.0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.4);  // inferior esquerdo
    glVertex2f(-0.3, 0.3);  // inferior direito
    glVertex2f(-0.2, -0.1); // inferior direito
    glVertex2f(-0.1, -0.3); // inferior direito
    glVertex2f(0.0, -0.4);  // superior esquerdo
    glVertex2f(0.1, -0.3);  // inferior direito
    glVertex2f(0.2, -0.1);  // inferior direito
    glVertex2f(0.4, 0.4);   // inferior direito
    glVertex2f(0.3, 0.3);   // inferior direito
    glEnd();
    break;
  case 4:
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE);
    glVertex2f(-0.40, -0.40);
    glVertex2f(-0.40, 0.10);
    glVertex2f(-0.30, -0.10);
    break;
  case 5:
  glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, -0.4); // inferior esquerdo
    glVertex2f(0.4, -0.4);  // inferior direito
    glVertex2f(0.4, 0.4);   // superior direito
    glVertex2d(-0.4, 0.4);
    glEnd();
    break;
  case 6:
    break;
  }
}

void desenharCabelos(int opcao)
{
  switch (opcao)
  {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.4, 0.4); // base esquerda
    glVertex2f(0.4, 0.5); // base direita

    glVertex2f(0.35, 0.4); // base esquerda
    glVertex2f(0.35, 0.5); // base direita
    glVertex2f(0.30, 0.4); // base esquerda
    glVertex2f(0.30, 0.5); // base direita

    glVertex2f(0.25, 0.4); // base esquerda
    glVertex2f(0.25, 0.5); // base direita

    glVertex2f(0.20, 0.4);  // base esquerda
    glVertex2f(0.20, 0.5);  // base direita
    glVertex2f(0.15, 0.4);  // base esquerda
    glVertex2f(0.15, 0.5);  // base direita
    glVertex2f(0.10, 0.4);  // base esquerda
    glVertex2f(0.10, 0.5);  // base direita
    glVertex2f(0.05, 0.4);  // base esquerda
    glVertex2f(0.05, 0.5);  // base direita
    glVertex2f(0.0, 0.4);   // base esquerda
    glVertex2f(0.0, 0.5);   // base direita
    glVertex2f(-0.4, 0.4);  // base esquerda
    glVertex2f(-0.4, 0.5);  // base direita
    glVertex2f(-0.20, 0.4); // base esquerda
    glVertex2f(-0.20, 0.5); // base direita
    glVertex2f(-0.15, 0.4); // base esquerda
    glVertex2f(-0.15, 0.5); // base direita
    glVertex2f(-0.10, 0.4); // base esquerda
    glVertex2f(-0.10, 0.5); // base direita
    glVertex2f(-0.05, 0.4); // base esquerda
    glVertex2f(-0.05, 0.5); // base direita
    glVertex2f(-0.25, 0.4); // base esquerda
    glVertex2f(-0.25, 0.5); // base direita
    glVertex2f(-0.30, 0.4); // base esquerda
    glVertex2f(-0.30, 0.5); // base direita
    glVertex2f(-0.35, 0.4); // base esquerda
    glVertex2f(-0.35, 0.5); // base direita
    glEnd();
    break;
  case 5:
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);

    glVertex2f(0.0, 0.4);
    glVertex2f(0.0, 0.7);
    glVertex2f(0.0, 0.4);
    glVertex2f(-0.25, 0.7);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.25, 0.7);

    glVertex2f(0.0, 0.4);
    glVertex2f(-0.25, 0.5);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.25, 0.5);
    glEnd();
    break;
  case 6:
    break;
    // Continue para as outras opções de cabelo
  }
}

void desenharOlhos(int opcao)
{
  // Implemente conforme necessário
  switch (opcao)
  {
  case 1:
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.05, 0.2); // inferior esquerdo
    glVertex2f(-0.1, 0.25); // inferior direito
    glVertex2f(-0.2, 0.25); // inferior direito
    glVertex2f(-0.25, 0.2); // inferior direito
    glVertex2f(-0.2, 0.15); // superior esquerdo
    glVertex2f(-0.1, 0.15); // inferior direito
    glEnd();
    glPushMatrix();
    glTranslatef(-0.15, 0.20, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
      float angle = i * 3.14159 / 180;
      glVertex2f(0.05 * cos(angle), 0.05 * sin(angle));
    }
    glEnd();
    glPopMatrix();
    glBegin(GL_LINES);
    glVertex2f(-0.15, 0.30);
    glVertex2f(-0.15, 0.25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-0.15, 0.15);
    glVertex2f(-0.15, 0.10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.05, 0.2); // inferior esquerdo
    glVertex2f(0.1, 0.25); // inferior direito
    glVertex2f(0.2, 0.25); // inferior direito
    glVertex2f(0.25, 0.2); // inferior direito
    glVertex2f(0.2, 0.15); // superior esquerdo
    glVertex2f(0.1, 0.15); // inferior direito
    glEnd();
    glPushMatrix();
    glTranslatef(0.15, 0.20, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
      float angle = i * 3.14159 / 180;
      glVertex2f(0.05 * cos(angle), 0.05 * sin(angle));
    }
    glEnd();
    glPopMatrix();
    break;
  case 2:
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(-0.05, 0.2); // inferior esquerdo
    glVertex2f(-0.25, 0.2); // inferior direito
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(0.05, 0.2); // inferior esquerdo
    glVertex2f(0.25, 0.2); // inferior direito
    glEnd();
    break;
  case 3:
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.15, 0.20, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
      float angle = i * 3.14159 / 180;
      glVertex2f(0.05 * cos(angle), 0.05 * sin(angle));
    }
    glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-0.15, 0.20, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
      float angle = i * 3.14159 / 180;
      glVertex2f(0.05 * cos(angle), 0.05 * sin(angle));
    }
    glEnd();
    glPopMatrix();
    break;
  }
}

void desenharBoca(char opcao)
{
  // Implemente conforme necessário
}

void desenharSobrancelha(char opcao)
{
  switch (opcao)
  {
  case 1:
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-0.15, 0.25, 0.0);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    float comAnglo = 30.0;  // Ângulo inicial do arco
    float fimAnglo = 150.0; // Ângulo final do arco
    for (float i = comAnglo; i <= fimAnglo; i += 1.0)
    {
      float angle = i * 3.14159 / 180;
      glVertex2f(0.10 * cos(angle), 0.05 * sin(angle));
    }
    glEnd();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.15, 0.25, 0.0);
    glBegin(GL_LINES);
    comAnglo = 30.0;  // Ângulo inicial do arco
    fimAnglo = 150.0; // Ângulo final do arco
    for (float i = comAnglo; i <= fimAnglo; i += 1.0)
    {
      float angle = i * 3.14159 / 180;
      glVertex2f(0.10 * cos(angle), 0.05 * sin(angle));
    }
    glEnd();
    glPopMatrix();
    glLineWidth(1.0);
    break;
  default:
    break;
  }
  // Implemente conforme necessário
}

void desenharNariz(char opcao)
{
  // Implemente conforme necessário
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  // Desenhar contorno facial primeiro
  desenharContornoFacial(contornoFacial);
  // Desenhar cabelos depois do contorno facial
  desenharCabelos(cabelos);
  // Desenhar olhos
  desenharOlhos(olhos);
  // Desenhar boca
  desenharBoca(boca);
  // Desenhar sobrancelha
  desenharSobrancelha(sobrancelha);
  // Desenhar nariz
  desenharNariz(nariz);
  glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
  printf("*** Tratamento de teclas comuns\n");
  printf(">>> Tecla pressionada: %c\n", key);

  //if (key >= 49 && key <= 54) {
    //olhos = key - 49 + 1;
  //}
  switch (key)
  {
  case 49:
    olhos = 1;
    glutPostRedisplay();
    break;
  case 50:
    olhos = 2;
    glutPostRedisplay();
    break;
  case 51:
    olhos = 3;
    glutPostRedisplay();
    break;
  case 52:
    olhos = 4;
    glutPostRedisplay();
    break;
  case 53:
    olhos = 5;
    glutPostRedisplay();
    break;
  case 54:
    olhos = 6;
    glutPostRedisplay();
    break;
  // sombr:
  case 97:
    sobrancelha = 1;
    glutPostRedisplay();
    break;
  case 115:
    sobrancelha = 2;
    glutPostRedisplay();
    break;
  case 100:
    sobrancelha = 3;
    glutPostRedisplay();
    break;
  case 102:
    sobrancelha = 4;
    glutPostRedisplay();
    break;
  case 103:
    sobrancelha = 5;
    glutPostRedisplay();
    break;
  case 104:
    sobrancelha = 6;
    glutPostRedisplay();
    break;
  //boca
    case 113:
    boca = 1;
    glutPostRedisplay();
  break;
  case 119:
    boca = 2;
    glutPostRedisplay();
  break;
  case 101:
    boca = 3;
    glutPostRedisplay();
  break;
  case 114:
    boca = 4;
    glutPostRedisplay();
  break;
  case 116:
    boca = 5;
    glutPostRedisplay();
  break;
  case 121:
    boca = 6;
    glutPostRedisplay();
  break;
  case 112:
    nariz = 1;
    glutPostRedisplay();
  break;
  case 120:
    nariz = 2;
    glutPostRedisplay();
  break;
  case 99:
    nariz = 3;
    glutPostRedisplay();
  break;
  case 118:
    nariz = 4;
    glutPostRedisplay();
  break;
  case 98:
    nariz = 5;
    glutPostRedisplay();
  break;
  case 110:
    nariz = 6;
    glutPostRedisplay();
  break;
  }

}
void Special_keyboard(GLint tecla, int x, int y)
{
  switch (tecla)
  {
  case GLUT_KEY_F1:
    contornoFacial = 1;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F2:
    contornoFacial = 2;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F3:
    contornoFacial = 3;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F4:
    contornoFacial = 4;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F5:
    contornoFacial = 5;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F6:
    contornoFacial = 6;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F7:
    cabelos = 1;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F8:
    cabelos = 2;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F9:
    cabelos = 3;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F10:
    cabelos = 4;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F11:
    cabelos = 5;
    glutPostRedisplay();
    break;
  case GLUT_KEY_F12:
    cabelos = 6;
    glutPostRedisplay();
    break;
  }
}

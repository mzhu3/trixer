#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  color c;
  c.red = 0;
  c.green = 250;
  c.blue = 0;
  edges = new_matrix(4, 4);

  add_edge(edges,10,20,25,50,60,70);
  add_edge(edges,2,4,5,3,6,9);
  
  printf("Matrix edge:\n");
  print_matrix(edges);

  printf("Ident edge:\n");
  ident(edges);
  print_matrix(edges);
  free_matrix( edges );

  struct matrix * test;
  test = new_matrix(4,4);
  
  add_edge(test,100,200,255,120,240,300);
  add_edge(test,2,3,4,5,6,7);

  printf("test matrix:\n");
  print_matrix(test);
  printf("scalar by 2 test:\n");
  scalar_mult(2,test);
  print_matrix(test);

  struct matrix * a;
  a = new_matrix(4,4);
  add_edge(a,2,3,4,5,6,7);
  add_edge(a,10,11,12,13,14,15);
  printf("\n");
  printf("matrix a:\n");
  print_matrix(a);
  
  struct matrix *b;
  b = new_matrix(4,4);
  add_edge(b,2,4,6,8,10,12);
  add_edge(b,1,2,3,4,5,6);
  printf("matrix b:\n");
  print_matrix(b);

  printf("\n");
  printf("matrix multi of a by b:\n");
  matrix_mult(a,b);
  print_matrix(b);

  free_matrix(test);
  free_matrix(a);
  free_matrix(b);

  struct matrix *drawing;
  drawing = new_matrix(4,4);

  add_edge(drawing,50,450,100,50,50,100);
  add_edge(drawing,400,450,100,400,50,100);
  add_edge(drawing,50,450,100,400,450,100);
  add_edge(drawing,50,50,100,400,50,100);
  draw_lines(drawing,s,c);

  double factor;
  double scale;
  int colorI= 0;
  for(factor;factor < 1;factor +=.05){
    scale = 1-factor;
    scalar_mult(scale,drawing);
    draw_lines(drawing,s,c);
  }
  
  display(s);
  save_extension(s,"matrix.png");
  free_matrix(drawing);
      
}  

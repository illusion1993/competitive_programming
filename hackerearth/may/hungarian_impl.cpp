/********************************************************************
 ********************************************************************
 ** C++ class implementation of the Hungarian algorithm by David Schwarz, 2012
 **
 **
 ** O(n^3) implementation derived from libhungarian by Cyrill Stachniss, 2004
 **
 **
 ** Solving the Minimum Assignment Problem using the 
 ** Hungarian Method.
 **
 ** ** This file may be freely copied and distributed! **
 **
 **
 ** This file is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied 
 ** warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 ** PURPOSE.  
 **
 ********************************************************************
 ********************************************************************/

#include "hungarian.cpp"

std::vector< std::vector<int> > array_to_matrix(int* m, int rows, int cols) {
  int i,j;
  std::vector< std::vector<int> > r;
  r.resize(rows, std::vector<int>(cols, 0));

  for(i=0;i<rows;i++)
  {
    for(j=0;j<cols;j++)
      r[i][j] = m[i*cols+j];
  }
  return r;
}


int main() {

  // int r[4*3] =  {   100, 100, 1, 
  //                   100, 2, 21512, 
  //                   1, 4, 9852, 
  //                   6, 30252, 400 };
  // std::vector< std::vector<int> > m = array_to_matrix(r,4,3);
  // Hungarian hungarian(m , 4,3) ;
  
  int r[4*3] =  {   2, 1, 8, 
                    4, 2, 7, 
                    10, 10, 12, 
                    20, 20, 3};
  std::vector< std::vector<int> > m = array_to_matrix(r,4,3);
  Hungarian hungarian(m , 4, 3) ;

  /* some output */
  fprintf(stderr, "cost-matrix:");
  hungarian.print_cost();

  /* solve the assignement problem */
  hungarian.solve();

  /* some output */
  fprintf(stderr, "assignment:");
  hungarian.print_assignment();


  return 0;
}
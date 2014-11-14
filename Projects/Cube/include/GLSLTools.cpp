/* This is C++ sample code for File I/O */
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif

#include <GL/glew.h>
#include <iostream> // library that contain basic input/output functions
#include <fstream>  // library that contains file input/output functions
using namespace std;

void outputShaderErrors(GLuint shader) {
    char buffer[512];
    glGetShaderInfoLog(shader, 512, NULL, buffer);
    for (int i=0;i<512;i++)
        std::cout<< buffer[i];
    std::cout<< std::endl;
}

char* loadSource(const char* filename, const int array_size = 4096)
{
  char * array = new char[array_size]; // allocating an array of 1kb
  int position = 0; //this will be used incremently to fill characters in the array 
  
  ifstream fin(filename); //opening an input stream for file test.txt
  /*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
  stream could not be opened.*/
  if(fin.is_open())
  {
    //file opened successfully so we are here
    // cout << "File Opened successfully!!!. Reading data from file into array" << endl;
    //this loop run until end of file (eof) does not occur
    while(!fin.eof() && position < array_size)
    {
      fin.get(array[position]); //reading one character from file to array
      position++;
    }
    array[position-1] = '\0'; //placing character array terminating character
    
    // cout << "Displaying Array..." << endl << endl;
    //this loop display all the charaters in array till \0 
    // for(int i = 0; array[i] != '\0'; i++)
    // {
    //   cout << array[i];
    // }

    return array;
  }
  else //file could not be opened
  {
    // cout << "Oh no! File could not be opened." << endl;
    return new char[1];
  }
  return 0;
}

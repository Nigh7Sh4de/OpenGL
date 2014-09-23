/* This is C++ sample code for File I/O */
#include <iostream> // library that contain basic input/output functions
#include <fstream>  // library that contains file input/output functions
using namespace std;

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

// #include <stdio.h>
// #include <stdlib.h>

// #define GLEW_STATIC
// #include <GL/glew.h>
// /**
//  * Store all the file's contents in memory, useful to pass shaders
//  * source code to OpenGL
//  */
// /* Problem:
//  *  We should close the input file before the return NULL; statements but this would lead to a lot of repetition (DRY)
//  *   -you could solve this by using goto or by abusing switch/for/while + break or by building an if else mess
//  *  better solution: let the user handle the File: char* file_read(const FILE* input)
// */
// char* file_read(const char* filename)
// {
//   FILE* input = fopen(filename, "rb");
//   if(input == NULL) return NULL;
 
//   if(fseek(input, 0, SEEK_END) == -1) return NULL;
//   long size = ftell(input);
//   if(size == -1) return NULL;
//   if(fseek(input, 0, SEEK_SET) == -1) return NULL;
 
//   /*if using c-compiler: dont cast malloc's return value*/
//   char *content = (char*) malloc( (size_t) size +1  ); 
//   if(content == NULL) return NULL;
 
//   fread(content, 1, (size_t)size, input);
//   if(ferror(input)) {
//     free(content);
//     return NULL;
//   }
 
//   fclose(input);
//   content[size] = '\0';
//   return content;
// }

// /**
//  * Display compilation errors from the OpenGL shader compiler
//  */
// void print_log(GLuint object)
// {
//   GLint log_length = 0;
//   if (glIsShader(object))
//     glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);
//   else if (glIsProgram(object))
//     glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
//   else {
//     fprintf(stderr, "printlog: Not a shader or a program\n");
//     return;
//   }
 
//   char* log = (char*)malloc(log_length);
 
//   if (glIsShader(object))
//     glGetShaderInfoLog(object, log_length, NULL, log);
//   else if (glIsProgram(object))
//     glGetProgramInfoLog(object, log_length, NULL, log);
 
//   fprintf(stderr, "%s", log);
//   free(log);
// }

// /**
//  * Compile the shader from file 'filename', with error handling
//  */
// GLuint create_shader(const char* filename, GLuint type)
// {
//   const GLchar* source = file_read(filename);
//   if (source == NULL) {
//     fprintf(stderr, "Error opening %s: ", filename); perror("");
//     return 0;
//   }
//   GLuint res = glCreateShader(type);
//   const GLchar* sources[2] = {
// #ifdef GL_ES_VERSION_2_0
//     "#version 100\n"
//     "#define GLES2\n",
// #else
//     "#version 120\n",
// #endif
//     source };
//   glShaderSource(res, 2, sources, NULL);
//   free((void*)source);
 
//   glCompileShader(res);
//   GLint compile_ok = GL_FALSE;
//   glGetShaderiv(res, GL_COMPILE_STATUS, &compile_ok);
//   if (compile_ok == GL_FALSE) {
//     fprintf(stderr, "%s:", filename);
//     print_log(res);
//     glDeleteShader(res);
//     return 0;
//   }
 
//   return res;
// }
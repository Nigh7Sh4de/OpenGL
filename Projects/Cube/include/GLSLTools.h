#ifndef _CREATE_SHADER_H
#define _CREATE_SHADER_H
#include <GL/glew.h>
void outputShaderErrors(GLuint shader);
char* loadSource(const char* filename, const int array_size = 4096);
// void print_log(GLuint object);
// GLuint create_shader(const char* filename, GLuint type);
#endif
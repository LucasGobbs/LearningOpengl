#include <GL/glew.h>
#include <stdio.h>
#ifndef SHADER_H
#define SHADER_H
struct shader{
    char* pathVert;
    char* pathFrag;
    GLuint vertId;
    GLuint fragId;
};
typedef struct shader shader;
shader* shader_create(const char* _pathVert, const char* _pathFrag);
GLuint shader_compile(const GLchar* source, GLenum shader_type);
GLchar* shader_read_source(FILE* path);
GLuint shader_create_program(shader* sh);
void shader_bind(shader sh);
void shader_unbind(shader sh);
void shader_destroy(shader* sh);
void shader_setUniform4f(GLuint programId, const char* name, float a, float b, float c, float d);

#endif
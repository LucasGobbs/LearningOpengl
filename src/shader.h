#ifndef SHADER_H
#define SHADER_H
struct shader{
    char* path;
};
typedef struct shader shader;
void shader_create(char* path);
void shader_bind();
void shader_unbind();
void shader_destroy();
#endif
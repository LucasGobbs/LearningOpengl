#include "shader.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_SOURCE_CHARS 1000

shader* shader_create(const char* _pathVert, const char* _pathFrag){
    GLuint vShader;
    GLuint fShader;
    shader* shaders = NULL;
    FILE* vSource = NULL;
    FILE* fSource = NULL;
    
    vSource = fopen(_pathVert, "r");
    fSource = fopen(_pathFrag, "r");
    
    GLchar* vertexSource   = (GLchar*) shader_read_source(vSource);
    GLchar* fragmentSource = (GLchar*) shader_read_source(fSource);
    
    //check(vertexSource != NULL && fragmentSource != NULL,
    //    "Shader source files weren't read properly.");

    vShader = shader_compile(vertexSource,   GL_VERTEX_SHADER);
    fShader = shader_compile(fragmentSource, GL_FRAGMENT_SHADER);

    //check(vShader != 0 && fShader != 0, "Shader compilation failed.");

    shaders = malloc(sizeof(shader));
    //check_mem(shaders);
    shaders->vertId   = vShader;
    shaders->fragId   = fShader;

    if(vertexSource != NULL)   { free(vertexSource);   }
    if(fragmentSource != NULL) { free(fragmentSource); }
    if(vSource != NULL)        { fclose(vSource);      }
    if(fSource != NULL)        { fclose(fSource);      }

    return shaders;
}
GLuint shader_compile(const GLchar* source, GLenum shader_type){
    GLchar infoLog[512];
    GLint  success;
    GLuint shader = 0;

    //check(source != NULL, "Empty shader source given.");

    shader = glCreateShader(shader_type);
    glShaderSource(shader,1,&source,NULL);
    glCompileShader(shader);

    // Check for compilation success.
    glGetShaderiv(shader,GL_COMPILE_STATUS,&success);
    glGetShaderInfoLog(shader,512,NULL,infoLog);
    //check(success, "Shader %s failed to compile:\n%s\n", source, infoLog);

    return shader;
 
}
GLchar* shader_read_source(FILE* path){
    GLchar* s = NULL;
    GLchar c;
    int i = 0;
    
    //check(source != NULL, "NULL shader source file given.");
    
    s = malloc(sizeof(GLchar) * MAX_SOURCE_CHARS);
    //check_mem(s);

    while((c = fgetc(path)) != EOF && i < MAX_SOURCE_CHARS - 1) {
        s[i] = c;
        i++;
    }

    s[i] = '\0';

    return s;
}
GLuint shader_create_program(shader* sh){
    GLuint program = 0;

    //check(shaders != NULL, "Bad shaders given.");

    // Link shaders
    program = glCreateProgram();
    glAttachShader(program,sh->vertId);
    glAttachShader(program,sh->fragId);
    glLinkProgram(program);

    return program;

}
void shader_bind(shader sh);
void shader_unbind(shader sh);
void shader_destroy(shader* sh){
    if(sh!= NULL) {
        glDeleteShader(sh->vertId);
        glDeleteShader(sh->fragId);
        free(sh);
    }
}
void shader_setUniform4f(GLuint programId,const char* name, float a, float b, float c, float d){
    glUniform4f(glGetUniformLocation(programId, name), a, b, c, d);

}
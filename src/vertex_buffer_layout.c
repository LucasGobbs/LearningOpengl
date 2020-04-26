#include "vertex_buffer_layout.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
unsigned int getSizeOf(unsigned int type){
    switch(type){
        case GL_FLOAT:  
            return (sizeof(GLfloat));
        case GL_UNSIGNED_INT: 
            return (sizeof(GLuint));
        case GL_UNSIGNED_BYTE: // GLFLOAT
            return (sizeof(GLbyte));
    }
    return 0;
}
vertex_buffer_layout* vbl_create(unsigned int max_length){
    vertex_buffer_layout* vbl = (vertex_buffer_layout*) malloc(sizeof(vertex_buffer_layout));
    vbl->max_length = max_length;
    vbl->elements = malloc(sizeof(vertex_buffer_element)*max_length);
    vbl->stride = 0;
    vbl->elements_length = 0;
    return vbl;
}

vertex_buffer_layout* vbl_push_f(vertex_buffer_layout* vbl, unsigned int count){
    // Float
    return vbl_push(vbl, GL_FLOAT, count, GL_FALSE);
}
vertex_buffer_layout* vbl_push_ui(vertex_buffer_layout* vbl, unsigned int count){
    //unsigned int
    return vbl_push(vbl, GL_UNSIGNED_INT, count, GL_FALSE);
}
vertex_buffer_layout* vbl_push_ub(vertex_buffer_layout* vbl, unsigned int count){
    //unsigned int
    return vbl_push(vbl, GL_UNSIGNED_BYTE, count, GL_TRUE);
}

vertex_buffer_layout* vbl_push(vertex_buffer_layout* vbl, 
         unsigned int type, 
         unsigned int count, 
         unsigned char normalized){
    if(vbl->elements_length >= vbl->max_length){
        //excedeu capacidade
        printf("Nâo foi possivel adicionar");
        return vbl;
    } else {    
        vbl->elements[vbl->elements_length] = (vertex_buffer_element){type,count,normalized};
        vbl->stride += count * getSizeOf(type);
        vbl->elements_length++;
    }
    
    return vbl;
}
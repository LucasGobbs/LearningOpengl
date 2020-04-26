#include "index_buffer.h"
#include <stdlib.h>
#include <memory.h>

index_buffer* ibuffer_create(unsigned int* data, unsigned int count){
    index_buffer* ib = (index_buffer*)malloc(sizeof(index_buffer));
    ib->count = count;
    glGenBuffers(1, &ib->renderer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->renderer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), data, GL_STATIC_DRAW);

    
    return ib;
}
void ibuffer_bind(index_buffer ib){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib.renderer_id);
}
void ibuffer_unbind(index_buffer ib){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void ibuffer_destroy(index_buffer* ib){
    glDeleteBuffers(1, &ib->renderer_id);
    free(ib);
}
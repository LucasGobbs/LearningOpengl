
#include "vertex_buffer.h"
#include "stdlib.h"
#include "memory.h"


vertex_buffer* vbuffer_create(const void* data, GLuint size){
    vertex_buffer* vb = (vertex_buffer*)malloc(sizeof(vertex_buffer));
    glGenBuffers(1, &vb->renderer_id);
    glBindBuffer(GL_ARRAY_BUFFER, vb->renderer_id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    return vb;
}
void vbuffer_bind(vertex_buffer vb){
    glBindBuffer(GL_ARRAY_BUFFER, vb.renderer_id);
}
void vbuffer_unbind(vertex_buffer vb){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void vbuffer_destroy(vertex_buffer* vb){

    glDeleteBuffers(1, &vb->renderer_id);
    free(vb);
}
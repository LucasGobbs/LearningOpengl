#include <GL/glew.h>
#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H
struct vertex_buffer{
    GLuint renderer_id;
};
typedef struct vertex_buffer vertex_buffer;
vertex_buffer* vbuffer_create(const void* data, GLuint size);
void vbuffer_bind(vertex_buffer vb);
void vbuffer_unbind(vertex_buffer vb);
void vbuffer_destroy(vertex_buffer* vb);
#endif
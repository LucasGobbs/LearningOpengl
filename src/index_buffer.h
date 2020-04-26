#include <GL/glew.h>
#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H
struct index_buffer{
    GLuint renderer_id;
    unsigned int count;
};
typedef struct index_buffer index_buffer;
index_buffer* ibuffer_create(unsigned int* data, unsigned int size);
void ibuffer_bind(index_buffer ib);
void ibuffer_unbind(index_buffer ib);
void ibuffer_destroy(index_buffer* ib);
#endif

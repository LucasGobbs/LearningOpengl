#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "stdlib.h"
#include "memory.h"
#include "stdint.h"
#include <GL/glew.h>
#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H
//#define INT2VOIDP(i) (void*)(uintptr_t)(i)
#define INT2VOIDP(i) (void*)(uintptr_t)(i)
struct vertex_array{
    GLuint renderer_id;
};
typedef struct vertex_array vertex_array;
vertex_array* varray_create();
void varray_bind(vertex_array va);
void varray_unbind();
void varray_destroy(vertex_array* va);
void varray_addbuffer(vertex_array* va, 
                      vertex_buffer* vb, 
                      vertex_buffer_layout* layout);
#endif //VERTEX_ARRAY_H

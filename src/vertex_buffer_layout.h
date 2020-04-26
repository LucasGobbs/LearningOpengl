#include <GL/glew.h>
#ifndef VERTEX_BUFFER_LAYOUT
#define VERTEX_BUFFER_LAYOUT
struct vertex_buffer_element{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
};
typedef struct vertex_buffer_element vertex_buffer_element;

struct vertex_buffer_layout{
    unsigned int stride;

    unsigned int elements_length;
    unsigned int max_length;
    struct vertex_buffer_element* elements;
};
typedef struct vertex_buffer_layout vertex_buffer_layout;

//utilidade
unsigned int getSizeOf(unsigned int type);
//
vertex_buffer_layout* vbl_create(unsigned int max_length);
vertex_buffer_layout* vbl_push(vertex_buffer_layout* vbl, 
         unsigned int type, 
         unsigned int count, 
         unsigned char normalized);
vertex_buffer_layout* vbl_push_f(vertex_buffer_layout* vbl, unsigned int count);
vertex_buffer_layout* vbl_push_ui(vertex_buffer_layout* vbl, unsigned int count);
vertex_buffer_layout* vbl_push_ub(vertex_buffer_layout* vbl, unsigned int count);

#endif //VERTEX_BUFFER_LAYOUT

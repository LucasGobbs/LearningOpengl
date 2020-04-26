#include "vertex_array.h"
vertex_array* varray_create(){
    vertex_array* va = (vertex_array*)malloc(sizeof(vertex_array));
    glGenVertexArrays(1, &va->renderer_id);
    return va;
}
void varray_bind(vertex_array va){
    glBindVertexArray(va.renderer_id);
}
void varray_unbind(){
    glBindVertexArray(0);
}
void varray_destroy(vertex_array* va){
    glDeleteVertexArrays(1, &va->renderer_id);
    free(va); 
}
void varray_addbuffer(vertex_array* va, 
                      vertex_buffer* vb, 
                      vertex_buffer_layout* layout){
    varray_bind(*va);
    vbuffer_bind(*vb);
    unsigned int offset = 0;
    int i = 0;
    for(i=0;i<layout->elements_length;i++){
        const vertex_buffer_element element = layout->elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, 
                                 element.type, 
                                 element.normalized,
                                 layout->stride,
                                 INT2VOIDP(offset));
        offset += element.count * getSizeOf(element.type);
    }
}
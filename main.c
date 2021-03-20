#include "matrix.h"


int main() {
    /* tek satırda num ile kullanılıyor */
    matrix_new_num(m1, 01, 2, 3, 4); matrix_new(m2, 02, 2, 3, 4);
    
    matrix_new(m3, 2, 3, 4); 
    matrix_new(m4, 2, 3, 4);
    
    matrix_fill_wf(&m1, m_fill);
    matrix_print(&m1);
    
    return 0;
}


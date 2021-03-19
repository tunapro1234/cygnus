#include "main.h"


#define LEN(arr) \
	sizeof(arr) / sizeof(arr[0])

typedef struct matrix_t {
	size_t dim, *shape;
	f64 *data;
} matrix_t;


void matrix_init(matrix_t *self, size_t dim, const size_t *shape);
matrix_t* matrix_new(size_t dim, const size_t *shape);

size_t _matrix_length(size_t dim, const size_t *shape);
size_t matrix_length(const matrix_t *self);

void _matrix_set_shape(matrix_t *self, size_t new_dim, const size_t *new_shape);
bool matrix_change_shape(matrix_t *self, size_t new_dim, const size_t *new_shape);

void _matrix_print(const matrix_t *self);
void matrix_print_1(const matrix_t *self);
void matrix_print_2(const matrix_t *self);
size_t* _matrix_calc_lens(const matrix_t *self);

f64 m_fill(matrix_t *self, size_t index);
void matrix_fill_wf(matrix_t *self, f64 (*func)(matrix_t*, size_t));
void matrix_fill(matrix_t *self, f64 data);


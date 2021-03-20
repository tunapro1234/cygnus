#include "main.h"


typedef struct matrix_t {
	size_t dim, *shape;
	f64 *data;
} matrix_t;


#define LEN(arr) \
	sizeof(arr) / sizeof(arr[0])

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define ANON(name) CAT(name##_, __LINE__)


void matrixh_init(matrix_t *self, size_t dim, const size_t *shape);
matrix_t* matrixh_new(size_t dim, const size_t *shape);


/* name, ... */
#define matrix_new(name, ...)	matrix_new_num(name, __LINE__, __VA_ARGS__)
/* self, ... */
#define matrix_init(self, ...)	matrix_init_num(self, __LINE__)

/* name, num, ... */
#define matrix_new_num(name, num, ...)	\
	matrix_t name;					\
	matrix_init_num(&name, num, __VA_ARGS__)

/* self, num, ... */
#define matrix_init_num(self, num, ...) 												\
	size_t CAT(_shape_, num)[] = {__VA_ARGS__};											\
	(self)->dim = LEN(CAT(_shape_, num));												\
	(self)->shape = CAT(_shape_, num);													\
	\
	f64 CAT(_data_, num)[matrix_length_(LEN(CAT(_shape_, num)), CAT(_shape_, num))];	\
	(self)->data = CAT(_data_, num)


size_t matrix_length_(size_t dim, const size_t *shape);
size_t matrix_length(const matrix_t *self);

void _matrix_set_shape(matrix_t *self, size_t new_dim, const size_t *new_shape);
bool matrix_change_shape(matrix_t *self, size_t new_dim, const size_t *new_shape);

void matrix_print(const matrix_t *self);

f64 m_fill(matrix_t *self, size_t index);
void matrix_fill_wf(matrix_t *self, f64 (*func)(matrix_t*, size_t));
void matrix_fill(matrix_t *self, f64 data);


/*
size_t* _matrix_calc_lens(const matrix_t *self);
void matrix_print_1(const matrix_t *self);
*/

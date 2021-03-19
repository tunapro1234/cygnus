#include "matrix.h"



void matrix_init(matrix_t *self, size_t dim, const size_t *shape) {
	self->data = (f64 *)malloc(sizeof(f64) * _matrix_length(dim, shape));

	self->shape = (size_t *)malloc(sizeof(size_t) * dim);
	_matrix_set_shape(self, dim, shape);
}

matrix_t* matrix_new(size_t dim, const size_t *shape) {
	matrix_t *new_matrix = (matrix_t *)malloc(sizeof(matrix_t));
	matrix_init(new_matrix, dim, shape);
	return new_matrix;
}

size_t _matrix_length(size_t dim, const size_t *shape) {
	size_t i, len = 1;
	for (i = 0; i < dim; i++) 
		len *= shape[i];
	return len;
}

size_t matrix_length(const matrix_t *self) {
	return _matrix_length(self->dim, self->shape);
}

void _matrix_set_shape(matrix_t *self, size_t new_dim, const size_t *new_shape) {
	if (self->dim != new_dim)
        realloc(self->shape, sizeof(size_t) * new_dim);
    memcpy(self->shape, new_shape, sizeof(size_t) * new_dim);
	self->dim = new_dim;
}

bool matrix_change_shape(matrix_t *self, size_t new_dim, const size_t *new_shape) {
	if (matrix_length(self) == _matrix_length(new_dim, new_shape)) {
		_matrix_set_shape(self, new_dim, new_shape);
		return True;
	}
	return False;
}

size_t* _matrix_calc_lens(const matrix_t *self) {
	size_t i, plen = 1;
	size_t *lens = (size_t *)malloc(sizeof(size_t) * self->dim);

	for (i = self->dim; i > 0; i--) {
		plen *= self->shape[(i-1)];
		lens[(i-1)] = plen;
	}
	return lens;
}

void _matrix_print(const matrix_t *self) {
	size_t i, len = matrix_length(self);
	for (i = 0; i < len; i++) 
		printf("%lf", self->data[i]);
}

void matrix_print_1(const matrix_t *self) {
	size_t i, j, len = matrix_length(self);
	size_t *lens = _matrix_calc_lens(self);
	/* 
	 * lens hesaplama yaptım ve her biri için % operatörü kullanıyorum
	 * ama arakdan ilerleyerek bölerek ilerleyebiliriz.
	 * 
	 * ya da lensin başından ilerleyerek ve bölerek ilerleyebiliriz
	 */
	for (i = 0; i < len; i++) {
		if (i == 0)
			for (j = 0; j < self->dim; j++)
				printf("[");
		
		else if (i != len-1) {
			for (j = 0; j < self->dim; j++)
				if (i % lens[j] == 0) {
					printf("]");
					if (j == self->dim-1)
						printf("\n");
				}
			
            for (j = 0; j < self->dim; j++)
				if (i % lens[j] == 0)
					printf("[");
		}

		printf("%lf ", self->data[i]);
		
		if (i == len - 1)
			for (j = 0; j < self->dim; j++)
				printf("]");
	}
}

void matrix_print_2(const matrix_t *self) {
    size_t i, j, k, l, m, p, len = matrix_length(self);

	/* 
	 * algoritmayı anlatıcam kahvaltıdan sonra
	 * 
	 */

    for (i = 0; i < self->dim; i++) printf("[");

    for (i = 0; i < len; i++) {
        printf("%.2lf", self->data[i]);
        
		l = 0;
		p = i+1;
        j = self->dim;
        while (True) {
            if (p % self->shape[j-1] == 0 && (p /= self->shape[j-1]) >= 1) { 
                printf("]");
				l++;
            } else {
				if (l) {
					for (m = l; m > 0; m--) printf("\n");
					for (k = self->dim - l; k > 0; k--) printf(" ");
				} else printf(" ");
				if (i != len-1)
					for (; l > 0; l--) 
						printf("[");
				break;
			}
            j--;
        }
    }
}

f64 m_fill(matrix_t *self, size_t index) 
	{ return index % self->shape[self->dim - 1]; }

void matrix_fill_wf(matrix_t *self, f64 (*func)(matrix_t*, size_t)) {
	size_t i, len = matrix_length(self);
	for (i = 0; i < len; i++)
		self->data[i] = func(self, i);
}

void matrix_fill(matrix_t *self, f64 data) {
	size_t i, len = matrix_length(self);
	for (i = 0; i < len; i++)
		self->data[i] = data;
}


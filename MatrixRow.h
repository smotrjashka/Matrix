#ifndef MATRIX_MATRIXROW_H
#define MATRIX_MATRIXROW_H

#include <set>
#include "MatrixCell.h"

template<typename T, T default_val>
struct MatrixRow{
    MatrixRow(unsigned int row_number) : row_number_(row_number){

    };

    MatrixCell<T, default_val>& operator[](unsigned int left_index){
        for(auto it = cells_.begin(); it < cells_.end(); it++){
            if (it->is_same_index(left_index)){
                return (*it);
            }
        }
        MatrixCell<T, default_val> new_cell(left_index);
        cells_.insert(new_cell);
        return new_cell;
    };

private:
    unsigned int row_number_;
    std::set<MatrixCell<T, default_val>> cells_;
};

#endif //MATRIX_MATRIXROW_H

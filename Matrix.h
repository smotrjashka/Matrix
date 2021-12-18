#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include "MatrixRow.h"

template <typename T, T default_val>
struct Matrix{

public:
    Matrix(){
        real_size_ = 0;
    }
    int size(){
        return real_size_;
    }

    MatrixRow<T, default_val>& operator[](unsigned int right_index ){
        for(auto row : rows_){
            if (row.is_same_index(right_index)){
                return row;
            }
        }
        MatrixRow<T, default_val> new_row(right_index);
        rows_.insert(new_row);
        return new_row;
    } ;

private:
    // if we speak about infinite Matrix maybe long will be better???
    unsigned int real_size_;
    std::set<MatrixRow<T, default_val>> rows_;
};

#endif //MATRIX_MATRIX_H

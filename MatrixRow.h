#ifndef MATRIX_MATRIXROW_H
#define MATRIX_MATRIXROW_H

#include <set>
#include "MatrixCell.h"

template<typename T, T default_val>
struct MatrixRow{
    MatrixRow(unsigned int row_number) : row_number_(row_number){

    };

    MatrixCell<T, default_val>& operator[](unsigned int left_index){
        for(auto cell : cells_){
            if (cell.is_same_index(left_index)){
                return cell;
            }
        }
        MatrixCell<T, default_val> new_cell(left_index);
        cells_.insert(new_cell);
        return new_cell;
    };

    bool operator<(const MatrixRow<T, default_val> row) const{
      return row_number_<row.row_number_;
    };

    bool is_same_index(unsigned int index){
        return row_number_== index;
    };

private:
    unsigned int row_number_;
    std::set<MatrixCell<T, default_val>> cells_;
};

#endif //MATRIX_MATRIXROW_H

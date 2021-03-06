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
            if (cell->is_same_index(left_index)){
                return *cell;
            }
        }
        MatrixCell<T, default_val>* new_cell_ptr = new MatrixCell<T, default_val>(left_index);
        cells_.insert(new_cell_ptr);
        return *(new_cell_ptr);
    };

    bool operator<(const MatrixRow<T, default_val> row) const{
      return row_number_<row.row_number_;
    };

    bool is_same_index(unsigned int index){
        return row_number_== index;
    };

    int RowNumber(){
        return row_number_;
    };

    std::set<MatrixCell<T, default_val>*> Cells(){
        return cells_;
    };

    MatrixCell<T, default_val>*  get_first_cell_ptr(){
        if (cells_.size() > 0) {
            return (*cells_.begin());
        } else
            return nullptr;
    };

    MatrixCell<T, default_val>* get_last_cell_ptr(){
        if (cells_.size() > 0) {
            return (*cells_.end());
        } else
            return nullptr;
    };

    MatrixCell<T, default_val>* get_next_cell_ptr(MatrixCell<T, default_val>* prev_cell){
        if (prev_cell!= nullptr){
            return *(++(cells_.find(prev_cell)));
        }
        return nullptr;
    };

    MatrixCell<T, default_val>* get_next_cell_ptr(unsigned int prev_cell_number){
        for (auto cell_it = cells_.begin(); cell_it < cells_.end(); cell_it++) {
            if ((*cell_it)->is_same_index(prev_cell_number)){
                return *(cell_it++);
            }
        }
        return nullptr;
    };

private:
    unsigned int row_number_;
    std::set<MatrixCell<T, default_val>*> cells_;
};

#endif //MATRIX_MATRIXROW_H

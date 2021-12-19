#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <tuple>
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
        MatrixRow<T, default_val>* new_row_ptr = new MatrixRow<T, default_val>(right_index);
        rows_.insert(new_row_ptr);
        return *(new_row_ptr);
    } ;


        struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = std::tuple<int, int, T>;
        using pointer           = std::tuple<int, int, T>*;
        using reference         = std::tuple<int, int, T>&;


        Iterator(pointer ptr) : m_ptr_(ptr) {};


        pointer operator->() { return m_ptr_; }

        // Prefix increment
        Iterator& operator++() {
            //TODO
            m_ptr_ = ;
            return *this; }

   /*     // Postfix increment
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }*/

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

        reference operator*() const { return *m_ptr_; }

        private:
        pointer  m_ptr_;
        };


    Iterator begin() {
        auto it = rows_.begin();
        int row_number = (*it)->RowNumber();
        MatrixCell<T, default_val>* first_cell_ptr = (*it)->get_first_cell();
        return Iterator(&(std::make_tuple<int, int, T>(row_number, first_cell_ptr->Index(), first_cell_ptr->Value())));
    }

    Iterator end()   {
        auto it = rows_.end();
        int row_number = (*it)->RowNumber();
        MatrixCell<T, default_val>* end_cell_ptr = (*it)->get_last_cell();
        return Iterator(&(std::make_tuple<int, int, T>(row_number, end_cell_ptr->Index(), end_cell_ptr->Value())));
    }


private:
    // if we speak about infinite Matrix maybe long will be better???
    unsigned int real_size_;
    std::set<MatrixRow<T, default_val>*> rows_;
};

#endif //MATRIX_MATRIX_H

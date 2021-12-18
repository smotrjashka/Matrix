#ifndef MATRIX_MATRIXCELL_H
#define MATRIX_MATRIXCELL_H

template<typename T, T default_val>
struct MatrixCell{

    MatrixCell(unsigned int index) : position_in_row_(index), value_(default_val){

    };
    MatrixCell(unsigned int index, T value) : position_in_row_(index), value_(value){

    };

    bool is_same_index(unsigned int index){
        return position_in_row_ == index;
    };

    T& operator=(T value){
        value_ = value;
    };

    bool operator==(T value){
        return value==value_;
    }
protected:
    unsigned int position_in_row_;
    T value_;
};

#endif //MATRIX_MATRIXCELL_H

#ifndef MATRIX_MATRIXCELL_H
#define MATRIX_MATRIXCELL_H

template<typename T, T default_val>
struct MatrixCell{

    MatrixCell(unsigned int index) : position_in_row_(index), value_(default_val){

    };
    MatrixCell(unsigned int index, T value) : position_in_row_(index), value_(value){

    };

    MatrixCell(MatrixCell<T, default_val>& matrixCell){
        position_in_row_ = matrixCell.position_in_row_;
        value_ = matrixCell.value_;
    };

    MatrixCell(const MatrixCell<T, default_val>& matrixCell){
        position_in_row_ = matrixCell.position_in_row_;
        value_ = matrixCell.value_;
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

    bool operator<(const MatrixCell<T, default_val> cell) const {
        return position_in_row_<cell.position_in_row_;
    };

    T Value(){
        return value_;
    };

    unsigned int Index(){
        return position_in_row_;
    };

protected:
    unsigned int position_in_row_;
    T value_;
};

#endif //MATRIX_MATRIXCELL_H

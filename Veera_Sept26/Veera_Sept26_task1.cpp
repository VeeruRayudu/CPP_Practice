#include<iostream>
#include<iomanip>
#include<cstdlib>

class DoubleSubscriptedArray{
    private:
    int rows;
    int cols;
    int *ptr;

    public:
    // constructor
    DoubleSubscriptedArray(int rows=3, int cols=3)
        : rows(rows > 0 ? rows : 3), cols(cols > 0 ? cols : 3) {
        ptr = new int[rows * cols];
        for(int i = 0; i < rows * cols; i++){
            ptr[i] = 0;
        }
    }

    // copy constructor
    DoubleSubscriptedArray(const DoubleSubscriptedArray &other) : rows(other.rows), cols(other.cols){
        ptr = new int[rows * cols];
        for(int i = 0; i < rows * cols; i++){
            ptr[i] = other.ptr[i];
        }
    }

    // destructor
    ~DoubleSubscriptedArray(){
        delete[] ptr;
    }

    // assignment operator
    const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &right){
        if(&right != this){
            if (rows*cols != right.rows*right.cols){
                delete[] ptr;
                rows = right.rows;
                cols = right.cols;
                ptr = new int[rows*cols];
            }
            for(int i=0;i<rows*cols;i++){
                ptr[i] = right.ptr[i];
            }
        }
        return *this;
    }

    // equality operator
    bool operator==(const DoubleSubscriptedArray &right) const {
        if(rows != right.rows || cols != right.cols){
            return false;
        }
        for(int i = 0; i < rows * cols; i++){
            if (ptr[i] != right.ptr[i]){
                return false;
            }
        }
        return true;
    }

    // inequality operator
    bool operator!=(const DoubleSubscriptedArray &right) const {
        return !(*this == right);
    }

    // lvalue () operator
    int &operator()(int row, int col){
        if(row<0 || row>=rows || col<0 || col>=cols){
            std::cerr<<"Error: Index ("<<row<<","<<col<<") out of range.\n";
            exit(1);
        }
        return ptr[row*cols+col];
    }

    // rvalue () operator
    int operator()(int row, int col) const {
        if(row<0 || row>=rows || col<0 || col>=cols){
            std::cerr<<"Error: Index ("<<row<<","<<col<<") out of range.\n";
            exit(1);
        }
        return ptr[row*cols + col];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    int getSize() const { return rows * cols; }

    // input operator
    friend std::istream &operator>>(std::istream &input, DoubleSubscriptedArray &a) {
        for (int i=0;i<a.rows*a.cols;i++){
            input>>a.ptr[i];
        }
        return input;
    }

    // output operator
    friend std::ostream &operator<<(std::ostream &output, const DoubleSubscriptedArray &a){
        for (int r=0;r<a.rows;r++){
            for (int c=0 ;c < a.cols;c++){
                output<<std::setw(5)<<a.ptr[r*a.cols + c];
            }
            output<<std::endl;
        }
        return output;
    }
};

int main() {
    DoubleSubscriptedArray a(3, 5);

    std::cout<<"----Initial 3x5 array:\n"<<a<<std::endl;

    for(int i=0;i<a.getRows();i++){
        for(int j=0;j < a.getCols();j++){
            a(i, j) = (i+1)*10 + j;
        }
    }

    std::cout<<"After assigning values:\n"<<a<<std::endl;

    //copy and compare
    DoubleSubscriptedArray b = a;

    std::cout<<"Copied array b:\n"<<b<<std::endl;

    std::cout<<"a == b ? "<<(a==b ? "true" : "false")<<std::endl;

    b(1, 2) = 999;
    std::cout<<"Modified b:\n"<<b<<std::endl;

    std::cout<<"a != b ? "<<(a != b ? "true" : "false")<<std::endl;

    return 0;
}

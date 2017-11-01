#include <iostream>
#include <vector>

class Matrix{

public:
    Matrix(int x, int y){
        this->CorX = x;
        this->CorY = y;
    };

    void Init(){
        //make new Row
        std::vector<int> VecRow(this->CorY, 1);
        for(int i = 0; i < this->CorX; i++){
            //add Row in our Vector
            Vec2D.push_back(VecRow);
        }

    }

    Matrix Mult(Matrix M) {
        Matrix mat_res(this->CorX, M.CorY);
        mat_res.Init();
        if(this->CorY == M.CorX){
            for (int i = 0; i < this->CorX; i++) {          //over rows
                for (int j = 0; j < M.CorY; j++) {          //over columns
                    for(int k = 0; k < this->CorX; k++){    //over elements of one row
                        mat_res.Vec2D[i][j] += this->Vec2D[i][k] * M.Vec2D[k][j];
                    }
                }
            }
        }else{
            std::cerr << "Error! Matrix Columns and Rows aren't suitable \n";
            return mat_res;
        }
        return mat_res;
    }

    Matrix Add(Matrix M){
        Matrix mat_res(this->CorX, this->CorY);
        mat_res.Init();
        if(M.CorX == this->CorX && M.CorY == this->CorY){
            for(int i = 0; i < this->CorX; i++){
                for(int j = 0; j < this->CorY; j++){
                    mat_res.Vec2D[i][j] = this->Vec2D[i][j] + M.Vec2D[i][j];
                }
            }
        }

        return mat_res;
    }

private:
    int CorX = 0;
    int CorY = 0;
    //declare 2D vector
    std::vector< std::vector<int> > Vec2D;
};
int main() {

    int z_1 = 1000;
    int z_2 = 1000;

    time_t start, end;
    double elapsed;

    int terminate = 1;

    while(terminate){
        start = time(nullptr);

        Matrix mat(z_1, z_2);
        mat.Init();
        Matrix mat2(z_1, z_2);
        mat2.Init();

        mat.Add(mat);

        end = time(nullptr);

        elapsed = difftime(end, start);
        std::cout << elapsed << " " << z_1 << std::endl;

        if(elapsed > 60.0){ // 1 minute. Can be changed to 2, 5 or 10 minutes
            terminate = 0;
            std::cout << "Matrix should be on both Coordinates: " << z_1 - 1000 << std::endl;
        }else if(elapsed == 60.0) {
            terminate = 0;
            std::cout << "Matrix should be on both Coordinates: " << z_1 << std::endl;
        }else{
            z_1 += 1000;
            z_2 += 1000;
        }
    }

    std::cout << "Matrix should be on both Coordinates: " << --z_1 << std::endl;

    // Reset
    terminate = 1;

    z_1 = 100;
    z_2 = 100;

    while(terminate){
        start = time(nullptr);

        Matrix mat(z_1, z_2);
        mat.Init();
        Matrix mat2(z_1, z_2);
        mat2.Init();

        mat.Mult(mat);

        end = time(nullptr);

        elapsed = difftime(end, start);
        std::cout << elapsed << " " << z_1 << std::endl;

        if(elapsed > 60.0){ // 1 minute. Can be changed to 2, 5 or 10 minutes
            terminate = 0;
            std::cout << "Matrix should be on both Coordinates: " << z_1 - 100 << std::endl;
        }else if(elapsed == 60.0) {
            terminate = 0;
            std::cout << "Matrix should be on both Coordinates: " << z_1 << std::endl;
        }else{
            z_1 += 100;
            z_2 += 100;
        }
    }

    return 0;
}
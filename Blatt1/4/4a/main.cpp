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
        std::vector<int> VecRow(this->CorY, 0);
        for(int i = 0; i < this->CorX; i++){
            //add Row in our Vector
            Vec2D.push_back(VecRow);
        }

    }

    void Print(){
        for(int i = 0; i < this->CorX; i++){
            for(int j = 0; j < this->CorY; j++){
                std::cout << Vec2D[i][j] << " ";
            }
            std::cout << "\n";
        }
        //for a nice out put
        std::cout << "\n";
    }

    void Input(){
        for(int i = 0; i < this->CorX; i++){
            for(int j = 0; j < this->CorY; j++){
                //To give right Coordinates +1 to counters
                std::cout << "Point (" << i+1 << "," << j+1 << "): ";
                std::cin >> Vec2D[i][j];
            }
        }

    }

    Matrix Mult(Matrix M) {
        clock_t start = clock();
        int actions = 0;
        Matrix mat_res(this->CorX, M.CorY);
        mat_res.Init();

        if(this->CorY == M.CorX){
            ++actions;
            for (int i = 0; i < this->CorX; i++) {          //over rows
                ++actions;
                for (int j = 0; j < M.CorY; j++) {          //over columns
                    ++actions;
                    for(int k = 0; k < this->CorX; k++){    //over elements of one row
                        ++actions;
                        mat_res.Vec2D[i][j] += this->Vec2D[i][k] * M.Vec2D[k][j];
                        ++actions;
                    }
                }
            }
        }else{
            std::cerr << "Error! Matrix Columns and Rows aren't suitable \n";
            std::cout << "Amount of actions in Mult: " << actions << std::endl;

            clock_t stop = clock();
            double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
            std::cout << "Actions in Mult took: " << elapsed << " ms" << std::endl;

            return mat_res;
        }
        std::cout << "Amount of actions in Mult: " << actions << std::endl;

        clock_t stop = clock();
        double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Actions in Mult took: " << elapsed << " ms" << std::endl;

        return mat_res;
    }

    Matrix Add(Matrix M){
        clock_t start = clock();
        int actions = 0;
        Matrix mat_res(this->CorX, this->CorY);
        mat_res.Init();
        if(M.CorX == this->CorX && M.CorY == this->CorY){
            ++actions;
            for(int i = 0; i < this->CorX; i++){
                ++actions;
                for(int j = 0; j < this->CorY; j++){
                    ++actions;
                    mat_res.Vec2D[i][j] = this->Vec2D[i][j] + M.Vec2D[i][j];
                    ++actions;
                }
            }
        }else{
            std::cerr << "Error! Matrix Columns and Rows aren't suitable \n";
            std::cout << "Amount of actions in Add: " << actions << std::endl;

            clock_t stop = clock();
            double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
            std::cout << "Actions in Add took: " << elapsed << " ms" << std::endl;

            return mat_res;
        }
        std::cout << "Amount of actions in Add: " << actions << std::endl;

        clock_t stop = clock();
        double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
        std::cout << "Actions in Add took: " << elapsed << " ms" << std::endl;

        return mat_res;
    }

private:
    int CorX = 0;
    int CorY = 0;
    //declare 2D vector
    std::vector< std::vector<int> > Vec2D;
};
int main() {
    int z_1 = 0;
    int z_2 = 0;

    std::cout << "Coordinate X" << std::endl;
    std::cin >> z_1;

    std::cout << "Coordinate Y" << std::endl;
    std::cin >> z_2;

    Matrix mat(z_1, z_2);

    mat.Init();
    mat.Input();
    mat.Print();

    std::cout << "Coordinate X" << std::endl;
    std::cin >> z_1;

    std::cout << "Coordinate Y" << std::endl;
    std::cin >> z_2;

    Matrix mat2(z_1, z_2);

    mat2.Init();
    mat2.Input();
    mat2.Print();

    //save result matrix in a Matrix obj
    Matrix mat3 = mat.Add(mat2);
    mat3.Print();

    Matrix mat4 = mat.Mult(mat2);
    mat4.Print();

    return 0;
}
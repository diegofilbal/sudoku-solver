#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9

typedef short board_t[SIZE][SIZE];

void read_input( board_t b )
{
    for(short j{0}; j < SIZE; j++)
    {
        for (short k{0}; k < SIZE; k++)
        {
            std::cin >> board[j][k];
        }
    }
}

void print( short b[SIZE][SIZE] ) // Prints the whole given matrix to the user
{
    std::cout << "\n";

    for(int i{0}; i < SIZE; i++)
    {
        if(i == 3 || i == 6) std::cout << "_____________________\n\n";

        for(int j{0}; j < SIZE; j++)
        {
            if(j == 3 || j == 6) std::cout << "  ";
            std::cout << b[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool verify_row( int i, short b[SIZE][SIZE] ) // Verifies if each number appears only once in the line
{
    short cont[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; // Counting vector, the index indicates de value in the matrix line

    for(int j{0}; j < SIZE; j++){
        if(b[i][j] >= 1 && b[i][j] <= 9) // Verifies if the number is in range
            cont[ (b[i][j] - 1) ]++; // Increments in the counting vector
        else
            return 0;
    }

    return ( cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8] );
    // Makes a logic operation with the values of the vector, it will return 1 (true) if every single one is placed with number 1, and 0 (false) if any of them is different than 1.
}

bool verify_column( int i, short b[SIZE][SIZE] ) // Verifies if each number appears only once in the column
{
    short cont[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; // Counting vector, the index indicates de value in the matrix column

    for(int j{0}; j < SIZE; j++){
        if(b[j][i] >= 1 && b[j][i] <= 9) // Verifies if the number is in range
            cont[ (b[j][i] - 1) ]++; // Increments in the counting vector
        else
            return 0;
    }

    return ( cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8] );
    // Makes a logic operation with the values of the vector, it will return 1 (true) if every single one is placed with number 1, and 0 (false) if any of them is different than 1.
}

bool verify_quadrant(short i, short j, short b[SIZE][SIZE])
{
    short cont[9] {0, 0, 0, 0, 0, 0, 0, 0, 0}; // Counting vector, the index indicates de value in the matrix quadrant

    for(int k{i}; k < i + 3; k++) 
    {
        for(int l{j}; l < j + 3; l++)
        {
            if(b[k][l] >= 1 && b[k][l] <= 9) // Verifies if the number is in proper range
                cont[ (b[k][l] - 1) ]++; // Increments in the counting vector
            else
                return 0;
        }
    }

    return ( cont[0] && cont[1] && cont[2] && cont[3] && cont[4] && cont[5] && cont[6] && cont[7] && cont[8] );
    // Makes a logic operation with the values of the vector, it will return 1 (true) if every single one is placed with number 1, and 0 (false) if any of them is different than 1.
}

bool is_valid( short b[SIZE][SIZE] )
{
    // TODO: implement this function.

    bool vl_result, vc_result, vq_result;

    for(int i{0}; i < SIZE; i++) // Passes each matrix's line/column to the due function
    {
        vl_result = verify_row(i, b);
        vc_result = verify_column(i, b);
    }

    for(int i{0}; i < SIZE; i += 3) // Passes every index of matrix's quadrant first element to the function
    {
        for(int j{0}; j < SIZE; j += 3)
        vq_result = verify_quadrant(i, j, b);
    }

    return ( vl_result && vc_result && vq_result ); // Returns 1 (true) if all results are 1, 0 if any of them is not 1;
}


int main(void)
{
    board_t board;

    short i{0}; // Iterator for board counting
    short data;

    while(std::cin) // It keeps running while there is still data in the input
    {
        read_input(board);

        std::cout << "\nBoard #" << (i+1) << ": \n";
        print( board );
        std::cout << "\n>> Is valid? " << std::boolalpha << is_valid( board ) << std::endl;
        std::cout << "\n";

        i++;
    }

    return 0;
}
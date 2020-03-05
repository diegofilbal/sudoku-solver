#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9

void print( short b[SIZE][SIZE] ) // Prints the whole given matrix to the user
{
    std::cout << "\n";

    for(int i{0}; i < SIZE; i++)
    {
        if(i == 3 || i == 6) std::cout << "_____________________\n\n";
        // if(i == 3 || i == 6) std::cout << "\n------|-------|-------\n\n";

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

/*
    short boards[8][SIZE][SIZE]=
    {

        {
            { 1, 3, 4, 6, 7, 8, 5, 9, 2 },
            { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
            { 5, 9, 8, 3, 4, 2, 1, 6, 7 },
            { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
            { 4, 2, 6, 8, 5, 3, 9, 7, 1 },
            { 7, 1, 3, 4, 2, 9, 8, 5, 6 },
            { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
            { 2, 8, 7, 9, 1, 4, 6, 3, 5 },
            { 3, 4, 5, 2, 8, 6, 7, 1, 9 },
        },

        {
            { 1, 6, 2, 8, 5, 7, 4, 9, 3 },
            { 5, 3, 4, 1, 2, 9, 6, 7, 8 },
            { 7, 8, 9, 6, 4, 3, 5, 2, 1 },
            { 4, 7, 5, 3, 1, 2, 9, 8, 6 },
            { 9, 1, 3, 5, 8, 6, 7, 4, 2 },
            { 6, 2, 8, 7, 9, 4, 1, 3, 5 },
            { 3, 5, 6, 4, 7, 8, 2, 1, 9 },
            { 2, 4, 1, 9, 3, 5, 8, 6, 7 },
            { 8, 9, 7, 2, 6, 1, 3, 5, 4 },
        },

        {
            { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
            { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
            { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
            { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
            { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
            { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
            { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
            { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
            { 3, 4, 5, 2, 8, 6, 1, 7, 9 },
        },

        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 },
        },

        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 5, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 3, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 },
        },

        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 19, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, -3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 },
        },

        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 0, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 },
        },

        {
            { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
            { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
            { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
            { 8, 9, 7, 3, 1, 5, 4, 2, 3 },
            { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
            { 5, 4, 6, 7, 8, 6, 9, 1, 2 },
            { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
            { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
            { 3, 5, 2, 8, 6, 4, 1, 7, 9 },
        }
    
    };
*/

/*
    std::cout << "Board: \n";
    print( board1 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board1 ) << std::endl;
    std::cout << "\n";

    std::cout << "Board: \n";
    print( board2 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board2 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board3 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board3 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board4 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board4 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board5 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board5 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board6 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board6 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board7 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board7 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board8 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board8 ) << std::endl;
    std::cout << "\n";
*/

    // TODO: Make the code below work, instead of the ugly code above.
/*
    int n_boards{8}; // Number of boards...
    for ( int i{0}; i < n_boards ; ++i )
    {
        std::cout << "\nBoard #" << (i+1) << ": \n";
        print( boards[i] );
        std::cout << "\n>> Is valid? " << std::boolalpha << is_valid( boards[i] ) << std::endl;
        std::cout << "\n";
    }
*/

    short board[SIZE][SIZE];
    short i{0}; // Iterator for board counting

    while(std::cin) // It keeps running while there is still data in the file
    {
        for(short j{0}; j < SIZE; j++)
        {
            for (short k{0}; k < SIZE; k++)
            {
                std::cin >> board[j][k];
            }
        }

        std::cout << "\nBoard #" << (i+1) << ": \n";
        print( board );
        std::cout << "\n>> Is valid? " << std::boolalpha << is_valid( board ) << std::endl;
        std::cout << "\n";

        i++;
    }

    return 0;
}

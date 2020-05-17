#pragma once

namespace UserTable
{
    class Table
    {
    private:
        int width = 0;
        int height = 0;
        int **data;

    public:
        Table(int rows, int cols); ///< Constructor
        ~Table(); ///< Destructor
        void display();
        void setValue(int xPos, int yPos, int newValue);
        void resize(int new_width, int new_height);
    };
    
} // namespace UserTable

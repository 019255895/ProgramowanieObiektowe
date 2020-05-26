#pragma once

namespace UserTable
{
    class Table
    {
    private:
        int rows;
        int cols;
        int **data;
        const char * filePath;

    public:
        Table(const char * path); ///< Constructor
        ~Table(); ///< Destructor
        void display();
        void setValue(int xPos, int yPos, int newValue);
        void resize(int new_width, int new_height);
    };
    
} // namespace UserTable
